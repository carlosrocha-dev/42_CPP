/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 20:28:23 by caalbert          #+#    #+#             */
/*   Updated: 2024/02/04 20:28:55 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	type = "Dog";
	std::cout << "Dog constructed." << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog destructed." << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Woof!" << std::endl;
}
