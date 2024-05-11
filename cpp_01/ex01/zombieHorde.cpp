/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 22:13:38 by caalbert          #+#    #+#             */
/*   Updated: 2024/02/01 02:35:41 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
	Zombie* horde = new (std::nothrow) Zombie[N];
	if (!horde) return NULL;

	for (int i = 0; i < N; ++i) {
		new (&horde[i]) Zombie(name);
	}

	return horde;
}
