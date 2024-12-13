/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:03:23 by locharve          #+#    #+#             */
/*   Updated: 2024/12/09 16:22:20 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

class	Bureaucrat;

class	Form {
	private:
		const std::string	_name;
		bool				_signed;
		const unsigned int	_gradeToSign;
		const unsigned int	_gradeToExec;
	public:
		Form();
		Form(std::string name, bool s, unsigned int gradeS, unsigned int gradeE);
		Form(const Form& src);
		Form&	operator=(const Form& src);

		unsigned int	testGrade(unsigned int g) const;

		const std::string	getName() const;
		bool				getSigned() const;
		unsigned int	getGradeToSign() const;
		unsigned int	getGradeToExec() const;

		void	beSigned(Bureaucrat& b);

		~Form();

		class	ConstructGradeTooHighException: public std::exception {
			public:
				const char*	what() const throw();
		};
		class	ConstructGradeTooLowException: public std::exception {
			public:
				const char*	what() const throw();
		};
		class	GradeTooLowException: public std::exception {
			public:
				const char*	what() const throw();
		};
		class	AlreadySignedException: public std::exception {
			public:
				const char*	what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& os, const Form& f);

#endif