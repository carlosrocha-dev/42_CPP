/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 23:04:58 by caalbert          #+#    #+#             */
/*   Updated: 2024/02/03 23:05:15 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void) {
	ClapTrap clap("Clappy");
	ScavTrap scav("Scavvy");
	FragTrap frag("Fraggy");

	clap.attack("Enemy");
	scav.guardGate();
	frag.highFivesGuys();

	return (0);
}
