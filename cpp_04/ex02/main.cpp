/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:45:08 by caalbert          #+#    #+#             */
/*   Updated: 2024/02/10 20:51:53 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
	AAnimal* animals[4];

	for (int i = 0; i < 2; ++i) {
		animals[i] = new Dog();
	}

	for (int i = 2; i < 4; ++i) {
		animals[i] = new Cat();
	}

	std::cout << "\n\033[1;34mDemonstrating animal sounds: \033[0m" << std::endl;
	for (int i = 0; i < 4; ++i) {
		std::cout << animals[i]->getType() << " says ";
		animals[i]->makeSound();
	}

	std::cout << "\033[1;31m\nDeleting animals:\033[0m" << std::endl;
	for (int i = 0; i < 4; ++i) {
		delete animals[i];
	}

	return 0;
}
