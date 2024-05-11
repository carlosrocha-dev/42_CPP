/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 22:14:20 by caalbert          #+#    #+#             */
/*   Updated: 2024/01/31 13:36:51 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main(void) {
	int N;

	N = 5;
	Zombie* horde = zombieHorde(N, "\033[2;37mHordeZombie\033[0m");

	if (!horde) {
		std::cerr << "\033[1;31mFailed to create zombie horde\033[0m" << std::endl;
		return 1;
	}

	for (int i = 0; i < N; ++i) {
		horde[i].announce();
	}

	delete[] horde;
	return (0);
}
