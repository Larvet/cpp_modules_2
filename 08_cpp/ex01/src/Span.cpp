/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 12:31:37 by locharve          #+#    #+#             */
/*   Updated: 2025/01/07 10:27:51 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): _size(1) {}

Span::Span(unsigned int N): _size(N) {}

Span::Span(const Span& src) {
	*this = src;
}

Span&	Span::operator=(const Span& src) {
	_size = src.getSize();
	_stock = src.getStock();
	return (*this);
}

unsigned int const &	Span::getSize() const {
	return (_size);
}

std::vector<int> const &	Span::getStock() const {
	return (_stock);
}

void	Span::addNumber(int nbr) {
	try {
		if (_stock.size() >= _size)
			throw (FullStockException());
		_stock.push_back(nbr);
	} catch (FullStockException& e) {
		std::cerr << e.what() << std::endl;
	}
}

void	Span::addRange(typename s_vec_range< int >::t range) {
	try {
		if (_stock.size() >= _size)
			throw (FullStockException());
		
		s_vec_it< int >::t	it = range.first;
		for (size_t i = _stock.size(); i < _size && it != range.second; i++, it++);
		_stock.insert(_stock.end(), range.first, it);
		
		if (it != range.second)
			throw (RangeCutException());
	} catch (FullStockException& e) {
		std::cerr << e.what() << std::endl;
	} catch (RangeCutException& e) {
		std::cerr << e.what() << std::endl;
	}
}

int	Span::shortestSpan() const {
	try {
		if (_size <= 1)
			throw (TooFewNbrsException());

		std::vector< int >	sorted = _stock;
		std::sort(sorted.begin(), sorted.end());
		
		int	minSpan = sorted[1] - sorted[0];
		for (size_t i = 1, n = sorted.size(); i < n - 1; i++) {
			int	tmp = sorted[i + 1] - sorted[i];
			if (tmp < minSpan)
				minSpan = tmp;
		}
		return (minSpan);
	} catch (TooFewNbrsException& e) {
		std::cerr << e.what() << std::endl;
		return (-1);
	}
}

int	Span::longestSpan() const {
	try {
		if (_size <= 1)
			throw (TooFewNbrsException());
		
		std::cout << "max element = " << *(std::max_element(_stock.begin(), _stock.end())) << std::endl
			<< "min element = " << *(std::min_element(_stock.begin(), _stock.end())) << std::endl;
		return (*(std::max_element(_stock.begin(), _stock.end()))
			- *(std::min_element(_stock.begin(), _stock.end())));
	} catch (TooFewNbrsException& e) {
		std::cerr << e.what() << std::endl;
		return (-1);
	}
}

void	Span::print() {
	std::vector<int>::iterator	it = _stock.begin();
	std::vector<int>::iterator	end = _stock.end();
	std::cout << "///// Stock:\tmax size: " << _size
		<< "\tactual size: " << _stock.size() << std::endl;
	while (it != end) {
		std::cout << *it << std::endl;
		it++;
	}
}

Span::~Span() {}

const char*	Span::FullStockException::what() const throw() {
	return ("Maximum limit of stocked elements has already been reached.");
}

const char*	Span::TooFewNbrsException::what() const throw() {
	return ("There is less than two elements in the container. Therefore min or max span cannot be calculated. -1 is returned instead.");
}

const char*	Span::RangeCutException::what() const throw() {
	return ("Could not insert full range: exceeded max size.");
}