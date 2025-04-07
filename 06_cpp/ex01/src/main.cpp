/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:35:55 by locharve          #+#    #+#             */
/*   Updated: 2025/04/03 16:55:49 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main() {
	Data	data;
	data.n = 42;
	std::cout << "original:\t" << &data << std::endl;

	uintptr_t	ui = Serializer::serialize(&data);
	std::cout << "serialized:\t0x" << std::hex << ui << std::endl;
	
	Data*	dptr = Serializer::deserialize(ui);
	std::cout << "deserialized:\t" << dptr << std::endl;
	return (0);
}