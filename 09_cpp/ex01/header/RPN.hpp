/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:04:46 by locharve          #+#    #+#             */
/*   Updated: 2025/04/14 16:17:41 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <iostream>
# include <exception>

# define WHITESPACES "\t\n\v\f\r "

class	RPN {
	private:
		std::stack< double >	_stack;
	public:
		RPN();
		RPN(std::string input);
		RPN(const RPN& rhs);
		RPN&	operator=(const RPN& rhs);

		void	calculate(const char& op);
		void	readInput(const std::string& input);
		void	printResult() const;
		~RPN();

		class	SyntaxError: public std::exception {
			public:
				const char*	what() const throw();
		};
};

#endif