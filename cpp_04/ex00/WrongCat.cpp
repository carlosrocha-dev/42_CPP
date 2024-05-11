/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 20:39:24 by caalbert          #+#    #+#             */
/*   Updated: 2024/02/09 23:26:48 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
	type = "WrongCat";
	std::cout << "WrongCat constructed." << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructed." << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "WrongCat makes a meow... but it's the wrong way!" << std::endl;
}
