/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:09:15 by locharve          #+#    #+#             */
/*   Updated: 2025/04/03 15:07:55 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <cctype>
# include <limits>
# include <sstream>

# include "detect.hpp"
# include "convert.hpp"

struct s_type {
	char	c;
	int		i;
	float	f;
	double	d;
};


class	ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& src);
		ScalarConverter& operator=(const ScalarConverter& src);
	public:
		
		static void convert(std::string str);

		~ScalarConverter();
};

#endif