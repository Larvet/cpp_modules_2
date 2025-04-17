/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:40:56 by locharve          #+#    #+#             */
/*   Updated: 2025/04/17 17:51:53 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PmergeMe_HPP
# define PmergeMe_HPP

# include <iostream>
# include <sstream>
# include <vector>
# include <deque>
# include <string>
# include <algorithm>
# include <exception>
# include <cstdlib>
# include <ctime>

class	PmergeMe {
	private:
		std::vector< int >	_vec;
		std::vector< int > _sortedVec;
		
		std::deque< int >	_deq;
	public:
		PmergeMe();
		PmergeMe(std::string input);
		PmergeMe(const PmergeMe& rhs);
		PmergeMe&	operator=(const PmergeMe& rhs);

		void	recursiveSort(const std::vector< int >& vec);

		std::vector< int >	sortVector(const std::vector< int >& vec);
		std::vector< std::pair< int, int > >	initPairs(const std::vector< int >& vec);
		std::vector< std::pair< int, int > >	sortPairs(std::vector< std::pair< int, int > >& pairs);

		int	sortVector();
		int	sortDeque();

		const std::vector< int >&	getVector() const;
		const std::deque< int >&	getDeque() const;

		~PmergeMe();

		class	MustBeDigits: public std::exception {
			public:
				const char*	what() const throw();
		};
		class	OOBNumber: public std::exception {
			public:
				const char*	what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& os, const PmergeMe& rhs);

template< typename T >
std::ostream&	operator<<(std::ostream& os, const std::vector< T >& vec);

template< typename T >
std::ostream&	operator<<(std::ostream& os, const std::pair< T, T >& p);

#endif