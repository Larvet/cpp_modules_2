/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:15:23 by locharve          #+#    #+#             */
/*   Updated: 2024/11/15 11:12:25 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("RightToBreatheForm"), _signed(0), _gradeToSign(1), _gradeToExec(1) {
	std::cout << "+++++++ Form default constructor called: "
		<< *this << std::endl;
}

Form::Form(const Form& src): _name(src.getName()), _gradeToSign(src.testGrade(getGradeToSign())),
	_gradeToExec(src.testGrade(getGradeToExec())) {
		*this = src;
		std::cout << "+++++++ Form copy constructor called: "
			<< *this << std::endl;
}

Form&	Form::operator=(const Form& src) {
	_signed = src.getSigned();
	return (*this);
}

unsigned int	Form::testGrade(unsigned int g) {
	try {
		if (g < 1)
			throw (GradeTooHighException());
		else if (g > 150)
			throw (GradeTooLowException());
	} catch (GradeTooHighException& e) {
		e.constructException(*this);
		return (1);
	} catch (GradeTooLowException& e) {
		e.constructException(*this);
		return (150);
	}
	return (g);
}

const std::string	Form::getName() const {
	return (_name);
}

bool	getSigned() const {
	return (_signed);
}

const unsigned int	Form::getGradeToSign() const {
	return (_gradeToSign);
}

const unsigned int	Form::getGradeToExec() const {
	return (_gradeToExec);
}

void	beSigned(Bureaucrat& b) {
	if (b.getGrade() > getGradeToSign())
		throw (GradeTooLowException());
	else
		_signed = 1;
}

Form::~Form() {
	std::cout << "------- Form destructor called" << std::endl;
}

Form::GradeTooHighException::constructException(Form& f) {
	std::cerr << "Form " << f.getName()
		<< " constructor: grade too high. It has been reset to 1."
		<< std::endl;
}

Form::GradeTooLowException::constructException(Form& f) {
	std::cerr << "Form " << f.getName()
		<< " constructor: grade too low. It has been reset to 150." << std::endl;
}

Form::GradeTooLowException::signException(Bureaucrat& b, Form& f) {
	std::cerr << b << " couldn't sign " << f
		<< " because they don't have the required grade" << std::endl; 
}

std::ostream&	operator<<(std::ostream& os, const Form& f) {
	os	<< "Form " << f.getName()
		<< (f.getSigned() ? " | signed | " : " | not signed | ")
		<< " grade to sign: " << f.getGradeToSign()
		<< " | grade to execute: " << f.getGradeToExec()
		<< std::endl;
	return (os);
}