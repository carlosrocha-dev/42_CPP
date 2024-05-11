/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:24:13 by caalbert          #+#    #+#             */
/*   Updated: 2024/01/28 18:53:02 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string.h>
#include <sstream> 

void addContact(PhoneBook &phonebook);
void searchContact(PhoneBook &phonebook);

int main(void) {
    PhoneBook phonebook;
    std::string command;

    while (true) {
        std::cout << "\033[1;32mEnter command (ADD, SEARCH, EXIT): \033[0m";
        if (!std::getline(std::cin, command)) {
            continue;
        }

        if (command.empty()) {
            std::cout << "\033[1;31mCommand cannot be empty\033[0m" << std::endl;
            continue;
        }

        if (command == "ADD")
            addContact(phonebook);
        else if (command == "SEARCH")
            searchContact(phonebook);
        else if (command == "EXIT") {
            std::cout << "\033[1;34mBYE, BYE!\033[0m" << std::endl;
            break;
        } else
            std::cout << "\033[1;31mInvalid command\033[0m" << std::endl;
    }

    return 0;
}

void addContact(PhoneBook &phonebook) {
	std::string fname, lname, nname, phone, secret;

	std::cout << "\033[1;30mEnter first name: \033[0m";
	while (std::getline(std::cin, fname) && fname.empty()) {
		std::cout << "\033[1;31mFirst name cannot be empty.\033[0m\033[1;30m Enter first name: \033[0m";
	}

	std::cout << "\033[1;30mEnter last name: \033[0m";
	while (std::getline(std::cin, lname) && lname.empty()) {
		std::cout << "\033[1;301mLast name cannot be empty.\033[0m\033[1;30m Enter last name: \033[0m";
	}

	std::cout << "\033[1;30mEnter nickname: \033[0m";
	while (std::getline(std::cin, nname) && nname.empty()) {
		std::cout << "\033[1;31mNickname cannot be empty.\033[0m\033[1;30m Enter nickname: \033[0m";
	}

	std::cout << "\033[1;30mEnter phone number: \033[0m";
	while (std::getline(std::cin, phone) && phone.empty()) {
		std::cout << "\033[1;31mPhone number cannot be empty.\033[0m\033[1;30m Enter phone number: \033[0m";
	}

	std::cout << "\033[1;30mEnter darkest secret: \033[0m";
	while (std::getline(std::cin, secret) && secret.empty()) {
		std::cout << "\033[1;31mDarkest secret cannot be empty.\033[0m\033[1;30m Enter darkest secret: \033[0m";
	}

	Contact newContact;
	newContact.setInfo(fname, lname, nname, phone, secret);
	phonebook.addContact(newContact);

	std::cout << "\n\033[1;32mContact added successfully!\033[0m" << std::endl;
	std::cout << "First Name: " << fname  << std::endl;
	std::cout << "Last Name: " << lname << std::endl;
	std::cout << "Nickname: " << nname << std::endl;
	std::cout << "Phone Number: " << phone << std::endl;
	std::cout << "Darkest Secret: " << secret << std::endl;
}

void searchContact(PhoneBook &phonebook) {
	phonebook.displayContacts();
	std::cout << "\033[1;30mEnter index of contact to display (0-7): \033[0m";
	std::string line;
	int index;

	while (true) {
		std::getline(std::cin, line);
		std::stringstream ss(line);
		if (ss >> index && !(ss >> line)) {
			if (index >= 0 && index <= 7) {
				if (phonebook.displayContactInfo(index)) {
					break;
				} else {
					std::cout << "\033[1;31mInvalid index. Returning to main menu.\033[0m\n";
					return;
				}
			} else {
				std::cout << "\033[1;31mPlease enter a number between 0 and 7: \033[0m";
			}
		} else {
			std::cout << "\033[1;31mInvalid input. Please enter a number between 0 and 7: \033[0m";
		}
	}
}