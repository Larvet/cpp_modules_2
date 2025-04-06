#pragma once

#include <stack>
#include <string>
#include <iostream>
#include <exception>

class	RPN {
	private:
		std::stack< int >	_stack;
	public:
		RPN();
		RPN(const char* const & input);
		RPN(const RPN& rhs);
		RPN&	operator=(const RPN& rhs);

		void	calculate(const char& op);
		void	readInput(const char* const & input);
		void	printResult() const;
		~RPN();

		class	SyntaxError: public std::exception {
			public:
				const char*	what() const throw();
		};
};