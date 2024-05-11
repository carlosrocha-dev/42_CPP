/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:23:00 by caalbert          #+#    #+#             */
/*   Updated: 2024/01/23 17:16:19 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

void Contact::setInfo(const std::string& fname, const std::string& lname,
					const std::string& nname, const std::string& phone,
					const std::string& secret) {
	firstname = fname;
	lastname = lname;
	nickname = nname;
	phonenumber = phone;
	darkestsecret = secret;
}

void Contact::displayContact() const {
	std::cout << "First Name: " << firstname << std::endl;
	std::cout << "Last Name: " << lastname << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone Number: " << phonenumber << std::endl;
	std::cout << "Darkest Secret: " << darkestsecret << std::endl;
}

void Contact::displayShort(int index) const {
	std::cout << std::right << std::setw(10) << index << "|";
	std::cout << std::right << std::setw(10) << truncate(firstname) << "|";
	std::cout << std::right << std::setw(10) << truncate(lastname) << "|";
	std::cout << std::right << std::setw(10) << truncate(nickname) << std::endl;
}

std::string Contact::truncate(const std::string& str) const {
	if (str.length() > 9)
		return str.substr(0, 9) + ".";
	else
		return str;
}
