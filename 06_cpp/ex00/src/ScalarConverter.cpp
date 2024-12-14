/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:17:00 by locharve          #+#    #+#             */
/*   Updated: 2024/12/14 15:52:02 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& src) {
	(void)src;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& src) {
	(void)src;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

static void	handleSpecial(std::string str) {
	double	d = atof(str.c_str());
	float	f = static_cast<float>(d);
	std::cout << "char:\timpossible" << std::endl
		<< "int:\timpossible" << std::endl
		<< "float:\t";
		if (str[0] == '+')
			std::cout << '+';
		std::cout << f << 'f' << std::endl
		<< "double:\t";
		if (str[0] == '+')
			std::cout << '+';
		std::cout << d << std::endl;
}

static bool	isConvertible(std::string str) {
	std::string::iterator	it = str.begin();
	std::string::iterator	end = str.end();
	while (it != end && std::isdigit(*it))
		it++;
	if (it == end)
		return (true);
	if (*it != '.')
		return (false);
	it++;
	if (!std::isdigit(*it))
		return (false);
	while (it != end && std::isdigit(*it))
		it++;
	return (it == end || *it == 'f');
}

void	ScalarConverter::convert(std::string str) {
	if (str == "nan" || str == "nanf" || str == "-inf"
		|| str == "-inff" || str == "+inf" || str == "+inff")
		handleSpecial(str);
	else if (!isConvertible(str))
		std::cout << "impossible: " << str << std::endl;
//		handleImpossible();
	else {
		double	d = atof(str.c_str());
		float	f = static_cast<float>(d);
		int		i = static_cast<int>(d);
		if (i >= 33 && i <= 126) {
			char	c = static_cast<char>(d);
			std::cout << "char:\t'" << c << "'" << std::endl;
		} else {
			std::cout << "char:\t" << "Non displayable" << std::endl;
		}
		std::cout << "int:\t" << i << std::endl
			<< "float:\t" << f;
		if (f == static_cast<int>(i))
			std::cout << ".0";
		std::cout << 'f' << std::endl
			<< "double:\t" << d;
		if (d == static_cast<int>(i))
			std::cout << ".0";
		std::cout << std::endl;
	}
}