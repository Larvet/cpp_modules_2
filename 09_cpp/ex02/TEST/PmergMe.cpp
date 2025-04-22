/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergMe.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:39:47 by locharve          #+#    #+#             */
/*   Updated: 2025/04/22 17:08:30 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(char** argv) {
	parse(argv);
}

PmergeMe::PmergeMe(const PmergeMe& rhs) {
	*this = rhs;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& rhs) {
	_vec = rhs._vec;
	_deq = rhs._deq;
}

void	PmergeMe::parse(char** argv) {
	std::string	buffer, word;
	for (size_t i = 0; argv[i]; i++) {
		buffer += argv[i];
		if (argv[i + 1])
			buffer += ' ';
	}
	std::stringstream	ss(buffer);
	while (ss >> word) {
		if (word.find_first_not_of("0123456789") != std::string::npos)
			throw (MustBeDigits());
		long long	nbr = std::atoll(word.c_str());
		if (nbr < 0 || nbr > 2147483647)
			throw (IntOverflow());
		_vec.push_back(static_cast< int >(nbr));
		_deq.push_back(static_cast< int >(nbr));
	}
}

void	PmergeMe::binaryInsert(std::vector< int >& vec, const int& value) {
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

template< typename Container >
bool	PmergeMe::isSorted(const Container& container) const {
	size_t	i = 1, size = container.size();
	while (i < size && container[i - 1] <= container[i])
		i++;
	return (i == size);
}

template< typename Container >
Container	PmergeMe::recursiveSort(Container& container) {
	size_t	size(container.size());
	if (size <= 1)
		return (container);
	bool	odd = size % 2;
	size = size / 2 + odd;

	Container	min(container.begin(), container.begin() + size),
		max(container.begin() + size, container.end());
	size -= odd;
	for (size_t i = 0; i < size; i++) {
		if (min[i] > max[i])
			swap(min[i], max[i]);
	}
	
	max = recursiveSort(max);
	container = max;
	for (size_t i = 0; i < size; i++) // size / 2 -> changement de sens
		binaryInsert(container, min[i]);
	if (odd)
		binaryInsert(container, min[size]);

	return (container);
}

void	PmergeMe::sortVec() {
	clock_t	start = clock(), end;
	recursiveSort(_vec);
	end = clock();
	_vecTime = 1000000.0 * (end - start) / CLOCKS_PER_SEC;
}

void	PmergeMe::sortDeq() {
	clock_t	start = clock(), end;
	recursiveSort(_deq);
	end = clock();
	_deqTime = 1000000.0 * (end - start) / CLOCKS_PER_SEC;
}

PmergeMe::~PmergeMe() {}

// EXCEPTIONS

const char*	PmergeMe::MustBeDigits::what() const throw() {
	return ("Arguments must be only digits.");
}

const char*	PmergeMe::IntOverflow::what() const throw() {
	return ("An argument overflows int.");
}