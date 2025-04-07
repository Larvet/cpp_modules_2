/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:41:46 by locharve          #+#    #+#             */
/*   Updated: 2025/01/10 12:15:08 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <list>
#include <deque>

template< typename T, typename Container = std::deque< T > >
class	MutantStack: public std::stack< T, Container > {
	public:
		MutantStack() {}
		MutantStack(const MutantStack& src) { *this = src; }
		MutantStack&	operator=(const MutantStack& src) {
			this->c = src.c;
			return (*this);
		}

		typedef typename Container::iterator iterator;

		iterator	begin() {
			return (this->c.begin());
		}
		iterator	rbegin() {
			return (this->c.rbegin());
		}
		iterator	end() {
			return (this->c.end());
		}
		iterator	rend() {
			return (this->c.rend());
		}

		void print() {
			iterator	it = begin();
			iterator	ite = end();

			while (it != ite) {
				std::cout << *it << std::endl;
				it++;
			}
		}

		~MutantStack() {}
};