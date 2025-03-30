/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:17:00 by locharve          #+#    #+#             */
/*   Updated: 2024/12/18 14:24:19 by locharve         ###   ########.fr       */
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

static bool	isSpecial(const std::string& str) {
	return (str == "nan" || str == "nanf" || str == "-inf"
		|| str == "-inff" || str == "+inf" || str == "+inff");
}

static bool	isChar(const std::string& str) {
	return (str.size() == 1 && isprint(str[0]));
}

static bool	isInt(const std::string& str) {
	size_t	sign = (str[0] == '-' || str[0] == '+');
	return (str.find_first_not_of("0123456789", sign) == std::string::npos);
}

static bool	isFloat(const std::string& str) {
	size_t	sign = (str[0] == '-' || str[0] == '+'),
			pos = str.find_first_not_of("0123456789", sign);

	if (pos != std::string::npos && str[pos] == '.') {
		pos = str.find_first_not_of("0123456789", ++pos);

		return (pos != std::string::npos && str[pos] == 'f' && pos == str.size() - 1);
	}
	return (false);
}

static bool	isDouble(const std::string& str) {
	size_t	sign = (str[0] == '-' || str[0] == '+'),
			pos = str.find_first_not_of("0123456789", sign);

	return (pos != std::string::npos && str[pos] == '.'
		&& str.find_first_not_of("0123456789", ++pos) == std::string::npos);
}

static void	convertChar(s_type& sType, const char* str) {
	sType.c = str[0];
	sType.i = static_cast< int >(sType.c);
	sType.f = static_cast< float >(sType.c);
	sType.d = static_cast< double >(sType.c);
}

static void	convertInt(s_type& sType, const char* str) {
	sType.i = std::atoi(str);
	sType.c = static_cast< char >(sType.i);
	sType.f = static_cast< float >(sType.i);
	sType.d = static_cast< double >(sType.d);
}

static void	convertFloat(s_type& sType, const char* str) {
	sType.f = std::atof(str);
	sType.c = static_cast< char >(sType.f);
	sType.i = static_cast< int >(sType.f);
	sType.d = static_cast< double >(sType.f);
}

static void	convertDouble(s_type& sType, const char* str) {
	sType.d = std::atof(str);
	sType.c = static_cast< char >(sType.d);
	sType.i = static_cast< int >(sType.d);
	sType.f = static_cast< float >(sType.d);
}

static void	handleNotConvertible(const std::string& str) {
	std::cout << "Not convertible: " << str << std::endl;
}

void	ScalarConverter::convert(std::string str) {
	s_type	sType;

	if (isSpecial(str))
		handleSpecial(str.c_str()); ////
	else if (isChar(str))
		convertChar(sType, str.c_str());
	else if (isInt(str))
		convertInt(sType, str.c_str());
	else if (isFloat(str))
		convertFloat(sType, str.c_str());
	else if (isDouble(str))
		convertDouble(sType, str.c_str());
	else
		handleNotConvertible(str);

	// setprecision !
	std::stringstream	ss;
	
	ss << sType.f;
	std::cout << "char:\t" << sType.c << '\'' << std::endl
		<< "int:\t" << sType.i << std::endl;
		

	ss << sType.f;
	if (ss.str().find('.') == std::string::npos)
		ss << ".0f";
	else
		ss << 'f';
	std::cout << "float:\t" << ss.str() << std::endl;
	ss.str("");
	
	ss << sType.d;
	if (ss.str().find('.') == std::string::npos)
		ss << ".0";
	std::cout << "double:\t" << ss.str() << std::endl;
}
