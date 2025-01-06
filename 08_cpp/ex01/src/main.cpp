/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:33:22 by locharve          #+#    #+#             */
/*   Updated: 2025/01/06 14:33:26 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>
#include <cstdlib>

int	main() {
	Span	span(7);

	srand(time(NULL));

	span.print();
	for (int i = 0; i < 10; i++) {
		span.addNumber(rand() % 100);
		span.print();
	}

	std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
	std::cout << "Longest span: " << span.longestSpan() << std::endl;

	span.addRange(10);
	std::cout << "After addRange()" << std::endl;
	span.print();

	std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
	std::cout << "Longest span: " << span.longestSpan() << std::endl;

	std::cout << std::endl << "///////////////////" << std::endl << std::endl;

	Span	span2(100000);
	for (int i = 0; i < 50000; i++) {
		span2.addNumber(rand() % 100000);
	//	span.print();
	}
	std::cout << "Shortest span: " << span2.shortestSpan() << std::endl;
	std::cout << "Longest span: " << span2.longestSpan() << std::endl;

	span2.addRange(10000);
	std::cout << "After addRange()" << std::endl;
	span2.print();

	std::cout << "Shortest span: " << span2.shortestSpan() << std::endl;
	std::cout << "Longest span: " << span2.longestSpan() << std::endl;

	return (0);
}