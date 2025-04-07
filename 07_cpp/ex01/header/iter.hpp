/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:37:06 by locharve          #+#    #+#             */
/*   Updated: 2025/04/07 17:01:39 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

// ExampleClass for tests
// here because additional .hpp files are not allowed

class	ExampleClass {
	private:
		int	_n;
		void*	_ptr;
	public:
		ExampleClass();
		ExampleClass(int n, void* ptr);
		ExampleClass(const ExampleClass& src);
		ExampleClass&	operator=(const ExampleClass& src);
		ExampleClass&	operator=(const int& n);
		~ExampleClass();

		void	setN(int n);
		void	setPtr(void* ptr);

		int	getN() const;
		void*	getPtr() const;

		bool	operator<(const ExampleClass& ex) const;
		bool	operator>(const ExampleClass& ex) const;
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