#include "convert.hpp"

static size_t	getPrecision(const std::string& str) {
	size_t	start = str.find('.'), end = str.find_last_not_of("0f");

	return (end - start);
}

template< typename T >
static bool	isInLimits(long long ll) {
	return (ll >= std::numeric_limits< T >::min()
		&& ll <= std::numeric_limits< T >::max());
}

template< typename T >
static bool	isInLimits(double d) {
	return (d >= -std::numeric_limits< T >::max()
		&& d <= std::numeric_limits< T >::max());
}

void	convertPseudoLitteral(const std::string& str) {
	float	f;
	double	d;

	if (str == "nanf" || str == "+inff" || str == "-inff") {
		f = static_cast< float >(std::atof(str.c_str()));
		d = static_cast< double >(f);
	} else {
		d = static_cast< float >(std::atof(str.c_str()));
		f = static_cast< float >(d);
	}
	
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

void	convertChar(const std::string& str) {
	char	c = static_cast< char >(str[0]);
	int		i = static_cast< int >(c);
	float	f = static_cast< float >(c);
	double	d = static_cast< double >(c);

	std::cout << "char:\t\'" << c << '\'' << std::endl
		<< "int:\t" << i << std::endl
		<< "float:\t" << f << ".0f" << std::endl
		<< "double:\t" << d << ".0" << std::endl;
}

void	convertInt(const std::string& str) {
	int		i = std::atoi(str.c_str());
	char	c = static_cast< char >(i);
	float	f = static_cast< float >(i);
	double	d = static_cast< double >(i);

	long long	llLimit = std::atoll(str.c_str());
	double		dLimit = std::atof(str.c_str());
	std::stringstream	ss;

	if (isprint(c))
		ss << '\'' << c << '\'';
	else if (isInLimits< char >(llLimit))
		ss << "Non printable";
	else
		ss << "overflow";
	std::cout << "char:\t" << ss.str() << std::endl;
	ss.str("");

	if (isInLimits< int >(llLimit))
		ss << i;
	else
		ss << "overflow";
	std::cout << "int:\t" << ss.str() << std::endl;
	ss.str("");

	if (isInLimits< float >(dLimit))
		ss << f;
	else
		ss << "overflow";
	std::cout << "float:\t" << ss.str() << ".0f" << std::endl
		<< "double:\t" << d << ".0" << std::endl;
	ss.str("");
}

void	convertFloat(const std::string& str) {
	float	f = static_cast< float >(std::atof(str.c_str()));
	char	c = static_cast< char >(f);
	int		i = static_cast< int >(f);
	double	d = static_cast< double >(f);

	long long	llLimit = std::atoll(str.c_str());
	double		dLimit = std::atof(str.c_str());
	std::stringstream	ss;

	if (isprint(c))
		ss << '\'' << c << '\'';
	else if (isInLimits< char >(llLimit))
		ss << "Non printable";
	else
		ss << "overflow";
	std::cout << "char:\t" << ss.str() << std::endl;
	ss.str("");

	if (isInLimits< int >(llLimit))
		ss << i;
	else
		ss << "overflow";
	std::cout << "int:\t" << ss.str() << std::endl;
	ss.str("");

	if (isInLimits< float >(dLimit)) {
		ss << std::fixed << std::setprecision(getPrecision(str)) << f;
		if (ss.str().find('.') == std::string::npos)
			ss << ".0f";
		else
			ss << 'f';
	} else
		ss << "overflow";
	std::cout << "float:\t" << ss.str() << std::endl;
	ss.str("");

	ss << std::fixed << std::setprecision(getPrecision(str)) << d;
	if (ss.str().find('.') == std::string::npos)
		ss << ".0";
	std::cout << "double:\t" << ss.str() << std::endl;
	ss.str("");
}

void	convertDouble(const std::string& str) {
	double	d = std::atof(str.c_str());
	char	c = static_cast< char >(d);
	int		i = static_cast< int >(d);
	float	f = static_cast< double >(d);

	long long	llLimit = std::atoll(str.c_str());
	double		dLimit = std::atof(str.c_str());
	std::stringstream	ss;

	if (isprint(c))
		ss << '\'' << c << '\'';
	else if (isInLimits< char >(llLimit))
		ss << "Non printable";
	else
		ss << "overflow";
	std::cout << "char:\t" << ss.str() << std::endl;
	ss.str("");

	if (isInLimits< int >(llLimit))
		ss << i;
	else
		ss << "overflow";
	std::cout << "int:\t" << ss.str() << std::endl;
	ss.str("");

	if (isInLimits< float >(dLimit)) {
		ss << std::fixed << std::setprecision(getPrecision(str)) << f;
		if (ss.str().find('.') == std::string::npos)
			ss << ".0f";
		else
			ss << 'f';
	} else
		ss << "overflow";
	std::cout << "float:\t" << ss.str() << std::endl;
	ss.str("");

	ss << std::fixed << std::setprecision(getPrecision(str)) << d;
	if (ss.str().find('.') == std::string::npos)
		ss << ".0";
	std::cout << "double:\t" << ss.str() << std::endl;
	ss.str("");
}

void	handleNotConvertible(const std::string& str) {
	std::cout << "Not convertible: " << str << std::endl;
}