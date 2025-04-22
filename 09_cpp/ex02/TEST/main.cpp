/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:55:51 by locharve          #+#    #+#             */
/*   Updated: 2025/04/22 17:09:01 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PmergeMe.hpp"

int	main(int argc, char** argv) {
	if (argc >= 2) {
		PmergeMe	pmerge(argv + 1);
		
		pmerge.sortVec();
		pmerge.sortDeq();

		// print
	} else {
		std::cerr << "Usage: ./PmergeMe <positive int> ..." << std::endl;
		return (1);
	}
	return (0);
}