/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:03:23 by locharve          #+#    #+#             */
/*   Updated: 2024/12/10 14:39:38 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>

class	Bureaucrat;

class	AForm {
	private:
		const std::string	_name;
		bool				_signed;
		const unsigned int	_gradeToSign;
		const unsigned int	_gradeToExec;
	public:
		AForm();
		AForm(std::string name, bool s, unsigned int gradeS, unsigned int gradeE);
		AForm(const AForm& src);
		AForm&	operator=(const AForm& src);

		unsigned int	testGrade(unsigned int g) const;

		void	setSigned(unsigned int s);

		const std::string	getName() const;
		bool				getSigned() const;
		unsigned int	getGradeToSign() const;
		unsigned int	getGradeToExec() const;

		void	beSigned(Bureaucrat& b);

		virtual std::string	getTarget() const = 0;
		virtual void	doExecute() const = 0;
		void	execute(Bureaucrat const & executor) const;

		virtual ~AForm();

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
		class	NotSignedException: public std::exception {
			public:
				const char*	what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& os, const AForm& f);

#endif