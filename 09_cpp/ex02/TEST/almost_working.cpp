#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

template< typename T >
std::ostream&	operator<<(std::ostream& os, const std::pair< T, T >& pair) {
	os << pair.first << '\t' << pair.second << std::endl;
	return (os);
}

template< typename T >
std::ostream&	operator<<(std::ostream& os, const std::vector< T >& vec) {
	for (size_t i = 0, n = vec.size(); i < n; i++)
		os << vec[i] << std::endl;
	return (os);
}

template< typename T >
void	swap(T& a, T& b) {
	T	tmp = a;
	a = b;
	b = tmp;
}

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

// fake binaryInsert
void	binaryInsert(std::vector< int >& vec, int value, size_t high) {
	std::cout << "binaryInsert: " << value
		<< " in " << std::endl << vec << std::endl;
	(void) high;
	size_t	i = 0;
	while (i < vec.size()) {
		if ((!i && value <= vec[i])
			|| (i && value > vec[i - 1] && value <= vec[i]))
			break ;
		i++;
	}
//	i += (i < vec.size() - 1);
	std::cout << "binaryInsert: i = " << i << std::endl;
	vec.insert(vec.begin() + i, value);
}

std::vector< int >	recursiveSort(std::vector< int >& vec) {
	std::cout << "ENTER IN RECURSIVESORT: " << vec.size() << std::endl
		<< vec << std::endl;
	size_t	size(vec.size());
	if (size <= 1)
		return (vec);
	bool	odd = size % 2;
	size = size / 2 + odd;
	std::vector< int >	min(vec.begin(), vec.begin() + size),
		max(vec.begin() + size, vec.end());
	size -= odd;
	for (size_t i = 0; i < size; i++) {
		if (min[i] > max[i])
			swap(min[i], max[i]);
		std::cout << min[i] << '\t' << max[i] << std::endl;
	}
	
//	std::cout << "/////// MIN" << std::endl << min << std::endl
//		<< "/////// MAX" << std::endl << max << std::endl;
	max = recursiveSort(max);
//	std::cout << "MAX AFTER RECURSION" << std::endl << max << std::endl;
	vec.clear();
//	reserve ?
	vec = max;
	vec.reserve(max.size() + min.size());
	// std::cout << "size = " << size << std::endl;
	for (size_t i = 0; i < size; i++) { // size / 2 -> changement de sens
		std::cout << "i = " << i << std::endl;
		binaryInsert(vec, min[i], i);
	}
	if (odd)
		binaryInsert(vec, min[size], size);

	return (vec);
}

int	main(int argc, char** argv) {
	if (argc > 2) {
		return (1);
	} else if (argc == 2) {
		std::vector< int >	vec = parse(argv[1]);
		std::vector< int >	sorted = recursiveSort(vec);
	//	sort(vec);
		std::cout << vec << std::endl;

	} else
		std::cerr << "Usage: ./PmergeMe < positive int > ..." << std::endl;
}