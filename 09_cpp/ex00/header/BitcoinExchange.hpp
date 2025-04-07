/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:41:41 by locharve          #+#    #+#             */
/*   Updated: 2025/01/13 14:39:24 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <fstream>
# include <ctime>
# include <map>

class	BitcoinExchange {
	private:
		std::map<std::string, float>	_data;
		std::map<std::string, float>	_input; ////
		std::map<std::string, float>	_output; //
	public:
		BitcoinExchange();
		BitcoinExchange(std::string	input);
		BitcoinExchange(const BitcoinExchange& rhs);
		BitcoinExchange&	operator=(const BitcoinExchange& rhs);

		void	setData();
	//	void	setOutput(std::string input); ///
		void	parseInput(std::string input);

		void	printData(); //
		
		~BitcoinExchange();

		class	CannotOpenFileException: public std::exception {
			private:
				const char*	_filename;
				std::string	what_str;
			public:
				CannotOpenFileException(std::string filename);
				
				const char*	what() const throw();

				virtual ~CannotOpenFileException() throw() {}
		};
};

#endif