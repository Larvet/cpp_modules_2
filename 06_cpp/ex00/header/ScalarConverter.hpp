/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:09:15 by locharve          #+#    #+#             */
/*   Updated: 2024/12/16 15:39:40 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cstdlib>
# include <cctype>
# include <limits>
# include <sstream>

struct s_type {
	char	c;
	int		i;
	float	f;
	double	d;
};


class	ScalarConverter {
	private:
		ScalarConverter();
	public:
		ScalarConverter(const ScalarConverter& src);
		ScalarConverter& operator=(const ScalarConverter& src);
		
		static void convert(std::string str);

		~ScalarConverter();
};

#endif