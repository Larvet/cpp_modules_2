#include <iostream>
#include <vector>

template< typename T >
const T&	testMax(const T& a, const T& b) {
	return (a > b ? a : b);
}

int	main() {
	std::pair< int, int >	p1(3, 5), p2(3, 4);
	std::pair< int, int >	pMax = testMax(p1, p2);
	std::cout << pMax.first << " " << pMax.second << std::endl;
	return (0);
}