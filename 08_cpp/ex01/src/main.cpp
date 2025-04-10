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

int	main(int argc, char** argv) {
	Span	span(argc - 1 + 4);

	for (int i = 1; i < argc; i++) {
		span.addNumber(std::atoi(argv[i]));
	}
	span.print();

	std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
	std::cout << "Longest span: " << span.longestSpan() << std::endl;

	std::vector< int >	toInsert;
	toInsert.push_back(42);
	toInsert.push_back(0);
	toInsert.push_back(-1);
	toInsert.push_back(153);
	toInsert.push_back(21);

	span.addRange(std::make_pair(toInsert.begin(), toInsert.end()));
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

//	span2.addRange(10000);
//	std::cout << "After addRange()" << std::endl;
//	span2.print();

	std::cout << "Shortest span: " << span2.shortestSpan() << std::endl;
	std::cout << "Longest span: " << span2.longestSpan() << std::endl;

	return (0);
}