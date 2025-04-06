#include "BitcoinExchange.hpp"

int	main(int argc, char** argv) {
	if (argc == 2) {
		BitcoinExchange	btc(argv[1]);
	//	std::cout << btc;
	} else
		std::cerr << "Usage: ./btc <input_file>" << std::endl;
	return (0);
}