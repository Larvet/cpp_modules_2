/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 11:15:28 by locharve          #+#    #+#             */
/*   Updated: 2025/04/10 20:02:03 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <list>

// stack, queue, priority_queue !

int	main() {
	int	value = 2;

	std::vector<int>	myVec;
	myVec.push_back(1);
	myVec.push_back(2);
	myVec.push_back(3);

	std::vector< int >::iterator	vecIt = easyfind(myVec, value);
	if (vecIt != myVec.end())
		std::cout << "Found in vector: " << *vecIt
			<< " at index: " << vecIt - myVec.begin() << std::endl;
	else
		std::cout << "Not found in vector: " << value << std::endl;

	////////////////////////////////////////////////////////////////

	std::deque<int>	myDeq;
	myDeq.push_back(1);
	myDeq.push_back(2);
	myDeq.push_back(3);

	std::deque< int >::iterator	deqIt = easyfind(myDeq, value);
	if (deqIt != myDeq.end())
		std::cout << "Found in deque: " << *deqIt
			<< " at index: " << deqIt - myDeq.begin() << std::endl;
	else
		std::cout << "Not found in deque: " << value << std::endl;

	////////////////////////////////////////////////////////////////

	std::list<int>	myLst;
	myLst.push_back(1);
	myLst.push_back(2);
	myLst.push_back(3);

	std::list< int >::iterator	lstIt = easyfind(myLst, value);
	if (lstIt != myLst.end()) {
		std::list< int >::iterator	tmpIt = myLst.begin();
		size_t	i = 0;
		while (tmpIt != lstIt && tmpIt != myLst.end()) {
			tmpIt++;
			i++;
		}
		std::cout << "Found in list: " << *lstIt
			<< " at index: " << i << std::endl;
	} else
		std::cout << "Not found in list: " << value << std::endl;

	return (0);
}
