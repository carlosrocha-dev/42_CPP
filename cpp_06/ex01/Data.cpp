/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:33:35 by caalbert          #+#    #+#             */
/*   Updated: 2024/02/28 09:36:38 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

/**
 * @brief Construct a new Data:: Data object
 *
 */
Data::Data()
{
	this->_name = "default";
	this->_len = 0;
	this->_height = 0;
}
Data::Data(std::string name, int len, int height)
{
	this->_name = name;
	this->_len = len;
	this->_height = height;
}

Data::~Data()
{
}

Data::Data(Data const &src)
{
	*this = src;
}

Data &Data::operator=(Data const &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_len = rhs._len;
		this->_height = rhs._height;
	}
	return (*this);
}

std::string Data::getName()
{
	return (this->_name);
}

int Data::getLen()
{
	return (this->_len);
}

int Data::getHeight()
{
	return (this->_height);
}

void Data::setLen(int len)
{
	this->_len = len;
}

void Data::setHeight(int height)
{
	this->_height = height;
}

void Data::setName(std::string name)
{
	this->_name = name;
}

double Data::calcIMC() {
	if (this->_height <= 0)
		return -1;
	double heightInMeters = this->_height;
	return (this->_len / (heightInMeters * heightInMeters));
}

