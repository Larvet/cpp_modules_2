/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:00:22 by locharve          #+#    #+#             */
/*   Updated: 2024/12/09 16:29:02 by locharve         ###   ########.fr       */
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
		std::cerr << getName() << e.what() << " ; their grade has been reset to 1" << std::endl;
		_grade = 1;
	} catch (GradeTooLowException& e) {
		std::cerr << getName() << e.what() << " ; their grade has been reset to 150" << std::endl;
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
		std::cerr << "Cannot increment: " << getName() << e.what() << std::endl;
	}
}

void	Bureaucrat::decrementGrade() {
	try {
		if (_grade >= 150)
			throw (GradeTooLowException());
		_grade++;
	} catch (GradeTooLowException& e) {
		std::cerr << "Cannot decrement: " << getName() << e.what() << std::endl;
	}
}

Bureaucrat::~Bureaucrat() {
	std::cout << "------- Bureaucrat destructor called: " << *this << std::endl;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return ("'s grade is too high");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return ("'s grade is too low");
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (os);
}