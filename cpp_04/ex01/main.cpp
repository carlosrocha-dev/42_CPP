/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 23:53:59 by caalbert          #+#    #+#             */
/*   Updated: 2024/02/09 23:55:51 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
	const int numAnimals = 4;
	Animal* animals[numAnimals];

	for (int i = 0; i < numAnimals / 2; ++i) {
		animals[i] = new Dog();
	}
	for (int i = numAnimals / 2; i < numAnimals; ++i) {
		animals[i] = new Cat();
	}

	for (int i = 0; i < numAnimals; ++i) {
		std::cout << animals[i]->getType() << " makes a sound: ";
		animals[i]->makeSound();
	}

	Dog originalDog;
	Dog copyDog(originalDog);
	Cat originalCat;
	Cat copyCat(originalCat);
	
	for (int i = 0; i < numAnimals; ++i) {
		delete animals[i];
	}

	return 0;
}
