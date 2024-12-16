/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:17:00 by locharve          #+#    #+#             */
/*   Updated: 2024/12/16 15:34:43 by locharve         ###   ########.fr       */
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

	if (*it == '-')
		it++;
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
		std::cout << "Conversion is impossible: " << str << std::endl;
	else {
		std::stringstream	stream;
		long double	d = atof(str.c_str());
		long long	l = static_cast<long>(d);

		/* CHAR */
		std::cout << "char:\t";
		if (l >= 33 && l <= 126)
			std::cout << static_cast<char>(l) << std::endl;
		else if (l < std::numeric_limits<char>::min() || l > std::numeric_limits<char>::max())
			std::cout << "char overflow" << std::endl;
		else
			std::cout << "non displayable" << std::endl;

		/* INT */
		std::cout << "int:\t";
		if (l >= std::numeric_limits<int>::min() && l <= std::numeric_limits<int>::max())
			std::cout << static_cast<int>(l) << std::endl;
		else
			std::cout << "int overflow" << std::endl;

		/* FLOAT */
		std::cout << "float:\t";
		if (d >= -std::numeric_limits<float>::max() && d <= std::numeric_limits<float>::max()) {
			stream << static_cast<float>(d);
			if (stream.str().find('.') == std::string::npos)
				stream << ".0";
			std::cout << stream.str() << 'f' << std::endl;
			stream.str(std::string());
		}
		else
			std::cout << "float overflow" << std::endl;

		/* DOUBLE */
		std::cout << "double:\t";
		if (d >= -std::numeric_limits<double>::max() && d <= std::numeric_limits<double>::max()) {
			stream << static_cast<double>(d);
			if (stream.str().find('.') == std::string::npos)
				stream << ".0";
			std::cout << stream.str() << std::endl;
			stream.str(std::string());
		}
		else
			std::cout << "double overflow" << std::endl;
	}
}