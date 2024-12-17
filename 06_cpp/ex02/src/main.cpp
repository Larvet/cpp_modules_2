/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:15:42 by locharve          #+#    #+#             */
/*   Updated: 2024/12/17 15:57:09 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "fonctions.hpp"

int	main() {
	Base*	ptr = generate();
	
	// identify with ptr
	identify(ptr);
	// identify with ref
	identify(*ptr);

	delete ptr;
	return (0);
}