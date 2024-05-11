/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:23:10 by caalbert          #+#    #+#             */
/*   Updated: 2024/01/23 17:16:25 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string phonenumber;
	std::string darkestsecret;

public:
	void setInfo(const std::string& fname, const std::string& lname,
				const std::string& nname, const std::string& phone,
				const std::string& secret);
	void displayContact() const;
	void displayShort(int index) const;

private:
	std::string truncate(const std::string& str) const;
};

#endif
