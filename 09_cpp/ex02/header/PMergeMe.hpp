#pragma once

#include <iostream>
#include <vector>

class	PMergeMe {
	private:
		std::vector< unsigned int >	_vec;
	public:
		PMergeMe();
		PMergeMe(const char** argv);
		PMergeMe(const PMergeMe& rhs);
		PMergeMe&	operator=(const PMergeMe& rhs);

		~PMergeMe();
};