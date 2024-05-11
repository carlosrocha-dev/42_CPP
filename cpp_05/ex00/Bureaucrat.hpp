/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:15:57 by caalbert          #+#    #+#             */
/*   Updated: 2024/02/26 11:24:23 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat {
	private:
		std::string const	_name;
		size_t				_grade;
	public:
		Bureaucrat();
		explicit Bureaucrat(std::string name, size_t grade);
		Bureaucrat(Bureaucrat const &src);
		~Bureaucrat();

		Bureaucrat &operator=(Bureaucrat const &rhs);

		std::string	getName() const;
		size_t		getGrade() const;
		void		incrementGrade();
		void		decrementGrade();
		class GradeTooHighException : public std::exception {
		public:
			const char* what(void) const throw();
		};

		class GradeTooLowException : public std::exception {
		public:
			const char* what(void) const throw();
		};
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &rhs);

#endif