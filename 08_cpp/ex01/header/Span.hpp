/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 12:20:13 by locharve          #+#    #+#             */
/*   Updated: 2025/01/05 12:50:34 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>

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

		unsigned int&	getSize() const;
		std::vector<int>&	getStock() const;

		void	addNumber(int nbr);
		int	shortestSpan();
		int	longestSpan();

		~Span();

		class	FullStockException: public std::exception {
			const char*	what() const throw();
		}
};