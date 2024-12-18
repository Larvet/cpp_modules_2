/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:16:43 by locharve          #+#    #+#             */
/*   Updated: 2024/12/18 14:07:06 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():
	AForm("RobotomyRequestForm", 0, 72, 45), _target("me") {
		std::cout << "+++++++ RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target):
	AForm("RobotomyRequestForm", 0, 72, 45), _target(target) {
		std::cout << "+++++++ RobotomyRequestForm string constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src):
	AForm(src.getName(), src.getSigned(), src.getGradeToSign(), src.getGradeToExec()),
	_target(src.getTarget()) {
		std::cout << "+++++++ RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& src) {
	setSigned(src.getSigned());
	_target = src.getTarget();
	return (*this);
}

std::string	RobotomyRequestForm::getTarget() const {
	return (_target);
}

void	RobotomyRequestForm::doExecute() const {
	std::srand(std::time(NULL));
	std::cout << "Robotomy goes brrrr..." << std::endl;
	if (std::rand() % 2)
		std::cout << getTarget() << " has been robotomized !" << std::endl;
	else
		std::cout << "Oh no... Robotomy has failed..." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "------- RobotomyRequestForm destructor called" << std::endl;
}