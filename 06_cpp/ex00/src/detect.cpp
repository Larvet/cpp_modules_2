#include "detect.hpp"

bool	detectPseudoLitteral(const std::string& str) {
	return (str == "nan" || str == "nanf" || str == "-inf"
		|| str == "-inff" || str == "+inf" || str == "+inff");
}

bool	detectChar(const std::string& str) {
	return (str.size() == 1 && isprint(str[0]));
}

bool	detectInt(const std::string& str) {
	size_t	sign = (str[0] == '-' || str[0] == '+');
	return (str.find_first_not_of("0123456789", sign) == std::string::npos);
}

bool	detectFloat(const std::string& str) {
	size_t	sign = (str[0] == '-' || str[0] == '+'),
			pos = str.find_first_not_of("0123456789", sign);

	if (pos != std::string::npos && str[pos] == '.') {
		pos = str.find_first_not_of("0123456789", ++pos);

		return (pos != std::string::npos && str[pos] == 'f' && pos == str.size() - 1);
	}
	return (false);
}

bool	detectDouble(const std::string& str) {
	size_t	sign = (str[0] == '-' || str[0] == '+'),
			pos = str.find_first_not_of("0123456789", sign);

	return (pos != std::string::npos && str[pos] == '.'
		&& str.find_first_not_of("0123456789", ++pos) == std::string::npos);
}
