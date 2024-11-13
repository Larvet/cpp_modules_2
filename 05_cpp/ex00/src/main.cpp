#include "Bureaucrat.hpp"

int	main() {
	Bureaucrat	john;
	std::cout << john << std::endl;
	john.decrementGrade();
	john.incrementGrade();

	Bureaucrat	john_copy(john);
	std::cout << john_copy << std::endl;

	Bureaucrat	bobby("Bobby", 0);

	return (0);
}