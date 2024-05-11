/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:23:45 by caalbert          #+#    #+#             */
/*   Updated: 2024/01/28 18:06:13 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : contactCount(0) {
}

PhoneBook::~PhoneBook() {
}

void PhoneBook::addContact(const Contact& contact) {
	if (contactCount < 8)
		contacts[contactCount++] = contact;
	else {
		for (int i = 0; i < 7; ++i)
			contacts[i] = contacts[i + 1];
		contacts[7] = contact;
	}
}

void PhoneBook::displayContacts() const {
	for (int i = 0; i < contactCount; ++i)
		contacts[i].displayShort(i);
}

bool PhoneBook::displayContactInfo(int index) const {
	if (index >= 0 && index < contactCount){
		contacts[index].displayContact();
		return true;
	}
	else
		return false;
}
