/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 20:23:22 by caalbert          #+#    #+#             */
/*   Updated: 2024/02/04 20:23:59 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("") {
	std::cout << "Animal constructed." << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal destructed." << std::endl;
}

void Animal::makeSound() const {
	std::cout << "Animal makes a sound." << std::endl;
}

std::string Animal::getType() const {
	return type;
}
