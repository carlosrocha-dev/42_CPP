/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 20:29:26 by caalbert          #+#    #+#             */
/*   Updated: 2024/01/29 20:30:48 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

void Harl::debug() {
	std::cout << "\033[36m[DEBUG]\033[0m I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
}

void Harl::info() {
	std::cout << "\033[32m[INFO]\033[0m I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void Harl::warning() {
	std::cout << "\033[33m[WARNING]\033[0m I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
}

void Harl::error() {
	std::cout << "\033[31m[ERROR]\033[0m This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain(std::string level) {
	void (Harl::*actions[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++) {
		if (level == levels[i]) {
			switch (i) {
				case 0:
					(this->*actions[0])();
				case 1:
					(this->*actions[1])();
				case 2:
					(this->*actions[2])();
				case 3:
					(this->*actions[3])();
			}
			break;
		}
	}
}
