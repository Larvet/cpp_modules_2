/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:42:49 by locharve          #+#    #+#             */
/*   Updated: 2024/12/13 16:06:04 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main() {
	Bureaucrat	john("John", 3);
	Bureaucrat	henry("Henry", 149);

	ShrubberyCreationForm	f1("me");

	john.executeForm(f1);
	henry.executeForm(f1);

	john.signForm(f1);
	john.executeForm(f1);
	henry.executeForm(f1);

	RobotomyRequestForm	r1("you");

	john.executeForm(r1);
	henry.executeForm(r1);

	john.signForm(r1);
	john.executeForm(r1);
	henry.executeForm(r1);

	PresidentialPardonForm	p1("someone");

	john.executeForm(p1);
	henry.executeForm(p1);

	john.signForm(p1);
	john.executeForm(p1);
	henry.executeForm(p1);

	std::cout << std::endl << "////////////////////////////" << std::endl << std::endl;

	AForm*	tab[3] = {new ShrubberyCreationForm(), new RobotomyRequestForm(), new PresidentialPardonForm()};
	for (int i = 0; i < 3; i++) {
		std::cout << tab[i]->getName() << std::endl;
		delete tab[i];
	}

	std::cout << std::endl << "////////////////////////////" << std::endl << std::endl;

	Intern	intern;
	AForm*	form = intern.makeForm("ShrubberyCreationForm", "Jean-Jacques");
	if (form) {
		std::cout << *form << std::endl;
		delete form;
	}
}