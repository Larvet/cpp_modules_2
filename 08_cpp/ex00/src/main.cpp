/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 11:15:28 by locharve          #+#    #+#             */
/*   Updated: 2025/01/05 12:19:23 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <list>

int	main() {
	int	value = 3;

	std::vector<int>	myVec;
	myVec.push_back(1);
	myVec.push_back(2);
	myVec.push_back(3);

	if (easyfind(myVec, value))
		std::cout << "Found in vector: " << value << std::endl;
	else
		std::cout << "Not found in vector: " << value << std::endl;

	////////////////////////////////////////////////////////////////

	std::deque<int>	myDeq;
	myDeq.push_back(1);
	myDeq.push_back(2);
	myDeq.push_back(3);

	if (easyfind(myDeq, value))
		std::cout << "Found in deque: " << value << std::endl;
	else
		std::cout << "Not found in deque: " << value << std::endl;

	////////////////////////////////////////////////////////////////

	std::list<int>	myLst;
	myLst.push_back(1);
	myLst.push_back(2);
	myLst.push_back(3);

	if (easyfind(myLst, value))
		std::cout << "Found in list: " << value << std::endl;
	else
		std::cout << "Not found in list: " << value << std::endl;

	return (0);
}
