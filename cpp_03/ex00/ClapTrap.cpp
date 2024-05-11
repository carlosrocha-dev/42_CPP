/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:10:25 by caalbert          #+#    #+#             */
/*   Updated: 2024/02/03 22:10:37 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(const std::string &name)
	: name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap " << this->name << " is born!" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->name << " is destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string &target) {
	if (this->energyPoints > 0 && this->hitPoints > 0) {
		std::cout << "ClapTrap " << this->name << " attacks " << target
				<< ", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints--;
	} else {
		std::cout << "ClapTrap " << this->name << " cannot attack due to insufficient energy or health." << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->hitPoints > amount) {
		this->hitPoints -= amount;
		std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
	} else {
		this->hitPoints = 0;
		std::cout << "ClapTrap " << this->name << " is out of hit points and can't take more damage!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->energyPoints > 0) {
		this->hitPoints += amount;
		this->energyPoints--;
		std::cout << "ClapTrap " << this->name << " repairs itself, regaining " << amount << " hit points!" << std::endl;
	} else {
		std::cout << "ClapTrap " << this->name << " cannot repair due to insufficient energy." << std::endl;
	}
}
