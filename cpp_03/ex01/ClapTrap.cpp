/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:50:43 by caalbert          #+#    #+#             */
/*   Updated: 2024/02/03 22:50:55 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(const std::string& name)
: name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap " << this->name << " constructed." << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->name << " destructed." << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (energyPoints == 0 || hitPoints == 0) {
		std::cout << "ClapTrap " << name << " has no energy or hit points to attack." << std::endl;
		return;
	}
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
	energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) {
	hitPoints = (amount >= hitPoints) ? 0 : (hitPoints - amount);
	std::cout << "ClapTrap " << name << " took " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (energyPoints == 0) {
		std::cout << "ClapTrap " << name << " has no energy to repair." << std::endl;
		return;
	}
	hitPoints += amount;
	energyPoints--;
	std::cout << "ClapTrap " << name << " repaired itself, recovering " << amount << " hit points!" << std::endl;
}
