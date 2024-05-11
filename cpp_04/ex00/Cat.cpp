/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 20:37:28 by caalbert          #+#    #+#             */
/*   Updated: 2024/02/04 20:37:46 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	type = "Cat";
	std::cout << "Cat constructed." << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat destructed." << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}
