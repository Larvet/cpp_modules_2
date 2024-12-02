/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:18:45 by locharve          #+#    #+#             */
/*   Updated: 2024/12/02 16:28:06 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():
	AForm("ShrubberyCreationForm", 0, 145, 137), _target("random") {
		std::cout << "+++++++ ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
	AForm("ShrubberyCreationForm", 0, 145, 137), _target(target) {
		std::cout << "+++++++ ShrubberyCreationForm string constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src):
	AForm(src.getName(), src.getSigned(), src.getGradeToSign(), src.getGradeToExec()),
	_target(src.getTarget()) {
		std::cout << "+++++++ ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src) {
	setSigned(src.getSigned());
	_target = src.getTarget();
	return (*this);
}

void	ShrubberyCreationForm::doExecute() const {
	std::string	filename(_target + "_shrubbery");
	std::ofstream	out;

	out.open(filename.c_str());
	out <<  "                                                         ." << std::endl
		<<	"                                              .         ;  " << std::endl
		<<	"                 .              .              ;%     ;;   " << std::endl
		<<	"                   ,           ,                :;%  %;   " << std::endl
		<<	"                    :         ;                   :;%;'     .,   " << std::endl
		<<	"           ,.        %;     %;            ;        %;'    ,;" << std::endl
		<<	"             ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl
		<<	"              %;       %;%;      ,  ;       %;  ;%;   ,%;' " << std::endl
		<<	"               ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl
		<<	"                `%;.     ;%;     %;'         `;%%;.%;'" << std::endl
		<<	"                 `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl
		<<	"                    `:%;.  :;bd%;          %;@%;'" << std::endl
		<<	"                      `@%:.  :;%.         ;@@%;'   " << std::endl
		<<	"                        `@%.  `;@%.      ;@@%;         " << std::endl
		<<	"                          `@%%. `@%%    ;@@%;        " << std::endl
		<<	"                            ;@%. :@%%  %@@%;       " << std::endl
		<<	"                              %@bd%%%bd%%:;     " << std::endl
		<<	"                                #@%%%%%:;;" << std::endl
		<<	"                                %@@%%%::;" << std::endl
		<<	"                                %@@@%(o);  . '         " << std::endl
		<<	"                                %@@@o%;:(.,'         " << std::endl
		<<	"                            `.. %@@@o%::;         " << std::endl
		<<	"                               `)@@@o%::;         " << std::endl
		<<	"                                %@@(o)::;        " << std::endl
		<<	"                               .%@@@@%::;         " << std::endl
		<<	"                               ;%@@@@%::;.          " << std::endl
		<<	"                              ;%@@@@%%:;;;. " << std::endl
		<<	"                          ...;%@@@@@%%:;;;;,.." << std::endl;
	out.close();
}

std::string	ShrubberyCreationForm::getTarget() const {
	return (_target);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "------- ShrubberyCreationForm destructor called" << std::endl;
}