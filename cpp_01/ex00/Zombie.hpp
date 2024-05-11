/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:25:55 by caalbert          #+#    #+#             */
/*   Updated: 2024/01/30 13:31:38 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

const std::string RESET = "\033[0m";
const std::string RED = "\033[1;31m";
const std::string YELLOW = "\033[1;33m";
const std::string GREEN = "\033[1;32m";
const std::string BLUE = "\033[1;34m";

class Zombie {
private:
	std::string _name;

public:
	Zombie(std::string name);
	~Zombie(void);
	void announce(void);
};

#endif
