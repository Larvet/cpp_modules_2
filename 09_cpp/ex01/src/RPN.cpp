#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(std::string input) {
	readInput(input);
	printResult();
}

RPN::RPN(const RPN& rhs) {
	*this = rhs;
}

RPN&	RPN::operator=(const RPN& rhs) {
	_stack = rhs._stack;
	return (*this);
}

static bool	isOperator(const char& c) {
	std::string	op("+-/*");
	return (op.find(c) != std::string::npos);
}

void	RPN::calculate(const char& op) {
	if (_stack.size() < 2)
		throw (SyntaxError());
	double	a = _stack.top();
	_stack.pop();
	double	b = _stack.top();
	_stack.pop();
	double	result;
	if (op == '+')
		result = b + a;
	else if (op == '-')
		result = b - a;
	else if (op == '*')
		result = b * a;
	else
		result = b / a;
	_stack.push(result);
}

void	RPN::readInput(const std::string& input) {
	size_t i = input.find_first_not_of(WHITESPACES, 0);
	while (i != std::string::npos) {
		if (isdigit(input[i]))
			_stack.push(input[i] - 48);
		else if (isOperator(input[i]))
			calculate(input[i]);
		else
			throw (SyntaxError());
		i = input.find_first_not_of(WHITESPACES, i + 1);
	}
}

void	RPN::printResult() const {
	if (_stack.size() != 1)
		throw (SyntaxError());
	std::cout << _stack.top() << std::endl;
}

RPN::~RPN() {}

// EXCEPTIONS

const char*	RPN::SyntaxError::what() const throw() {
	return ("Syntax error.");
}