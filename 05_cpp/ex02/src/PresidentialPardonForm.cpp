/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:16:55 by locharve          #+#    #+#             */
/*   Updated: 2024/12/03 15:24:33 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():
	AForm("PresidentialPardonForm", 0, 72, 45), _target("me") {
		std::cout << "+++++++ PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target):
	AForm("PresidentialPardonForm", 0, 72, 45), _target(target) {
		std::cout << "+++++++ PresidentialPardonForm string constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src):
	AForm(src.getName(), src.getSigned(), src.getGradeToSign(), src.getGradeToExec()),
	_target(src.getTarget()) {
		std::cout << "+++++++ PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& src) {
	setSigned(src.getSigned());
	_target = src.getTarget();
	return (*this);
}

std::string	PresidentialPardonForm::getTarget() const {
	return (_target);
}

void	PresidentialPardonForm::doExecute() const {
	std::cout << "Our great leader Zaphod Beeblebrox pardons "
		<< getTarget() << ", what a great president" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "------- PresidentialPardonForm destructor called" << std::endl;
}