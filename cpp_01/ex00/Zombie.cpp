/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:25:37 by caalbert          #+#    #+#             */
/*   Updated: 2024/01/30 22:38:21 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name) : _name(name) {}

Zombie::~Zombie() {
	std::cout << _name << RED << ": is destroyed" << RESET << std::endl;
}

void Zombie::announce(void) {
	std::cout << _name << GREEN << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}
