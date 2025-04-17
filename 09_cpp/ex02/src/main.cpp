#include "PmergeMe.hpp"

int	main(int argc, char** argv) {
	if (argc >= 2) {
		try {
			PmergeMe	pmm(argv[1]);
		//	std::cout << pmm << std::endl;
		//	pmm.recursiveSort(pmm.getVector());
		//	pmm.sortVector(pmm.getVector());
			std::vector< std::pair< int, int > >	pairs = pmm.initPairs(pmm.getVector()),
				pairs2 = pmm.sortPairs(pairs);

		
		} catch (PmergeMe::MustBeDigits& e) {
			std::cerr << e.what() << std::endl;
		} catch (PmergeMe::OOBNumber& e) {
			std::cerr << e.what() << std::endl;
		}
	} else {
		return (1);
	}
}