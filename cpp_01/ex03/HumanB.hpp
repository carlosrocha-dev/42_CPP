/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:02:56 by caalbert          #+#    #+#             */
/*   Updated: 2024/01/29 17:03:26 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class HumanB {
private:
	std::string name;
	Weapon* weapon;

public:
	HumanB(std::string name);
	void setWeapon(Weapon& weapon);
	void attack() const;
};

#endif
