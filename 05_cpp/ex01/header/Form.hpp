/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:03:23 by locharve          #+#    #+#             */
/*   Updated: 2024/11/18 15:16:30 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
//# include "Bureaucrat.hpp"
class	Bureaucrat;

class	Form {
	private:
		const std::string	_name;
		bool				_signed;
		const unsigned int	_gradeToSign;
		const unsigned int	_gradeToExec;
	public:
		Form();
		Form(const Form& src);
		Form&	operator=(const Form& src);

		unsigned int	testGrade(unsigned int g) const;

		const std::string	getName() const;
		bool				getSigned() const;
		unsigned int	getGradeToSign() const;
		unsigned int	getGradeToExec() const;

		void	beSigned(Bureaucrat& b);

		~Form();

		class	GradeTooHighException: public std::exception {
			public:
				void	constructException(const Form& f);
		};
		class	GradeTooLowException: public std::exception {
			public:
				void	constructException(const Form& f);
				void	signException(Bureaucrat& b, Form& f);
		};
};

std::ostream&	operator<<(std::ostream& os, const Form& f);

#endif