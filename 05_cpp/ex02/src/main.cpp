/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:42:49 by locharve          #+#    #+#             */
/*   Updated: 2024/12/02 16:10:04 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int	main() {
	Bureaucrat	john("John", 3);
	Bureaucrat	henry("Henry", 149);

	ShrubberyCreationForm	f1("me");

	john.executeForm(f1);
	henry.executeForm(f1);

	john.signForm(f1);
	john.executeForm(f1);
	henry.executeForm(f1);
}