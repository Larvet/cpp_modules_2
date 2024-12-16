/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:38:14 by locharve          #+#    #+#             */
/*   Updated: 2024/12/16 16:08:53 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>
# include <iostream>
# include "Data.hpp"

class	Serializer {
	private:
		Serializer();
		Serializer(const Serializer& src);
		Serializer&	operator=(const Serializer& src);
	public:
		~Serializer();

		static uintptr_t	serialize(Data* ptr);
		static Data*	deserialize(uintptr_t raw);
};

#endif