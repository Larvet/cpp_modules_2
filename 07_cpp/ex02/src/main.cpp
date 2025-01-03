/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:52:51 by locharve          #+#    #+#             */
/*   Updated: 2025/01/03 13:19:36 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main() {
	Array<int>	a;
	
	int	n = a[11];
	std::cout << n << std::endl;

	std::cout << "//////////////" << std::endl;

	Array<ExampleClass>	b(3);
	ExampleClass	blob = b[4];
	std::cout << blob << std::endl;

	std::cout << "//////////////" << std::endl;

	Array<ExampleClass>	c;
	ExampleClass	blim = b[4];
	std::cout << blim << std::endl;

//	a.printOne(11);
//	a.printAll();

//	for (unsigned int i = 0; i < size; i++)
//		std::cout << a._array[i] << std::endl;
	return (0);
}