#include "BitcoinExchange.hpp"

int	main(int argc, char** argv) {
	if (argc == 2) {
		try {
			BitcoinExchange	btc(argv[1]);
			//	std::cout << btc;
		} catch (BitcoinExchange::CannotOpenFile& e) {
			std::cerr << e.what() << std::endl;
		}

	} else
		std::cerr << "Usage: ./btc <input_file>" << std::endl;
	return (0);
}