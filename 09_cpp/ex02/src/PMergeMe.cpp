#include "PMergeMe.hpp"

PMergeMe::PMergeMe() {}

PMergeMe::PMergeMe(const char** argv) {
	try {

	} catch () {
		std::cerr << std::endl;
	}
}

PMergeMe::PMergeMe(const PMergeMe& rhs) {
	*this = rhs;
}

PMergeMe&	PMergeMe::operator=(const PMergeMe& rhs) {
	_vec = rhs._vec;
	return (*this);
}

PMergeMe::~PMergeMe() {}