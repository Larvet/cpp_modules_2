/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:48:48 by locharve          #+#    #+#             */
/*   Updated: 2025/04/07 16:54:27 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

# include <stdlib.h>
# include <string.h>

template<typename T>
void	swap(T& a, T& b) {
	T	tmp = a;
	a = b; 
	b = tmp;
}

template<typename T>
T const&	min(T const& a, T const& b) {
	return (a < b ? a : b);
}

template<typename T>
T const&	max(T const& a, T const& b) {
	return (a > b ? a : b);
}

// ExampleClass for tests
// here because additional .hpp files are not allowed

class	ExampleClass {
	private:
		int		_n;
		void*	_ptr;
	public:
		ExampleClass(int n, void* ptr);
		ExampleClass();
		ExampleClass(const ExampleClass& src);
		ExampleClass&	operator=(const ExampleClass& src);
		
		int	getN() const;
		void*	getPtr() const;
		
		bool	operator<(const ExampleClass& ex) const;
		
		bool	operator>(const ExampleClass& ex) const;

		~ExampleClass();
};

std::ostream&	operator<<(std::ostream& os, const ExampleClass& ex);

#endif