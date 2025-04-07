/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:44:51 by locharve          #+#    #+#             */
/*   Updated: 2025/01/10 12:04:51 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
/*
int	main() {
	MutantStack<int>	mstack;
	mstack.push(1);
	mstack.push(2);
	mstack.push(3);

	MutantStack<int>::iterator	it = mstack.begin();
//	(void)it;
	std::cout << *it << std::endl;

	return (0);
}
*/
int main()
{
	MutantStack<int> mstack;
//	std::list<int>	mstack;

	mstack.push(5);
//	mstack.push_front(5);
	mstack.push(17);
//	mstack.push_front(17);

	std::cout << mstack.top() << std::endl;
//	std::cout << mstack.front() << std::endl;
	mstack.pop();
//	mstack.pop_front();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
//	mstack.push_back(3);
	mstack.push(5);
//	mstack.push_back(5);
	mstack.push(737);
//	mstack.push_back(737);
	//[...]
	mstack.push(0);
//	mstack.push_back(0);

	MutantStack<int>::iterator it = mstack.begin();
//	std::list<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
//	std::list<int>::iterator ite = mstack.end();

	++it;
	--it;
	
	std::cout << std::endl << "mstack print" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);

	MutantStack<int>	copyStack = mstack;
//	MutantStack< int, std::list<int> >	copyStack = mstack;

	std::cout << std::endl << "Copy test" << std::endl;
	copyStack.print();
	
	return (0);
}