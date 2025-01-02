/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:04:07 by locharve          #+#    #+#             */
/*   Updated: 2025/01/02 11:39:35 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <cstdlib>

template<typename T>
class	Array {
	private:
		T*	_array;
		unsigned int	_size; // ?
	public:
		Array() {
			_array = new T[0];
			_size = 0;
		}
		Array(unsigned int n) {
			_array = new T[n];
			for (unsigned int i = 0; i < n; i++)
				_array[i] = i; /////
			_size = n;
		}
		Array(const Array& src) { *this = src; }
		Array&	operator=(const Array& src) { _array = new T[src.size()]; }

		T&	operator[](unsigned int n) {
			try {
				if (_size == 0)
					throw EmptyArrayException();
				else if (n >= _size)
					throw OOBException();
				else
					return (_array[n]);
			} catch (const EmptyArrayException& e) {
				std::cerr << e.what() << std::endl;
				delete [] _array;
				exit(1);
			} catch (const OOBException& e) {
				std::cerr << e.what() << std::endl;
				return (_array[_size - 1]);
			}
		}

		unsigned int	size() const { return (_size); }
/*
		void	printOne(unsigned int i) const {
			std::cout << *this[i] << std::endl;
		}

		void	printAll() const {
			for (unsigned int i = 0; i < _size; i++)
				printOne(i);
		} ////////
*/
		~Array() { delete [] _array; }

		class	EmptyArrayException: public std::exception {
			public:
				const char*	what() const throw() { return ("The array is empty. Cannot return any value. Exiting program."); }
		};
		class	OOBException: public std::exception {
			public:
				const char*	what() const throw() { return ("Index value is out of bounds. Last value of the array is returned instead."); }
		};
};