#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <iostream>
# include <string>
# include <fstream>
# include <exception>
# include <cstdlib>

class	BitcoinExchange {
	private:
		std::map< std::string, std::string >	_dataBase;
		std::map< std::string, std::string >	_input;
		std::map< std::pair< std::string, std::string >, std::string >	_result;
	public:
		BitcoinExchange();
		BitcoinExchange(const char* const & fileName);
		BitcoinExchange(const BitcoinExchange& rhs);
		BitcoinExchange&	operator=(const BitcoinExchange& rhs);

		void	parseDataBase();
		void	parseInputFile(const char* const & fileName);
		void	calculateResult();
		void	printResult() const;

		const std::map< std::string, std::string >&	getDataBase() const;

		~BitcoinExchange();

		class	CannotOpenFile: public std::exception {
			private:
				const std::string	_str;
			public:
				CannotOpenFile(std::string str);
				const char*	what() const throw();

				~CannotOpenFile();
		};
		class	BadInput: public std::exception {
			private:
				const std::string	_str;
			public:
				BadInput(std::string str);
				const char*	what() const throw();

				~BadInput();
		};
};

std::ostream&	operator<<(std::ostream& os, const BitcoinExchange& btc);

#endif
