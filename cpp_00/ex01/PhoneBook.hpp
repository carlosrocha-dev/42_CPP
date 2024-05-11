/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:23:28 by caalbert          #+#    #+#             */
/*   Updated: 2024/01/28 18:20:23 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include "Contact.hpp"

# define MAX_COMMAND_LEN 100

class PhoneBook {
private:
	Contact contacts[8];
	int contactCount;

public:
	PhoneBook();
	~PhoneBook();

	void addContact(const Contact& contact);
	void displayContacts() const;
	bool displayContactInfo(int index) const;
};

#endif
