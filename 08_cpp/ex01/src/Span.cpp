/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 12:31:37 by locharve          #+#    #+#             */
/*   Updated: 2025/01/05 12:50:31 by locharve         ###   ########.fr       */
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

unsigned int&	Span::getSize() const {
	return (_size);
}

std::vector<int>&	getStock() const {
	return (_stock);
}

void	addNumber(int nbr) {
	try {
		if (_stock.size >= _size)
			throw (FullStockException());
		_stock.push_back(nbr);
	} catch (FullStockException& e) {
		std::cerr << e.what << std::endl;
	}
}

Span::~Span() {}

const char*	Span::FullStockException::what() const throw() {
	return ("Maximum limit of stocked elements has already been reached");
}