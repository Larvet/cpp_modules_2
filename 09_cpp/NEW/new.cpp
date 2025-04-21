#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

std::vector< int >	parse(std::string input) {
	std::vector< int >	vec;
	std::stringstream	ss(input);
	std::string	word;

	while (ss >> word) {
//		if (word.find_first_not_of("0123456789") != std::string::npos)
//			throw (MustBeDigits());
		long long	nbr = std::atoll(word.c_str());
//		if (nbr < 0 || nbr > 2147483647)
//			throw (OOBNumber());
		vec.push_back(static_cast< int >(nbr));
//		_deq.push_back(static_cast< int >(nbr));
	}
	return (vec);
}

void	sortVec(std::vector< int >& vec) {
	
}

template< typename T >
std::ostream&	operator<<(std::ostream& os, const std::pair< T, T >& pair) {
	os << pair.first << ' ' << pair.second << std::endl;
	return (os);
}

template< typename T >
std::ostream&	operator<<(std::ostream& os, const std::vector< T >& vec) {
	for (size_t i = 0, n = vec.size(); i < n; i++)
		os << vec[i] << std::endl;
	return (os);
}

int	main(int argc, char** argv) {
	if (argc > 2) {
		return (1);
	} else if (argc == 2) {
		std::vector< int >	vec = parse(argv[1]);
		sortVec(vec);
//		std::cout << pairs << std::endl;

	} else
		std::cerr << "Usage: ./PmergeMe < positive int > ..." << std::endl;
}