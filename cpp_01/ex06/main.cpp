/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 23:14:53 by caalbert          #+#    #+#             */
/*   Updated: 2024/01/29 23:15:12 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(int argc, char** argv) {
	if (argc == 2) {
		Harl harl;
		harl.complain(argv[1]);
	} else {
		std::cerr << "Usage: ./harlFilter [DEBUG/INFO/WARNING/ERROR]\n";
	}
	return 0;
}
