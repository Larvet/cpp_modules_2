/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:00:16 by locharve          #+#    #+#             */
/*   Updated: 2024/11/15 10:00:20 by locharve         ###   ########.fr       */
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

	return (0);
}