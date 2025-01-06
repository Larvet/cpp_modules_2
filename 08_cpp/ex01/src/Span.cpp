/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 12:31:37 by locharve          #+#    #+#             */
/*   Updated: 2025/01/06 14:32:52 by locharve         ###   ########.fr       */
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

int	Span::calculateDist(int a, int b) {
	int	dist = a - b;
	return (dist < 0 ? -dist : dist);
}

void	Span::updateDist(int a, int b) {
	_dist.push_back(calculateDist(a, b));
}

void	Span::addNumber(int nbr) {
	try {
		if (_stock.size() >= _size)
			throw (FullStockException());
		_stock.push_back(nbr);
		if (_stock.size() >= 2)
			updateDist(_stock[_stock.size() - 2], _stock[_stock.size() - 1]);
	} catch (FullStockException& e) {
		std::cerr << e.what() << std::endl;
	}
}

void	Span::addRange(unsigned int n) {
	try {
		if (_stock.size() >= _size)
			throw (FullStockException());
		if (_size + n > _stock.size())
			n = _size - _stock.size();
		std::vector<int>	tmpStock;
		srand(time(NULL));
		for (unsigned int i = 0; i < n; i++)
			tmpStock.push_back(rand() % 100000);
		std::vector<int>	tmpDist;
		for (unsigned int i = 0; i < n - 1; i++)
			tmpDist.push_back(calculateDist(tmpStock[i], tmpStock[i + 1]));
		_stock.insert(_stock.end(), tmpStock.begin(), tmpStock.end());
		_dist.insert(_dist.end(), tmpDist.begin(), tmpDist.end());
	} catch (FullStockException& e) {
		std::cerr << e.what() << std::endl;
	}
}

int	Span::shortestSpan() {
	try {
		if (_size <= 1)
			throw (TooFewNbrsException());
		return (*(std::min_element(_dist.begin(), _dist.end())));
	} catch (TooFewNbrsException& e) {
		std::cerr << e.what() << std::endl;
		return (-1);
	}
}

int	Span::longestSpan() {
	try {
		if (_size <= 1)
			throw (TooFewNbrsException());
		return (*(std::max_element(_dist.begin(), _dist.end())));
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
	it = _dist.begin();
	end = _dist.end();
	std::cout << "///// Dist:" << std::endl;
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