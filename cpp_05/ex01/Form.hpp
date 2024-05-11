/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:52:35 by caalbert          #+#    #+#             */
/*   Updated: 2024/02/26 11:20:26 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		std::string const	_name;
		bool				_signed;
		size_t const		_gradeToSign;
		size_t const		_gradeToExecute;
	public:
		Form();
		explicit Form(std::string name, size_t gradeToSign, size_t gradeToExecute);
		Form(Form const &src);
		~Form();

		Form &operator=(Form const &rhs);

		std::string	getName() const;
		bool		getSigned() const;
		size_t		getGradeToSign() const;
		size_t		getGradeToExecute() const;
		void		beSigned(Bureaucrat const &bureaucrat);
		class GradeTooHighException : public std::exception {
		public:
			const char* what(void) const throw();
		};

		class GradeTooLowException : public std::exception {
		public:
			const char* what(void) const throw();
		};
};

std::ostream &operator<<(std::ostream &out, Form const &rhs);

#endif
