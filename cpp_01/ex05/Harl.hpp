/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:52:37 by caalbert          #+#    #+#             */
/*   Updated: 2024/01/29 23:23:14 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

# include <string>

# define RESET		"\033[0m"
# define RED		"\033[31m"
# define YELLOW		"\033[33m"
# define GREEN		"\033[32m"
# define BLUE		"\033[34m"

class Harl {
private:
	void debug();
	void info();
	void warning();
	void error();

public:
	void complain(std::string level);
};

#endif
