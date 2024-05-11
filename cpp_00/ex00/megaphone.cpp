/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:40:09 by caalbert          #+#    #+#             */
/*   Updated: 2024/01/23 14:17:06 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

static void toUpperStr(const char* cstr) {
	for (int i = 0; cstr[i] != '\0'; i++) {
		if (cstr[i] >= 'a' && cstr[i] <= 'z')
			std::cout << (char)(cstr[i] - ('a' - 'A'));
		else
			std::cout << cstr[i];
	}
}

void	processArguments(int argc, char *argv[]) {
	for (int i = 1; i < argc; i++) {
		toUpperStr(argv[i]);
	}
}

void	printNoise() {
	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
}

int	main(int argc, char *argv[])
{
	if (argc <= 1)
		printNoise();
	else
		processArguments(argc, argv);
	std::cout << std::endl;
	return 0;
}
