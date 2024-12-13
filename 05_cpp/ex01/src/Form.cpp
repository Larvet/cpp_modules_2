/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:15:23 by locharve          #+#    #+#             */
/*   Updated: 2024/12/09 16:29:01 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Form::Form(): _name("RightToBreatheForm"), _signed(0), _gradeToSign(1), _gradeToExec(1) {
	std::cout << "+++++++ Form default constructor called: "
		<< std::endl << *this << std::endl;
}

Form::Form(std::string name, bool s, unsigned int gradeS, unsigned int gradeE): _name(name),
	_signed(s), _gradeToSign(testGrade(gradeS)), _gradeToExec(testGrade(gradeE)) {
		std::cout << "+++++++ Form complete constructor called: "
			<< std::endl << *this << std::endl;
}

Form::Form(const Form& src): _name(src.getName()), _signed(src.getSigned()),
	_gradeToSign(src.testGrade(getGradeToSign())), _gradeToExec(src.testGrade(getGradeToExec())) {
		std::cout << "+++++++ Form copy constructor called: "
			<< std::endl << *this << std::endl;
}

Form&	Form::operator=(const Form& src) {
	this->_signed = src.getSigned();
	return (*this);
}

unsigned int	Form::testGrade(unsigned int g) const {
	try {
		if (g < 1)
			throw (ConstructGradeTooHighException());
		else if (g > 150)
			throw (ConstructGradeTooLowException());
	} catch (ConstructGradeTooHighException& e) {
		std::cerr << *this << e.what() << std::endl;
		return (1);
	} catch (ConstructGradeTooLowException& e) {
		std::cerr << *this << e.what() << std::endl;
		return (150);
	}
	return (g);
}

const std::string	Form::getName() const {
	return (_name);
}

bool	Form::getSigned() const {
	return (_signed);
}

unsigned int	Form::getGradeToSign() const {
	return (_gradeToSign);
}

unsigned int	Form::getGradeToExec() const {
	return (_gradeToExec);
}

void	Form::beSigned(Bureaucrat& b) {
	if (b.getGrade() > getGradeToSign())
		throw (GradeTooLowException());
	else if (getSigned())
		throw (AlreadySignedException());
	else
		_signed = 1;
}

Form::~Form() {
	std::cout << "------- Form destructor called" << std::endl;
}

const char*	Form::ConstructGradeTooHighException::what() const throw() {
	return (" constructor: grade too high. It has been reset to 1.");
}

const char*	Form::ConstructGradeTooLowException::what() const throw() {
	return (" constructor: grade too low. It has been reset to 150.");
}

const char*	Form::GradeTooLowException::what() const throw() {
	return (" they don't have the required grade"); 
}

const char*	Form::AlreadySignedException::what() const throw() {
	return (" it is already signed");
}

std::ostream&	operator<<(std::ostream& os, const Form& f) {
	os	<< "[ Form " << f.getName()
		<< (f.getSigned() ? " | signed | " : " | not signed | ")
		<< " grade to sign: " << f.getGradeToSign()
		<< " | grade to execute: " << f.getGradeToExec() << " ]";
	return (os);
}