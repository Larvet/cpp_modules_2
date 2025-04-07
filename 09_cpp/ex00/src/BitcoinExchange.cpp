/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:46:01 by locharve          #+#    #+#             */
/*   Updated: 2025/01/13 14:57:45 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	try {
		setData();
	//	parseInput("input.txt");
		// input
	} catch (CannotOpenFileException& e) {
		std::cerr << e.what() << std::endl;
	}
}

BitcoinExchange::BitcoinExchange(std::string input) {
	try {
		setData();
		parseInput(input);
	//	setOutput(input); ///
	} catch (CannotOpenFileException& e) {
		std::cerr << e.what() << std::endl;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& rhs) {
	*this = rhs;
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& rhs) {
	_data = rhs._data;
	return (*this);
}

void	BitcoinExchange::setData() {
	std::ifstream	ifs("data.csv");
	std::string	str, tmp;
	size_t	len;

	if (ifs.is_open()) {
		while (getline(ifs, str)) {
			len = str.find(',', 0);
			tmp = str.substr(len + 1, std::string::npos);
			_data[str.substr(0, len)] = atof(tmp.c_str()); // check les limites de float !!
		}
		ifs.close();

		if (_data.count("date"))
			_data.erase(_data.find("date"));
	} else
		throw (CannotOpenFileException("data.csv"));
}

// errors:
// not a positive number
// bad input (date incorrecte, ie: 2001-42-42)
// int overflows

void	BitcoinExchange::parseInput(std::string input) {
	std::ifstream	ifs(input);
	std::string	str, tmp;
	size_t	len;

	if (ifs.is_open()) {
		while (getline(ifs, str)) {
		// check format str
		len = str.find(' ', 0);
		tmp = str.substr(len + 3, std::string::npos);
		_input[str.substr(0, len)] = atof(tmp.c_str());
		}
	}
}

// void	BitcoinExchange::setOutput(std::string input) {}

void	BitcoinExchange::printData() {
	std::map<std::string, float>::iterator	it = _data.begin();
	std::map<std::string, float>::iterator	ite = _data.end();

	std::cout << std::fixed;
	std::cout << std::setprecision(2);
	while (it != ite) {
		std::cout << it->first << "," << it->second << std::endl;
		it++;
	}
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::CannotOpenFileException::CannotOpenFileException(std::string filename):
	_filename(filename.c_str()), what_str("Error: Cannot open file: ") {
	what_str += _filename;
}

const char*	BitcoinExchange::CannotOpenFileException::what() const throw() {
	return (what_str.c_str());
}
