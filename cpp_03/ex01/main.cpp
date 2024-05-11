/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:51:58 by caalbert          #+#    #+#             */
/*   Updated: 2024/02/03 22:52:31 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
	ClapTrap clapTrap("Clappy");
	ScavTrap scavTrap("Scavvy");

	clapTrap.attack("Enemy");
	scavTrap.attack("Another Enemy");

	clapTrap.takeDamage(5);
	scavTrap.takeDamage(20);

	clapTrap.beRepaired(5);
	scavTrap.beRepaired(20);

	scavTrap.guardGate();

	return (0);
}
