/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:50:49 by locharve          #+#    #+#             */
/*   Updated: 2025/04/07 16:54:24 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

// ExampleClass member functions
// here because additional .cpp files are not allowed

ExampleClass::ExampleClass(int n, void* ptr): _n(n), _ptr(ptr) {}

ExampleClass::ExampleClass(): _n(42), _ptr(NULL) {}

ExampleClass::ExampleClass(const ExampleClass& src) {
	*this = src;
}

ExampleClass&	ExampleClass::operator=(const ExampleClass& src) {
	_n = src.getN();
	_ptr = src.getPtr();
	return (*this);
}

int	ExampleClass::getN() const {
	return (_n);
}

void*	ExampleClass::getPtr() const {
	return (_ptr);
}

bool	ExampleClass::operator<(const ExampleClass& ex) const {
	return (_n < ex.getN());
}

bool	ExampleClass::operator>(const ExampleClass& ex) const {
	return (_n > ex.getN());
}

ExampleClass::~ExampleClass() {}

std::ostream&	operator<<(std::ostream& os, const ExampleClass& ex) {
	os << ex.getN() << " " << ex.getPtr();
	return (os);
}

// main

int	main() {
	int	a = 42, b = 153;
	char*	cs1 = strdup("oui oui");
	char*	cs2 = strdup("non non");
	std::string	s1("ouais gros"), s2("c'est fatal bazooka");
	ExampleClass	ex1(b, &s1);
	ExampleClass	ex2(726, &b);

	std::cout << "/////// Before swap:" << std::endl
		<< "a = " << a << "\tb = " << b << std::endl
		<< "cs1 = " << cs1 << "\tcs2 = " << cs2 << std::endl
		<< "s1 = " << s1 << "\ts2 = " << s2 << std::endl
		<< "ex1 = " << ex1 << "\tex2 = " << ex2 << std::endl << std::endl;

	::swap<int>(a, b);
	::swap<char*>(cs1, cs2);
	::swap<std::string>(s1, s2);
	::swap<ExampleClass>(ex1, ex2);

	std::cout << "/////// After swap:" << std::endl
		<< "a = " << a << "\tb = " << b << std::endl
		<< "cs1 = " << cs1 << "\tcs2 = " << cs2 << std::endl
		<< "s1 = " << s1 << "\ts2 = " << s2 << std::endl
		<< "ex1 = " << ex1 << "\tex2 = " << ex2 << std::endl << std::endl;

	std::cout << "/////// min:" << std::endl
		<< "min(a, b) = " << ::min<int>(a, b) << std::endl
		<< "min(cs1, cs2) = " << ::min<char*>(cs1, cs2) << std::endl // doesn't work because char* has no overloaded operator
		<< "min(s1, s2) = " << ::min<std::string>(s1, s2) << std::endl
		<< "min(ex1, ex2) = " << ::min<ExampleClass>(ex1, ex2) << std::endl << std::endl;

	std::cout << "/////// max:" << std::endl
		<< "max(a, b) = " << ::max<int>(a, b) << std::endl
		<< "max(cs1, cs2) = " << ::max<char*>(cs1, cs2) << std::endl // doesn't work because char* has no overloaded operator
		<< "max(s1, s2) = " << ::max<std::string>(s1, s2) << std::endl
		<< "max(ex1, ex2) = " << ::max<ExampleClass>(ex1, ex2) << std::endl << std::endl;

	free (cs1);
	free (cs2);
}