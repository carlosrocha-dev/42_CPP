/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:18:02 by caalbert          #+#    #+#             */
/*   Updated: 2024/02/12 21:09:54 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";

int main(void) {
	{
		// NOTE: test for Bureaucrat
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
		// NOTE: test for Form
		Form f1 = Form("f1", 1, 1);
		Form f2 = Form("f2", 149, 150);

		std::cout << GREEN << f1 << RESET << std::endl;
		std::cout << GREEN << f2 << RESET << std::endl;

		try {
			Bureaucrat("b1", 1).signForm(f1);
		} catch (std::exception& e) {
			std::cout << RED << "Error: " << e.what() << RESET << std::endl;
		}

		try {
			Bureaucrat("b2", 150).signForm(f2);
		} catch (std::exception& e) {
			std::cout << RED << "Error: " << e.what() << RESET << std::endl;
		}

		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;
	}

	return 0;
}
