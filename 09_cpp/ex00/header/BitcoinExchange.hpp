#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <iostream>
# include <iomanip>
# include <string>
# include <fstream>
# include <exception>
# include <cstdlib>

# define WHITESPACES "\t\n\v\f\r "

class	StrException: public std::exception {
	protected:
		const std::string	_str;
	public:
		StrException(const std::string& str);
		const char*	what() const throw();

		virtual ~StrException() throw();
};

class	BitcoinExchange {
	private:
		std::map< std::string, std::string >	_dataBase;
	public:
		BitcoinExchange();
		BitcoinExchange(const char* const & fileName);
		BitcoinExchange(const BitcoinExchange& rhs);
		BitcoinExchange&	operator=(const BitcoinExchange& rhs);

		void	parseDataBase();
		void	readInputFile(const char* const & fileName);
		float	calculateResult(const std::string& date, const std::string& amount);

		const std::map< std::string, std::string >&	getDataBase() const;
		const std::string&	getMin() const;

		~BitcoinExchange();

		class	CannotOpenFile: public StrException {
			public:
				CannotOpenFile(std::string str);

				~CannotOpenFile() throw();
		};
		class	BadInput: public StrException {
			public:
				BadInput(std::string str);

				~BadInput() throw();
		};
		class	InvalidDate: public StrException {
			public:
				InvalidDate(std::string str);

				~InvalidDate() throw();
		};
		class	InvalidAmount: public StrException {
			public:
				InvalidAmount(std::string str);

				~InvalidAmount() throw();
		};
};

std::ostream&	operator<<(std::ostream& os, const BitcoinExchange& btc);

#endif
