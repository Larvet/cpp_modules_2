#include "PMergeMe.hpp"

PMergeMe::PMergeMe() {}

PMergeMe::PMergeMe(std::string input) {
	std::stringstream	ss(input);
	std::string	word;

	while (ss >> word) {
		if (word.find_first_not_of("0123456789") != std::string::npos)
			throw (MustBeDigits());
		long long	nbr = std::atoll(word.c_str());
		if (nbr < 0 || nbr > 2147483647)
			throw (OOBNumber());
		_vec.push_back(static_cast< unsigned int >(nbr));
		_deq.push_back(static_cast< unsigned int >(nbr));
	}
}

PMergeMe::PMergeMe(const PMergeMe& rhs) {
	*this = rhs;
}

PMergeMe&	PMergeMe::operator=(const PMergeMe& rhs) {
	_vec = rhs._vec;
	return (*this);
}

void	recursiveSort(std::vector< unsigned int >& vec) {
	
}

unsigned int	PMergeMe::sortVector() {
	// time start
	
	// time end
}

const std::vector< unsigned int >&	PMergeMe::getVector() const {
	return (_vec);
}

const std::deque< unsigned int >&	PMergeMe::getDeque() const {
	return (_deq);
}

PMergeMe::~PMergeMe() {}

// EXCEPTIONS

const char*	PMergeMe::MustBeDigits::what() const throw() {
	return ("Arguments must be only digits.");
}

const char*	PMergeMe::OOBNumber::what() const throw() {
	return ("Arguments must be integers as: 0 <= arg <= 2147483647.");
}

// operator<<

std::ostream&	operator<<(std::ostream& os, const PMergeMe& rhs) {
	const std::vector< unsigned int >&	vec = rhs.getVector();
	os << "/////// VECTOR" << std::endl;
	for (size_t i = 0, n = vec.size(); i < n; i++)
		os << vec[i] << std::endl;
	
	const std::deque< unsigned int >&	deq = rhs.getDeque();
	os << std::endl << "/////// DEQUEU" << std::endl;
	for (size_t i = 0, n = deq.size(); i < n; i++)
		os << deq[i] << std::endl;

	return (os);
}
