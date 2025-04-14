/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:40:56 by locharve          #+#    #+#             */
/*   Updated: 2025/04/14 17:31:39 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <vector>
# include <deque>
# include <string>
# include <exception>
# include <cstdlib>
# include <ctime>

class	PMergeMe {
	private:
		std::vector< unsigned int >	_vec;
		std::deque< unsigned int >	_deq;
	public:
		PMergeMe();
		PMergeMe(std::string input);
		PMergeMe(const PMergeMe& rhs);
		PMergeMe&	operator=(const PMergeMe& rhs);

		unsigned int	sortVector();
		unsigned int	sortDeque();

		const std::vector< unsigned int >&	getVector() const;
		const std::deque< unsigned int >&	getDeque() const;

		~PMergeMe();

		class	MustBeDigits: public std::exception {
			public:
				const char*	what() const throw();
		};
		class	OOBNumber: public std::exception {
			public:
				const char*	what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& os, const PMergeMe& rhs);

#endif