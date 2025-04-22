#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <sys/time.h>
#include <ctime>

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

std::vector< int >	parse(char** argv) {
	std::vector< int >	vec;
	std::string	buffer, word;
	for (size_t i = 0; argv[i]; i++) {
		buffer += argv[i];
		if (argv[i + 1])
			buffer += ' ';
	}
	std::stringstream	ss(buffer);
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

void	binaryInsert(std::vector< int >& vec, const int& value) {
	static size_t	low = 0, high = vec.size() - 1;

	size_t	mid = low + (high - low) / 2;
	if (high - low <= 1 || value == vec[mid] || (!mid && value <= vec[mid])
		|| (mid && value > vec[mid - 1] && value <= vec[mid])) {
		vec.insert(vec.begin() + mid, value);
		low = 0;
		high = vec.size() - 1;
	} else {
		if (value <= vec[mid])
			high -= (high - low) / 2;
		else
			low += (high - low) / 2;
		binaryInsert(vec, value);
	}
}

std::vector< int >	recursiveSort(std::vector< int >& vec) {
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
	}
	
	max = recursiveSort(max);
	vec = max;
	for (size_t i = 0; i < size; i++) // size / 2 -> changement de sens
		binaryInsert(vec, min[i]);
	if (odd)
		binaryInsert(vec, min[size]);

	return (vec);
}

int	main(int argc, char** argv) {
	if (argc > 2) {
		std::cerr << "bad usage" << std::endl;
		std::vector< int > vec = parse(&argv[1]);
	//	std::cout << "VEC:" << std::endl << vec << std::endl;
		clock_t	start = clock();

		std::vector< int >	sorted = recursiveSort(vec);
		// time end
		clock_t	end = clock();

		std::cout << vec << std::endl
			<< "time = " << 1000000.0 * (end - start) / CLOCKS_PER_SEC << std::endl
			<< "time = " << end - start << std::endl;
		return (1);
	} else if (argc == 2) {
		std::vector< int >	vec = parse(argv[1]);
		// time start
		clock_t	start = clock();

		std::vector< int >	sorted = recursiveSort(vec);
		// time end
		clock_t	end = clock();

		std::cout << vec << std::endl
			<< "time = " << 1000000.0 * (end - start) / CLOCKS_PER_SEC << std::endl
			<< "time = " << end - start << std::endl;

	} else
		std::cerr << "Usage: ./PmergeMe < positive int > ..." << std::endl;
}