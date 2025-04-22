#include "RPN.hpp"

int	main(int argc, char** argv) {
	if (argc == 2) {
		try {
			RPN	rpn(argv[1]);
		} catch (RPN::SyntaxError& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	return (0);
}