/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:04:07 by locharve          #+#    #+#             */
/*   Updated: 2025/01/03 13:21:44 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <cstdlib>

template<typename T>
class	Array {
	private:
		T*	_array;
		unsigned int	_size;
	public:
		Array() {
			_array = new T[0];
			_size = 0;
		}
		Array(unsigned int n) {
			_array = new T[n];
			_size = n;
		}
		Array(const Array& src) { *this = src; }
		Array&	operator=(const Array& src) { _array = new T[src.size()]; }

		T	operator[](unsigned int n) {
			try {
				if (_size == 0)
					throw EmptyArrayException();
				else if (n >= _size)
					throw OOBException();
				else
					return (_array[n]);
			} catch (const EmptyArrayException& e) {
				std::cerr << e.what() << std::endl;
				return ((T)0);
			} catch (const OOBException& e) {
				std::cerr << e.what() << std::endl;
				return (_array[_size - 1]);
			}
		}

		unsigned int	size() const { return (_size); }

		~Array() { delete [] _array; }

		class	EmptyArrayException: public std::exception {
			public:
				const char*	what() const throw() { return ("The array is empty. Cannot return any value: returning 0 instead."); }
		};
		class	OOBException: public std::exception {
			public:
				const char*	what() const throw() { return ("Index value is out of bounds. Last value of the array is returned instead."); }
		};
};

class	ExampleClass {
	private:
		int	_n;
		void*	_ptr;
	public:
		ExampleClass(int n): _n(n), _ptr(NULL) {}
		ExampleClass(int n, void* ptr): _n(n), _ptr(ptr) {}
		ExampleClass(): _n(42), _ptr(NULL) {}
		ExampleClass(const ExampleClass& src) { *this = src; }
		ExampleClass&	operator=(const ExampleClass& src) {
			_n = src.getN();
			_ptr = src.getPtr();
			return (*this);
		}
		ExampleClass&	operator=(const int& n) {
			_n = n;
			return (*this);
		}
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

std::ostream&	operator<<(std::ostream& os, const ExampleClass& ex) {
	os << ex.getN() << " " << ex.getPtr();
	return (os);
}