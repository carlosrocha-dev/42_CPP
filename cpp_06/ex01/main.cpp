/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:33:55 by caalbert          #+#    #+#             */
/*   Updated: 2024/02/28 09:37:59 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
# include "Data.hpp"
# include "Serializer.hpp"

int main(void)
{
	Data *data = new Data("Carlos", 183, 94);
	uintptr_t ptr = Serializer::serialize(data);

	std::cout << "Name: " << data->getName() << std::endl;
	std::cout << "Len: " << data->getLen() << std::endl;
	std::cout << "Height: " << data->getHeight() << std::endl;
	std::cout << "IMC: " << data->calcIMC() << std::endl;
	std::cout << "is storage in :" << data << std::endl;
	std::cout << "the serializer number is:" << ptr<< std::endl;
	std::cout << "the return from the deserializer is:" << Serializer::deserialize(ptr) << std::endl;
}
