/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:37:06 by locharve          #+#    #+#             */
/*   Updated: 2024/12/18 15:49:07 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T>
void	foo(T & param) {
	param += 48;
}

template<typename T>
void	iter(T* & addr, size_t size, void f(T&)) {
	for (size_t i = 0; i < size; i++)
		f(addr[i]);
}

#endif