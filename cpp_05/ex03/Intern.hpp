/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 00:28:49 by caalbert          #+#    #+#             */
/*   Updated: 2024/02/26 10:47:09 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include <fstream>
# include "AForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{

public:
	Intern();
	~Intern();
	Intern(Intern const &src);
	Intern &operator=(Intern const &rhs);
	AForm *makeForm(std::string form, std::string target);

private:
	static AForm *makeShrubbery(std::string target) ;
	static AForm *makeRobotomy(std::string target) ;
	static AForm *makePresidential(std::string target) ;
	static const std::string _forms[3];
	static AForm* (*_formFunc[3])(std::string);
};



#endif