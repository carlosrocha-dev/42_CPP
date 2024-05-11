/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:00:55 by caalbert          #+#    #+#             */
/*   Updated: 2024/01/29 17:01:34 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	#ifndef HUMANA_HPP
	#define HUMANA_HPP

	#include "Weapon.hpp"
	#include <string>

	class HumanA {
	private:
		std::string name;
		Weapon& weapon;

	public:
		HumanA(std::string name, Weapon& weapon);
		void attack() const;
	};

	#endif
