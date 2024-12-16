/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:19:39 by locharve          #+#    #+#             */
/*   Updated: 2024/12/16 16:21:10 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

class	Base {
	public:
		virtual	~Base();

		Base*	generate();
		void	identify(Base* p);
		void	identify(Base& p);
};

#endif