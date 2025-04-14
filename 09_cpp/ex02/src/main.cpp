#include "PMergeMe.hpp"

int	main(int argc, char** argv) {
	if (argc >= 2) {
		try {
			PMergeMe	pmm(argv[1]);
			std::cout << pmm << std::endl;
		
		} catch (PMergeMe::MustBeDigits& e) {
			std::cerr << e.what() << std::endl;
		} catch (PMergeMe::OOBNumber& e) {
			std::cerr << e.what() << std::endl;
		}
	} else {
		return (1);
	}
}