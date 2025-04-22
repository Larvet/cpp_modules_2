/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:37:29 by locharve          #+#    #+#             */
/*   Updated: 2025/04/22 17:06:46 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <sstream>

class	PmergeMe {
	private:
		std::vector< int >	_vec, _deq;
		double	_vecTime, _deqTime;
	public:
		PmergeMe();
		PmergeMe(char** argv);
		PmergeMe(const PmergeMe& rhs);
		PmergeMe&	operator=(const PmergeMe& rhs);

		void	parse(char** argv);
		void	binaryInsert(std::vector< int >& vec, const int& value);

		template< typename Container >
		bool	isSorted(const Container& container) const;
		template< typename Container >
		Container	recursiveSort(Container& container);

		void	sortVec();
		void	sortDeq();

		~PmergeMe();

		class	MustBeDigits: public std::exception {
			const char*	what() const throw();
		};
		class	IntOverflow: public std::exception {
			const char*	what() const throw();
		};
};

#endif