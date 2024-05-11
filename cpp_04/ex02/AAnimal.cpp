/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:35:38 by caalbert          #+#    #+#             */
/*   Updated: 2024/02/10 15:01:08 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

//NOTE: AAnimal is an abstract class,
//so it doesn't need a default constructor
AAnimal::AAnimal() : type("Undefined") {
	std::cout << "\033[1;32mAAnimal created\033[0m" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : type(other.type) {
	std::cout << "AAnimal copy created" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destroyed" << std::endl;
}

std::string AAnimal::getType() const {
	return type;
}
