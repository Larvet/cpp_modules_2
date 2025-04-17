/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:26:22 by locharve          #+#    #+#             */
/*   Updated: 2025/04/10 19:59:31 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <iterator>

template< typename T >
typename T::iterator	easyfind(T container, int value) {
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	return (it);
}