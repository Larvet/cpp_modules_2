#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const char* const & fileName) {
	parseDataBase();
	readInputFile(fileName);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& rhs) {
	*this = rhs;
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& rhs) {
	_dataBase = rhs.getDataBase();
	return (*this);
}

static void	eraseWhitespaces(std::string& str) {
	size_t	pos = str.find_first_not_of(WHITESPACES),
		end = str.find_last_not_of(WHITESPACES);
	if (end != std::string::npos)
		end++;
	if (pos != std::string::npos && (pos < end || end == std::string::npos))
	str = str.substr(pos, end);
}

void	BitcoinExchange::parseDataBase() {
	std::ifstream	ifs("./data.csv"); // is dir ?
	if (!ifs.is_open())
		throw (CannotOpenFile("./data.csv"));
	
	std::string	str;
	std::getline(ifs, str);
	while (std::getline(ifs, str)) {
		size_t		pos(str.find(','));
		std::string	key = str.substr(0, pos), // retirer les espaces
			value = str.substr(pos + 1);
		eraseWhitespaces(key);
		eraseWhitespaces(value);
		_dataBase[key] = value;
	}
	ifs.close();
}

static bool	isDigit(const std::string& str) {
	size_t	i = 0;
	while (str[i] && isdigit(str[i]))
		i++;
	return (!str[i]);
}

static bool	isValidDate(const std::string& date, const std::string& min) {
	if (date < min)
		return (false);


	size_t	pos1 = date.find('-');
	if (pos1 == std::string::npos)
		return (false);


	std::string	buf = date.substr(0, pos1);
	size_t	nbr = std::atoi(buf.c_str());
	if (buf.size() != 4 || !isDigit(buf)
		|| nbr < static_cast< size_t >(std::atoi(min.substr(0, min.find('-')).c_str())) || nbr > 9999)
			return (false);
	

	size_t	pos2 = date.find('-', pos1 + 1);
	if (pos2 == std::string::npos)
		return (false);


	buf = date.substr(pos1 + 1, pos2 - (pos1 + 1));
	nbr = std::atoi(buf.c_str());
//	std::cout << "buf = " << buf << "\t" << nbr << std::endl;
	if (buf.size() != 2 || !isDigit(buf)
		|| nbr < 1 || nbr > 12)
			return (false);
	

	buf = date.substr(pos2 + 1);
	nbr = std::atoi(buf.c_str());
	if (buf.size() != 2 || !isDigit(buf)
		|| nbr < 1 || nbr > 31)
			return (false);
	

	return (true);
}

static bool	isValidAmount(const std::string& amount) {
	int	i = std::atoi(amount.c_str());
	float	f = std::atof(amount.c_str());

	return (i >= 0 && i <= 1000
		&& f >= 0.0f && f <= 1000.0f);
}

float	BitcoinExchange::calculateResult(const std::string& date, const std::string& amount) {
	std::map< std::string, std::string >::const_iterator
		itA = _dataBase.begin(), ite = _dataBase.end(),
		itB = itA;
		itB++;
	while (itB != ite && itB->first < date) {
		itA++;
		itB++;
	}
	if (itB == ite || itB->first != date)
		itB = itA;

	float	result;
	if (amount.find('.') != std::string::npos) {
		float	f = std::atof(amount.c_str());
		result = f * std::atof(itB->second.c_str());
	} else {
		int	i = std::atoi(amount.c_str());
		result = i * std::atof(itB->second.c_str());
	}
	return (result);
}

void	BitcoinExchange::readInputFile(const char* const & fileName) {
	try {
			std::ifstream	ifs(fileName); // is dir ?
			if (!ifs.is_open())
			throw (CannotOpenFile(fileName));

		std::string	str;
		std::getline(ifs, str); // check if header
		while (std::getline(ifs, str)) {
			try {
				size_t	pos(str.find('|'));
				if (pos == std::string::npos)
					throw (BadInput(str));

				std::string	date = str.substr(0, pos),
					amount = str.substr(pos + 1);
				eraseWhitespaces(date);
				eraseWhitespaces(amount);

				if (!isValidDate(date, getMin()))
					throw (InvalidDate(date));
				if (!isValidAmount(amount))
					throw (InvalidAmount(amount));

				float	result = calculateResult(date, amount);

				std::cout << date << " => " << amount << " = "
					<< std::fixed << std::setprecision(2) << result << std::endl;

			} catch (BadInput& e) {
				std::cerr << "Error: " << e.what() << std::endl;
			} catch (InvalidDate& e) {
				std::cerr << "Error: " << e.what() << std::endl;
			} catch (InvalidAmount& e) {
				std::cerr << "Error: " << e.what() << std::endl;
			}
		}
	} catch (CannotOpenFile& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

const std::map< std::string, std::string >&	BitcoinExchange::getDataBase() const {
	return (_dataBase);
}

const std::string&	BitcoinExchange::getMin() const {
	return (_dataBase.begin()->first);
}

BitcoinExchange::~BitcoinExchange() {}

// EXCEPTIONS

StrException::StrException(const std::string& str): _str(str) {}

const char*	StrException::what() const throw() {
	return (_str.c_str());
}

StrException::~StrException() throw() {}

BitcoinExchange::CannotOpenFile::CannotOpenFile(std::string str):
	StrException("Cannot open file: " + str) {}

BitcoinExchange::CannotOpenFile::~CannotOpenFile() throw() {}

BitcoinExchange::BadInput::BadInput(std::string str):
	StrException("Bad input: " + str) {}

BitcoinExchange::BadInput::~BadInput() throw() {}

BitcoinExchange::InvalidDate::InvalidDate(std::string str):
	StrException("Invalid date: " + str) {}

BitcoinExchange::InvalidDate::~InvalidDate() throw() {}

BitcoinExchange::InvalidAmount::InvalidAmount(std::string str):
	StrException("Invalid amount: " + str) {}

BitcoinExchange::InvalidAmount::~InvalidAmount() throw() {}

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