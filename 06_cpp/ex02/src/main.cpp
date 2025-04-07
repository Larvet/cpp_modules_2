/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:15:42 by locharve          #+#    #+#             */
/*   Updated: 2025/04/03 17:00:47 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "fonctions.hpp"

int	main() {
	Base*	ptr = generate();
	
	std::cout << "identify with ptr:\t"; 
	identify(ptr);
	std::cout << "identify with ref:\t"; 
	identify(*ptr);

	delete ptr;
	return (0);
}