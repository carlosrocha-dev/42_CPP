/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:41:30 by caalbert          #+#    #+#             */
/*   Updated: 2024/02/10 12:41:42 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal(), brain(new Brain()) {
	this->type = "Cat";
	std::cout << "Cat created" << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other), brain(new Brain(*other.brain)) {
	std::cout << "Cat copy created" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		AAnimal::operator=(other);
		*brain = *other.brain;
	}
	return *this;
}

Cat::~Cat() {
	delete brain;
	std::cout << "Cat destroyed" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}
