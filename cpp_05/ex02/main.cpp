/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:18:02 by caalbert          #+#    #+#             */
/*   Updated: 2024/02/26 11:01:37 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";

int main(void) {
	{
		Bureaucrat b1 = Bureaucrat("b1", 1);
		Bureaucrat b2 = Bureaucrat("b2", 150);

		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;

		try {
			b1.incrementGrade();
		} catch (std::exception& e) {
			std::cout << RED << "Error: " << e.what() << RESET << std::endl;
		}

		try {
			b2.decrementGrade();
		} catch (std::exception& e) {
			std::cout << RED << "Error: " << e.what() << RESET << std::endl;
		}

		std::cout << GREEN << b1 << RESET << std::endl;
		std::cout << GREEN << b2 << RESET << std::endl;
	}

	std::cout << "---------------------" << std::endl;


	{
		RobotomyRequestForm f2("Robot");
		Bureaucrat b1 = Bureaucrat("b1", 1);
		b1.signForm(f2);
		b1.executeForm(f2);
	}

	{
		PresidentialPardonForm f3("Mercy");
		Bureaucrat b1 = Bureaucrat("b1", 1);
		b1.signForm(f3);
		b1.executeForm(f3);
	}


	std::cout << "---------------------" << std::endl;
	std::cout << "\n\n" << std::endl;

	{
		ShrubberyCreationForm f1("File");
		Bureaucrat b1 = Bureaucrat("b1", 1);
		b1.signForm(f1);
		b1.executeForm(f1);

		std::cout << "\n\n" << std::endl;
		//NOTE: Read file
		std::ifstream ifs("File_shrubbery");
		std::string content((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
		std::cout << content << std::endl;
	}

	return 0;
}
