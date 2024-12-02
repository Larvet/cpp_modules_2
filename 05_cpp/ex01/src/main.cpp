/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:00:16 by locharve          #+#    #+#             */
/*   Updated: 2024/12/02 14:01:04 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main() {
	Bureaucrat	john;
	std::cout << john << std::endl;
	john.decrementGrade();
	john.incrementGrade();

	Bureaucrat	john_copy(john);
	std::cout << john_copy << std::endl;

	Bureaucrat	bobby("Bobby", 0);
	std::cout << bobby << std::endl;
	bobby.incrementGrade();
	bobby.decrementGrade();

	Form	f1;
//	std::cout << f1 << std::endl;

	Form	f2("F2", 0, 42, 57);
	john.signForm(f2);
	bobby.signForm(f2);

	Form	f3("F3", 0, 0, 0);
	john_copy.signForm(f3);

	Form	f4("F4", 1, 98, 67);
	john.signForm(f4);
	bobby.signForm(f4);

	return (0);
}