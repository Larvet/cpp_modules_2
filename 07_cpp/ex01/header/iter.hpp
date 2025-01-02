/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:37:06 by locharve          #+#    #+#             */
/*   Updated: 2025/01/02 08:52:41 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

class	ExampleClass {
	private:
		int	_n;
		void*	_ptr;
	public:
		ExampleClass(int n, void* ptr): _n(n), _ptr(ptr) {}
		ExampleClass() { _n = 42; _ptr = NULL; }
		ExampleClass(const ExampleClass& src) { *this = src; }
		ExampleClass&	operator=(const ExampleClass& src) { _n = src.getN(); _ptr = src.getPtr(); return (*this); }
		ExampleClass&	operator=(const int& n) { _n = n; return (*this); }
		~ExampleClass() {}

		void	setN(int n) { _n = n; }
		void	setPtr(void* ptr) { _ptr = ptr; }

		int	getN() const { return (_n); }
		void*	getPtr() const { return (_ptr); }

	//	ExampleClass&	operator+=(const int& n) { _n += n; return (*this); }

		bool	operator<(const ExampleClass& ex) const { return (_n < ex.getN()); }
	//	bool	operator<(const ExampleClass& ex) const { return (_ptr < ex.getPtr()); }		

		bool	operator>(const ExampleClass& ex) const { return (_n > ex.getN()); }
	//	bool	operator>(const ExampleClass& ex) const { return (_ptr > ex.getPtr()); }
};

std::ostream&	operator<<(std::ostream& os, const ExampleClass& ex) { os << ex.getN() << " " << ex.getPtr(); return (os); }

template<typename T>
void	foo(T & param) {
	param += 48;
}

template<>
void	foo<ExampleClass>(ExampleClass& ex) {
	ex.setN(ex.getN() + 48);
	ex.setPtr((void*)((long)(ex.getPtr()) + 48));
}

template<typename T>
void	iter(T* & addr, size_t size, void f(T&)) {
	for (size_t i = 0; i < size; i++)
		f(addr[i]);
}

#endif