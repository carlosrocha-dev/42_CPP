/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:37:13 by caalbert          #+#    #+#             */
/*   Updated: 2024/02/26 11:04:58 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("shrubbery creation", 145, 137) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src) {
	*this = src;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("shrubbery creation", 145, 137), _target(target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs) {
	(void)rhs;
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (this->getSigned() == true) {
		if (executor.getGrade() <= this->getGradeToExecute()) {
			std::ofstream fd;
			std::string filename = this->getTarget() + "_shrubbery";
			fd.open(filename.c_str(), std::ios::out | std::ios::trunc);
			std::string tree =
			"          %%%,%%%%%%%\n"
			"           ,'%% \\-*%%%%%%%\n"
			"     ;%%%%%*%   _%%%%\"\n"
			"      ,%%%       \\(_.*%%%%.\n"
			"      % *%%, ,%%%%*(    '\n"
			"    %^     ,*%%% )\\|,%%*%,_\n"
			"         *%    \\/ #).-\"*%%*\n"
			"             _.) ,/ *%,\n"
			"     _________/)#(____________\n";
			fd << tree;
			fd.close();
		}
		else
			throw AForm::GradeTooLowException();
	} else {
		throw AForm::FormNotSignedException();
	}
}

std::string	ShrubberyCreationForm::getTarget() const {
	return _target;
}