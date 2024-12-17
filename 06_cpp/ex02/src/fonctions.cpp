/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:34:42 by locharve          #+#    #+#             */
/*   Updated: 2024/12/17 15:56:28 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fonctions.hpp"

static void	BaseTabInit(Base* (&tab)[3]) {
	int	i = 0;
	tab[i] = new A();
	if (tab[i]) {
		i++;
		tab[i] = new B();
		if (tab[i]) {
			i++;
			tab[i] = new C();
		}
	}
	if (!tab[i]) {
		for (i = 0; tab[i]; i++)
			delete tab[i];
	}
}

Base*	generate() {
	Base*	tab[3];
	BaseTabInit(tab);
	if (!tab[0]) {
		std::cerr << "Allocation error in Base::generate()" << std::endl;
		return (NULL);
	}
	std::srand(std::time(NULL));
	int	r = std::rand() % 3;
	for (int i = 0; i < 3; i++) {
		if (i != r)
			delete tab[i];
	}
//	std::cout << "generate: " << (char)(r + 65) << std::endl;
	return (tab[r]);
}

void	identify(Base* p) {
	std::cout << "identify with ptr: ";
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void	identify(Base& p) {
	std::cout << "identify with ref: ";
	if (dynamic_cast<A*>(&p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(&p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(&p))
		std::cout << "C" << std::endl;
}