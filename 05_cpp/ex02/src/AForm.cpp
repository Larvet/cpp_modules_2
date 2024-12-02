/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:15:23 by locharve          #+#    #+#             */
/*   Updated: 2024/12/02 16:09:57 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

AForm::AForm(): _name("RightToBreatheForm"), _signed(0), _gradeToSign(1), _gradeToExec(1) {
	std::cout << "+++++++ AForm default constructor called: "
		<< std::endl << *this << std::endl;
}

AForm::AForm(std::string name, bool s, unsigned int gradeS, unsigned int gradeE): _name(name),
	_signed(s), _gradeToSign(testGrade(gradeS)), _gradeToExec(testGrade(gradeE)) {
		std::cout << "+++++++ AForm complete constructor called: "
			<< std::endl << *this << std::endl;
}

AForm::AForm(const AForm& src): _name(src.getName()), _signed(src.getSigned()),
	_gradeToSign(src.testGrade(getGradeToSign())), _gradeToExec(src.testGrade(getGradeToExec())) {
		std::cout << "+++++++ AForm copy constructor called: "
			<< std::endl << *this << std::endl;
}

AForm&	AForm::operator=(const AForm& src) {
	this->_signed = src.getSigned();
	return (*this);
}

unsigned int	AForm::testGrade(unsigned int g) const {
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

void	AForm::setSigned(unsigned int s) {
	_signed = s;
}

const std::string	AForm::getName() const {
	return (_name);
}

bool	AForm::getSigned() const {
	return (_signed);
}

unsigned int	AForm::getGradeToSign() const {
	return (_gradeToSign);
}

unsigned int	AForm::getGradeToExec() const {
	return (_gradeToExec);
}

void	AForm::beSigned(Bureaucrat& b) {
	if (b.getGrade() > getGradeToSign())
		throw (GradeTooLowException());
	else if (getSigned())
		throw (AlreadySignedException());
	else
		_signed = 1;
}

void	AForm::execute(Bureaucrat const & executor) const {
	if (!getSigned())
		throw (NotSignedException());
	if (executor.getGrade() > getGradeToExec())
		throw (GradeTooLowException());
	doExecute();
}

AForm::~AForm() {
	std::cout << "------- AForm destructor called" << std::endl;
}

void	AForm::GradeTooHighException::constructException(const AForm& f) {
	std::cerr << "AForm " << f.getName()
		<< " constructor: grade too high. It has been reset to 1."
		<< std::endl;
}

void	AForm::GradeTooLowException::constructException(const AForm& f) {
	std::cerr << "AForm " << f.getName()
		<< " constructor: grade too low. It has been reset to 150." << std::endl;
}

void	AForm::GradeTooLowException::signException(Bureaucrat& b, AForm& f) {
	std::cerr << b << " couldn't sign " << f
		<< " because they don't have the required grade" << std::endl; 
}

void	AForm::GradeTooLowException::executeException(Bureaucrat const & b, AForm const & f) {
	std::cerr << b << " couldn't execute " << f
		<< " because their grade is too low" << std::endl;
}

void	AForm::AlreadySignedException::printException(Bureaucrat& b, AForm& f) {
	std::cerr << b << " couldn't sign " << f
		<< " because it is already signed" << std::endl;
}

void	AForm::NotSignedException::printException(Bureaucrat const & b, AForm const & f) {
	std::cerr << b << " couldn't execute " << f
		<< " because it is not signed" << std::endl;
}

std::ostream&	operator<<(std::ostream& os, const AForm& f) {
	os	<< "[ AForm " << f.getName()
		<< (f.getSigned() ? " | signed | " : " | not signed | ")
		<< " grade to sign: " << f.getGradeToSign()
		<< " | grade to execute: " << f.getGradeToExec() << " ]"
		<< std::endl;
	return (os);
}