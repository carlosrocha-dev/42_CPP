/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:18:02 by caalbert          #+#    #+#             */
/*   Updated: 2024/02/13 00:33:37 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string BLUE = "\033[34m";

int main(void) {
	Bureaucrat b1 = Bureaucrat("Trash boss Bender", 1);
	Intern someRandomIntern;

	{
		std::cout << BLUE << "*** Trying to make shrubbery creation form ***" << RESET << std::endl;
		AForm* form = someRandomIntern.makeForm("shrubbery creation", "Home");
		if (form) {
			b1.signForm(*form);
			b1.executeForm(*form);
			delete form;
		}
		std::cout << BLUE << "TEST SHRUBBERY CREATION FINISHED" << RESET << std::endl << std::endl;
	}

	{
		std::cout << BLUE << "*** Trying to make robotomy request form ***" << RESET << std::endl;
		AForm* form = someRandomIntern.makeForm("robotomy request", "Bender");
		if (form) {
			b1.signForm(*form);
			b1.executeForm(*form);
			delete form;
		}
		std::cout << BLUE << "TEST ROBOTOMY REQUEST FINISHED" << RESET << std::endl << std::endl;
	}

	{
		std::cout << BLUE << "*** Trying to make presidential pardon form ***" << RESET << std::endl;
		AForm* form = someRandomIntern.makeForm("presidential pardon", "Fry");
		if (form) {
			b1.signForm(*form);
			b1.executeForm(*form);
			delete form;
		}
		std::cout << BLUE << "TEST PRESIDENTIAL PARDON FINISHED" << RESET << std::endl << std::endl;
	}

	{
		std::cout << BLUE << "*** Trying to make some bullshit form ***" << RESET << std::endl;
		AForm* form = someRandomIntern.makeForm("some bullshit form", "Nowhere");
		if (!form) {
			std::cout << RED << "Intern could not create the form: some bullshit form" << RESET << std::endl;
		}
		std::cout << BLUE << "TEST INVALID FORM FINISHED" << RESET << std::endl;
	}

	return 0;
}
