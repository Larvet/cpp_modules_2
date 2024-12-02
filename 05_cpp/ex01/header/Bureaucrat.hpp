/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:00:10 by locharve          #+#    #+#             */
/*   Updated: 2024/12/02 13:42:16 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
# include "Form.hpp"

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

		void	signForm(Form& f);

		~Bureaucrat();

		class	GradeTooHighException: public std::exception {
			public:
				void	constructException(std::string name);
				void	incrementException(std::string name);
		};
		class	GradeTooLowException: public std::exception {
			public:
				void	constructException(std::string name);
				void	decrementException(std::string name);
		};
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b);

#endif