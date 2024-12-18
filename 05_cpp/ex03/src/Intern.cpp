/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:12:43 by locharve          #+#    #+#             */
/*   Updated: 2024/12/18 14:16:59 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {
	std::cout << "+++++++ Intern constructor called" << std::endl;
}

Intern::Intern(const Intern& src) {
	*this = src;
	std::cout << "+++++++ Intern copy contructor called" << std::endl;
}

Intern&	Intern::operator=(const Intern& src) {
	(void)src;
	std::cout << "Intern operator= called, but has no effect due to lack of Intern attributes" << std::endl;
	return (*this);
}

Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
}

static void	AFormTabInit(AForm* (&tab)[3], std::string target) {
	int	i = 0;
	tab[i] = new ShrubberyCreationForm(target);
	if (tab[i]) {
		i++;
		tab[i] = new RobotomyRequestForm(target);
		if (tab[i]) {
			i++;
			tab[i] = new PresidentialPardonForm(target);
		}
	}
	if (!tab[i]) {
		for (int j = 0; j < i; j++)
			delete(tab[j]);
	}
} 

AForm*	Intern::makeForm(std::string formName, std::string target) {
	AForm*	tab[3];
	AFormTabInit(tab, target);
	if (!tab[0]) {
		std::cerr << "Allocation error in Intern::makeForm()" << std::endl;
		return (NULL);
	}
	try {
		int	i = 0, j;
		while (i < 3 && tab[i]->getName() != formName)
			i++;
		if (i == 3) {
			for (i = 0; i < 3; i++)
				delete tab[i];
			throw (FormDoesntExist());
		}
		for (j = 0; j < 3; j++) {
			if (j != i)
				delete tab[j];
		}
		std::cout << "Intern creates " << *tab[i] << std::endl;
		return (tab[i]);
	} catch (FormDoesntExist& e) {
		std::cerr << "Intern cannot make " << formName << ": " << e.what() << std::endl;
		return (NULL);
	}
}

const char*	Intern::FormDoesntExist::what() const throw() {
	return ("this form type doesn't exist");
}