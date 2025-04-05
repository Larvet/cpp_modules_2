#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const char* const & fileName) {
	parseDataBase();
	parseInputFile(fileName);
	calculateResult();
	printResult();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& rhs) {
	*this = rhs;
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& rhs) {
	_dataBase = rhs.getDataBase();
	return (*this);
}

void	BitcoinExchange::parseDataBase() {
	std::ifstream	ifs("./data.csv"); // is dir ?
	if (!ifs.is_open())
		throw (CannotOpenFile("./data.csv"));
	
	std::string	str;
	std::getline(ifs, str);
	while (std::getline(ifs, str)) {
		size_t		pos(str.find(','));
		std::string	key = str.substr(0, pos),
			value = str.substr(pos + 1);
		_dataBase[key] = value;
	}
	ifs.close();
}

void	BitcoinExchange::parseInputFile(const char* const & fileName) {
	std::ifstream	ifs(fileName); // is dir ?
	if (!ifs.is_open())
		throw (CannotOpenFile(fileName));

	std::string	str;
	while (std::getline(ifs, str)) {
		size_t		pos(str.find('|'));
		if (pos == std::string::npos) {
			ifs.close();
			throw (BadInput(str)); //// catch where ?
		}
		std::string	key = str.substr(0, pos),
			value = str.substr(pos + 1);
			_input[key] = value;
	}
}

const std::map< std::string, std::string >&	BitcoinExchange::getDataBase() const {
	return (_dataBase);
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::CannotOpenFile::CannotOpenFile(std::string str):
	_str("Cannot open file: " + str) {}

const char*	BitcoinExchange::CannotOpenFile::what() const throw() {
	return (_str.c_str());
}

BitcoinExchange::BadInput::~BadInput() {}

BitcoinExchange::BadInput::BadInput(std::string str):
	_str("Bad input: " + str) {}

const char*	BitcoinExchange::BadInput::what() const throw() {
	return (_str.c_str());
}

BitcoinExchange::BadInput::~BadInput() {}

std::ostream&	operator<<(std::ostream& os, const BitcoinExchange& btc) {
	const	std::map< std::string, std::string >&
		dataBase = btc.getDataBase();
	std::map< std::string, std::string >::const_iterator
		it = dataBase.begin(), ite = dataBase.end();
	while (it != ite) {
		os << it->first << ',' << it->second << std::endl;
		it++;
	}
	return (os);
}