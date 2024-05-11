/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:18:02 by caalbert          #+#    #+#             */
/*   Updated: 2024/02/10 17:18:09 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main() {
	try {
		Bureaucrat high("High", 1);
		Bureaucrat low("Low", 150);

		std::cout << high << std::endl;
		std::cout << low << std::endl;

		high.incrementGrade();
		low.decrementGrade();
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
