#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::string input) {
	std::stringstream	ss(input);
	std::string	word;

	while (ss >> word) {
		if (word.find_first_not_of("0123456789") != std::string::npos)
			throw (MustBeDigits());
		long long	nbr = std::atoll(word.c_str());
		if (nbr < 0 || nbr > 2147483647)
			throw (OOBNumber());
		_vec.push_back(static_cast< int >(nbr));
		_deq.push_back(static_cast< int >(nbr));
	}
}

PmergeMe::PmergeMe(const PmergeMe& rhs) {
	*this = rhs;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& rhs) {
	_vec = rhs._vec;
	return (*this);
}

// size_t	binarySearch(const std::vector< unsigned int >& vec, unsigned int value, size_t n) {
// //	std::vector< unsigned int >::iterator	it;
// 	if (value > vec[n]) {
// 		return (binarySearch(vec, value, n + n / 2));
// 	} else {
// 		return (binarySearch(vec, value, n - n / 2));
// 	}
// }

// first = max ; second = min
/*
void	PmergeMe::recursiveSort(const std::vector< unsigned int >& vec) {
	std::vector< std::pair< unsigned int, unsigned int > >	pairVec;
	unsigned int*	last = NULL;

	size_t i = 0, size = vec.size(), n = size / 2;
	while (i < n) {
		std::pair< unsigned int, unsigned int >	p;
		p.first = vec[i] > vec[size - i - 1] ? vec[i] : vec[size - i - 1];
		p.second = vec[i] < vec[size - i - 1] ? vec[i] : vec[size - i - 1];
		pairVec.insert(pairVec.begin(), p);
		i++;
	}
	if (size % 2)
		last = new unsigned int(vec[size / 2]); // catch ?

	std::sort(pairVec.begin(), pairVec.end());
	for (size_t i = 0, n = pairVec.size(); i < n; i++) {
		std::cout << pairVec[i].first << "\t" << pairVec[i].second << std::endl;
	}
	if (last)
		std::cout << *last << std::endl;

	_sortedVec.insert(_sortedVec.begin(), pairVec[0].second);
	_sortedVec.insert(_sortedVec.begin() + 1, pairVec[1].first);
	_sortedVec.insert(_sortedVec.begin() + 2, pairVec[1].first);

	for (size_t i = 1, n = pairVec.size(); i < n - 1; i++) {
		// binary insert pairVec[i + 1].second
		size_t	pos = binarySearch(_sortedVec, pairVec[i].second, _sortedVec.size(), 2);
		// binary insert pairVec[i].second
	}
	
	delete last;
}
*/

int	PmergeMe::sortVector() {
	// time start
	
	// time end
	return (0);
}

std::vector< int >	PmergeMe::sortVector(const std::vector< int >& vec) {
	size_t	vecSize = vec.size();
	if (vecSize == 1)
		return (vec);

	std::vector< std::pair< int, int > >	pairs;
	std::vector< int >	min, max;

	for (size_t i = 0; i < vecSize - 1; i += 2) {
		// first = min, second = max
		std::pair< int, int >	p;
		p.first = vec[i] < vec[i + 1] ? vec[i] : vec[i + 1];
		p.second = vec[i] > vec[i + 1] ? vec[i] : vec[i + 1];
		pairs.insert(pairs.begin(), p);
	}
	for (size_t i = 0, n = pairs.size(); i < n; i++) {
		std::pair< int, int >&	p = pairs[i];
		min.insert(min.begin(), p.first);
		max.insert(max.begin(), p.second);
	}
	if (vecSize % 2) {
		int	last = vec[vecSize - 1];
		if (last > *(std::max_element(max.begin(), max.end())))
			max.insert(max.end(), last);
		else
			min.insert(min.end(), last);
	}
	std::cout << "/////// max" << std::endl << max << std::endl
		<< "/////// min" << std::endl << min << std::endl;
	
	
	
	return (max);
}

std::vector< std::pair< int, int > >	PmergeMe::initPairs(const std::vector< int >& vec) {
	size_t	size = vec.size();
	std::pair< int, int >	p;
	std::vector< std::pair< int, int > >	pairs;

	for (size_t i = 0; i < size - 1; i += 2) {
		// first = min, second = max
		p.first = vec[i] < vec[i + 1] ? vec[i] : vec[i + 1];
		p.second = vec[i] > vec[i + 1] ? vec[i] : vec[i + 1];
		pairs.insert(pairs.begin(), p);
	}
	if (size % 2) {
		p.first = vec[size - 1];
		p.second = -1;
		pairs.insert(pairs.begin(), p);
	}
	return (pairs);
}

std::vector< std::pair< int, int > >	PmergeMe::sortPairs(std::vector< std::pair< int, int > >& pairs) {
	size_t	size = pairs.size();
	if (size <= 1)
		return (pairs);
	std::vector< int >	min, max;

	for (size_t i = 0; i < size; i++) {
		std::pair< int, int >&	p = pairs[i];
		min.insert(min.begin(), p.first);
		if (p.second >= 0)
			max.insert(max.begin(), p.second);
	}
	std::vector< std::pair< int, int > >	newPairs = initPairs(max),
		output = sortPairs(newPairs);
	std::cout << "/////// pairs" << std::endl << pairs << std::endl << std::endl;
	std::cout << "/////// newPairs" << std::endl << newPairs << std::endl << std::endl;
	std::cout << "/////// output" << std::endl << output << std::endl << std::endl;

	return (output);
}

const std::vector< int >&	PmergeMe::getVector() const {
	return (_vec);
}

const std::deque< int >&	PmergeMe::getDeque() const {
	return (_deq);
}

PmergeMe::~PmergeMe() {}

// EXCEPTIONS

const char*	PmergeMe::MustBeDigits::what() const throw() {
	return ("Arguments must be only digits.");
}

const char*	PmergeMe::OOBNumber::what() const throw() {
	return ("Arguments must be integers as: 0 <= arg <= 2147483647.");
}

// operator<<

std::ostream&	operator<<(std::ostream& os, const PmergeMe& rhs) {
	const std::vector< int >&	vec = rhs.getVector();
	os << "/////// VECTOR" << std::endl;
	for (size_t i = 0, n = vec.size(); i < n; i++)
		os << vec[i] << std::endl;
	
	const std::deque< int >&	deq = rhs.getDeque();
	os << std::endl << "/////// DEQUEU" << std::endl;
	for (size_t i = 0, n = deq.size(); i < n; i++)
		os << deq[i] << std::endl;

	return (os);
}

template< typename T >
std::ostream&	operator<<(std::ostream& os, const std::vector< T >& vec) {
	for (size_t i = 0, n = vec.size(); i < n; i++)
		os << vec[i] << std::endl;
	return (os);
}

template< typename T >
std::ostream&	operator<<(std::ostream& os, const std::pair< T, T >& p) {
	os << p.first << '\t' << p.second;
	return (os);
}