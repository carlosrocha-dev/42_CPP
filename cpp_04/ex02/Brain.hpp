/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 23:49:26 by caalbert          #+#    #+#             */
/*   Updated: 2024/02/09 23:49:34 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {
public:
	std::string ideas[100];

	Brain();
	Brain(const Brain& other);
	Brain& operator=(const Brain& other);
	~Brain();
};

#endif
