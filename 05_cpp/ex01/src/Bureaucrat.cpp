/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:00:22 by locharve          #+#    #+#             */
/*   Updated: 2024/11/15 11:12:33 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("John"), _grade(150) {
	std::cout << "+++++++ Bureaucrat default constructor called: " << *this << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade): _name(name) {
	try {
		if (grade < 1)
			throw (GradeTooHighException());
		else if (grade > 150)
			throw (GradeTooLowException());
		_grade = grade;
	} catch (GradeTooHighException& e) {
		e.constructException(name);
		_grade = 1;
	} catch (GradeTooLowException& e) {
		e.constructException(name);
		_grade = 150;
	}
	std::cout << "+++++++ Bureaucrat attributes constructor called: " << *this << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src): _name(src.getName()) {
	*this = src;
	std::cout << "+++++++ Bureaucrat copy constructor called: " << *this << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& src) {
	_grade = src.getGrade();
	return (*this);
}

const std::string	Bureaucrat::getName() const {
	return (_name);
}

unsigned int	Bureaucrat::getGrade() const {
	return (_grade);
}

void	Bureaucrat::incrementGrade() {
	try {
		if (_grade <= 1)
			throw (GradeTooHighException());
		_grade--;
	} catch (GradeTooHighException& e) {
		e.incrementException(getName());
	}
}

void	Bureaucrat::decrementGrade() {
	try {
		if (_grade >= 150)
			throw (GradeTooLowException());
		_grade++;
	} catch (GradeTooLowException& e) {
		e.decrementException(getName());
	}
}

void	Bureaucrat::signForm(Form& f) {
	try {
		f.beSigned(*this);
		std::cout << *this << " signed " << f << std::endl;
	} catch (Form::GradeTooLowException& e) {
		e.signException(*this, f);
	}
}

Bureaucrat::~Bureaucrat() {
	std::cout << "------- Bureaucrat destructor called: " << *this << std::endl;
}

void	Bureaucrat::GradeTooHighException::constructException(std::string name) {
	std::cerr << "Bureaucrat attributes constructor: " << name
		<< "'s grade is too high: it has been reset to 1" << std::endl;
}

void	Bureaucrat::GradeTooHighException::incrementException(const std::string name) {
	std::cerr << "Cannot increment " << name
			<< "'s grade: it is already set to 1." << std::endl;
}

void	Bureaucrat::GradeTooLowException::constructException(std::string name) {
	std::cerr << "Bureaucrat attributes constructor: " << name
		<< "'s grade is too low: it has been reset to 150" << std::endl;
}

void	Bureaucrat::GradeTooLowException::decrementException(const std::string name) {
	std::cerr << "Cannot decrement " << name
			<< "'s grade: it is already set to 150." << std::endl;
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (os);
}