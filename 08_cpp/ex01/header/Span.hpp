/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 12:20:13 by locharve          #+#    #+#             */
/*   Updated: 2025/01/06 14:20:30 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

class	Span {
	private:
		unsigned int	_size;
		std::vector<int>	_stock;
		std::vector<int>	_dist;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span& src);
		Span&	operator=(const Span& src);

		unsigned int const &	getSize() const;
		std::vector<int> const &	getStock() const;

		int	calculateDist(int a, int b);
		void	updateDist(int a, int b);
		void	addNumber(int nbr);

		void	addRange(unsigned int n); /////

		int	shortestSpan();
		int	longestSpan();

		void	print();

		~Span();

		class	FullStockException: public std::exception {
			public:
				const char*	what() const throw();
		};
		class	TooFewNbrsException: public std::exception {
			public:
				const char*	what() const throw();
		};
};