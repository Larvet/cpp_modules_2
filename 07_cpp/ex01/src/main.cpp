/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:40:20 by locharve          #+#    #+#             */
/*   Updated: 2025/01/02 08:52:43 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main() {
	int*	intTab = new int[10];
	if (!intTab)
		return (1);

	std::string*	strTab = new std::string[10];
	if (!strTab) {
		delete [] intTab;
		return (2);
	}

	float*	fltTab = new float[10];
	if (!fltTab) {
		delete [] intTab;
		delete [] strTab;
		return (3);
	}

	ExampleClass*	exTab = new ExampleClass[10];
	if (!exTab) {
		delete [] intTab;
		delete [] strTab;
		delete [] fltTab;
		return (4);
	}

	for (int i = 0; i < 10; i++) {
		intTab[i] = i;
		strTab[i] = i + 48;
		fltTab[i] = i;
		exTab[i] = i;
	}

	std::cout << std::endl << "/////// Before iter:" << std::endl;
	for (int i = 0; i < 10; i++) {
		std::cout << "i = " << i
			<< "\tint: " << intTab[i]
			<< "\tstr: " << strTab[i]
			<< "\tflt: " << fltTab[i]
			<< "\tex : " << exTab[i]
			<< std::endl;
	}

	::iter(intTab, 10, foo);
	::iter(strTab, 10, foo);
	::iter(fltTab, 10, foo);
	::iter(exTab, 10, foo);

	std::cout << std::endl << "/////// After iter:" << std::endl;
	for (int i = 0; i < 10; i++) {
		std::cout << "i = " << i
		<< "\tint: " << intTab[i]
		<< "\tstr: " << strTab[i]
		<< "\tflt: " << fltTab[i]
		<< "\tex : " << exTab[i]
		<< std::endl;
	}

	delete [] intTab;
	delete [] strTab;
	delete [] fltTab;
	delete [] exTab;
}