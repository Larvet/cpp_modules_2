#include <iostream>
#include <stdexcept>

class	Bureaucrat {
	private:
		const std::string	_name;
		unsigned int		_grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, unsigned int grade);
		Bureaucrat(const Bureaucrat& src);
		Bureaucrat&	operator=(const Bureaucrat& src);

		const std::string	getName() const;
		unsigned int		getGrade() const;

		void	incrementGrade();
		void	decrementGrade();

		~Bureaucrat();

		class	GradeTooHighException: public std::exception {
			public:
				void printException(std::string name);
		};
		class	GradeTooLowException: public std::exception {
			public:
				void printException(std::string name);
		};
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b);