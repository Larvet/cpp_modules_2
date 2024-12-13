/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:07:03 by locharve          #+#    #+#             */
/*   Updated: 2024/12/13 15:44:29 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

class	Intern {
	public:
		Intern();
		Intern(const Intern& src);
		Intern&	operator=(const Intern& src);
		~Intern();
		
		AForm*	makeForm(std::string formName, std::string target);
		
		class	FormDoesntExist: public std::exception {
			public:
				const char*	what() const throw();
		};
};

#endif