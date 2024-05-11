/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:52:48 by caalbert          #+#    #+#             */
/*   Updated: 2024/01/29 23:24:02 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

void Harl::debug() {
	std::cout << BLUE << "DEBUG: " << RESET << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info() {
	std::cout << GREEN << "INFO: " << RESET << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning() {
	std::cout << YELLOW << "WARNING: " << RESET << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error() {
	std::cout << RED << "ERROR: " << RESET << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
	void (Harl::*commentFunction)();

	if (level == "DEBUG") {
		commentFunction = &Harl::debug;
	} else if (level == "INFO") {
		commentFunction = &Harl::info;
	} else if (level == "WARNING") {
		commentFunction = &Harl::warning;
	} else if (level == "ERROR") {
		commentFunction = &Harl::error;
	} else {
		std::cout << "Unknown comment level: " << level << std::endl;
		return;
	}

	(this->*commentFunction)();
}
