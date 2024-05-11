/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 00:28:36 by caalbert          #+#    #+#             */
/*   Updated: 2024/02/26 10:47:34 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

const std::string Intern::_forms[3] = {
	"shrubbery creation",
	"robotomy request",
	"presidential pardon"
};

AForm* (*Intern::_formFunc[3])(std::string) = {
	&Intern::makeShrubbery,
	&Intern::makeRobotomy,
	&Intern::makePresidential
};

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(Intern const &src) {
	*this = src;
}

Intern &Intern::operator=(Intern const &rhs) {
	if (this != &rhs)
		*this = rhs;
	return *this;
}

AForm *Intern::makeShrubbery(std::string target)  {
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeRobotomy(std::string target)  {
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makePresidential(std::string target)  {
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string form, std::string target) {
	for (int i = 0; i < 3; i++) {
		if (!form.compare(_forms[i])) {
			std::cout << "Intern creates " << form << std::endl;
			return (_formFunc[i](target));
		}
	}
	std::cout << "Intern can't create " << form << std::endl;
	return (NULL);
}
