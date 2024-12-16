/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:52:32 by locharve          #+#    #+#             */
/*   Updated: 2024/12/16 15:38:02 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char** argv) {
	if (argc == 2)
		ScalarConverter::convert(argv[1]);
	else
		std::cerr << "This program needs one argument" << std::endl;
	return (0);
} 