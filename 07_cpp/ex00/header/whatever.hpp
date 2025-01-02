/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:48:48 by locharve          #+#    #+#             */
/*   Updated: 2025/01/02 08:30:03 by locharve         ###   ########.fr       */
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

class	ExampleClass {
	private:
		int	_n;
		void*	_ptr;
	public:
		ExampleClass(int n, void* ptr): _n(n), _ptr(ptr) {}
		ExampleClass() { _n = 42; _ptr = NULL; }
		ExampleClass(const ExampleClass& src) { *this = src; }
		ExampleClass&	operator=(const ExampleClass& src) { _n = src.getN(); _ptr = src.getPtr(); return (*this); }
		~ExampleClass() {}

		int	getN() const { return (_n); }
		void*	getPtr() const { return (_ptr); }

		bool	operator<(const ExampleClass& ex) const { return (_n < ex.getN()); }
	//	bool	operator<(const ExampleClass& ex) const { return (_ptr < ex.getPtr()); }		

		bool	operator>(const ExampleClass& ex) const { return (_n > ex.getN()); }
	//	bool	operator>(const ExampleClass& ex) const { return (_ptr > ex.getPtr()); }
};

std::ostream&	operator<<(std::ostream& os, const ExampleClass& ex) { os << ex.getN() << " " << ex.getPtr(); return (os); }

#endif