/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:32:47 by locharve          #+#    #+#             */
/*   Updated: 2024/12/17 14:36:49 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FONCTIONS_HPP
# define FONCTIONS_HPP

# include <cstdlib>
# include <ctime>
# include <iostream>

# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

Base*	generate();
void	identify(Base* p);
void	identify(Base& p);

#endif