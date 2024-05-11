/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:20:19 by caalbert          #+#    #+#             */
/*   Updated: 2024/01/30 22:36:47 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *newZombie(std::string name);
void randomChump(std::string name);

int main(void) {
	Zombie *heapZombie = newZombie("\033[1;34mHeapZombie\033[0m");
	heapZombie->announce();

	randomChump("\033[1;35mStackZombie\033[0m");

	delete heapZombie;
	return (0);
}
