/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:09:33 by caalbert          #+#    #+#             */
/*   Updated: 2024/02/03 22:10:07 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
	ClapTrap clapTrap("Clappy");

	clapTrap.attack("Enemy");
	clapTrap.takeDamage(8);
	clapTrap.beRepaired(5);

	return (0);
}
