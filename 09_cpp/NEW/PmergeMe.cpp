#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>

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
/*
std::vector< std::pair< int, int > >	makePairs(std::vector< int >& vec) {
	size_t	size = vec.size();
	std::vector< std::pair< int, int > >	pairs;

	for (size_t i = 0; i < size - 1; i += 2) {
		// first = max, second = min
		if (vec[i] > vec[i + 1])
			pairs.insert(pairs.begin(), std::make_pair(vec[i], vec[i + 1]));
		else
			pairs.insert(pairs.begin(), std::make_pair(vec[i + 1], vec[i]));
	}
	if (size % 2) {
		int	last = vec[size - 1];
		if (last > (std::max_element(pairs.begin(), pairs.end()))->first)
			pairs.insert(pairs.begin(), std::make_pair(last, -1));
		else
			pairs.insert(pairs.begin(), std::make_pair(-1, last));
	}
}
*/

template< typename T >
std::vector< T >	recursiveSort(std::vector< T >& vec) {
	size_t	size = vec.size();
	if (size <= 1) {
		//		pairs.insert(pairs.begin(), std::make_pair(vec[0], (T)0)); ////
		return (vec);
	}
	
	std::vector< std::pair< T, T > >	pairs;
	for (size_t i = 0; i < size - 1; i += 2) {
		// first = max, second = min
		if (vec[i] > vec[i + 1])
			pairs.insert(pairs.end(), std::make_pair(vec[i], vec[i + 1]));
		else
			pairs.insert(pairs.end(), std::make_pair(vec[i + 1], vec[i]));
	}

//	if (size % 2) { // last value // alone
//		T	last = vec[size - 1];
//	}

	std::vector< std::pair< T, T > >	newPairs = recursiveSort(pairs);
	std::cout << "newPairs" << std::endl << newPairs << std::endl;
	//	if (pairsPairs.size()) {

//	}

	return (vec);
}

void	binaryInsert(std::vector< int >& vec, int value, size_t high) {
	size_t	low = 0, mid;

	std::cout << "binaryInsert: " << value << std::endl;
	while (low <= high) {
		mid = low + (high - low) / 2;
//		if (value == vec[mid]) {
//			vec.insert(vec.begin() + mid, value);
//			std::cout << "/////" << vec << std::endl << "/////" << std::endl;
//			return ;
//		}
		if (value == vec[mid])
			break ;
		else if (value > vec[mid])
			low = mid + 1;
		else
			high = mid - 1;
	}
	vec.insert(vec.begin() + mid, value);
	std::cout << "/////" << std::endl << vec << "/////" << std::endl << std::endl;
}

std::vector< int >	recursiveSort(std::vector< int >& vec) {
	size_t	size = vec.size();
	if (size <= 1) {
		return (vec);
	}

	std::vector< int >	min, max;
	for (size_t i = 0; i < size - 1; i += 2) {
		int&	a = vec[i];
		int&	b = vec[i + 1];
		if (a < b) {
			min.push_back(a);
			max.push_back(b);
		} else {
			min.push_back(b);
			max.push_back(a);
		}
	}
	int	last = size % 2 ? vec[size - 1] : -1;

	std::vector< int >	sorted = recursiveSort(max);

	sorted.insert(sorted.begin(), min[0]);
//	min.erase(min.begin());
	for (size_t i = 1, n = min.size() / 2; i < n; i += 2) {
		binaryInsert(sorted, min[i + 1], n);
		binaryInsert(sorted, min[i], n);		
	}
	if (last != -1)
		binaryInsert(sorted, last, sorted.size() - 1); ///// - 1 ?
	for (size_t i = min.size() - 1, n = min.size() / 2; i > n; i--) {
		std::cout << "second loop: min " << i << ": " << min[i] << std::endl;
		binaryInsert(sorted, min[i], n);
	}
	return (sorted);
}

int	main(int argc, char** argv) {
	if (argc > 2) {
		return (1);
	} else if (argc == 2) {
		std::vector< int >	vec = parse(argv[1]);
		std::vector< int >	sorted = recursiveSort(vec);
		std::cout << sorted << std::endl;

	} else
		std::cerr << "Usage: ./PmergeMe < positive int > ..." << std::endl;
}