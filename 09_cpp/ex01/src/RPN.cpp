#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const char* const & input) {
	try {
		readInput(input);
		printResult();
	} catch (SyntaxError& e) {
		std::cerr << e.what() << std::endl;
	}
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
	int	a = _stack.top();
	_stack.pop();
	int	b = _stack.top();
	_stack.pop();
	int	result;
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

void	RPN::readInput(const char* const & input) {
	for (size_t i = 0; input[i]; i++, i += (input[i] == ' ')) {
		if (isdigit(input[i]))
			_stack.push(input[i] - 48);
		else if (isOperator(input[i]))
			calculate(input[i]);
		else
			throw (SyntaxError());
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