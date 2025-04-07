/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:17:00 by locharve          #+#    #+#             */
/*   Updated: 2025/04/03 15:25:56 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& src) {
	*this = src;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& src) {
	(void)src;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

void	ScalarConverter::convert(std::string str) {
	if (detectPseudoLitteral(str))
		convertPseudoLitteral(str);
	else if (detectChar(str))
		convertChar(str);
	else if (detectInt(str))
		convertInt(str);
	else if (detectFloat(str))
		convertFloat(str);
	else if (detectDouble(str))
		convertDouble(str);
	else
		handleNotConvertible(str);
}