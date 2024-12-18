/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:48:48 by locharve          #+#    #+#             */
/*   Updated: 2024/12/18 15:24:32 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

# include <stdlib.h>
# include <string.h>

template<typename T>
void	swap(T& a, T& b) {
	T	tmp = a;
	a = b; 
	b = tmp;
}

template<typename T>
T const&	min(T const& a, T const& b) {
	return (a < b ? a : b);
}

template<typename T>
T const&	max(T const& a, T const& b) {
	return (a > b ? a : b);
}

#endif