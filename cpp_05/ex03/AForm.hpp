/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:52:35 by caalbert          #+#    #+#             */
/*   Updated: 2024/02/26 10:48:58 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		std::string const	_name;
		bool				_signed;
		size_t const		_gradeToSign;
		size_t const		_gradeToExecute;
	public:
		virtual void execute(Bureaucrat const &executor) const = 0;
		AForm();
		AForm(std::string name, size_t gradeToSign, size_t gradeToExecute);
		AForm(AForm const &src);
		virtual ~AForm();
		AForm &operator=(AForm const &rhs);

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

		class FormNotSignedException : public std::exception {
		public:
			const char* what(void) const throw();
		};
};

std::ostream &operator<<(std::ostream &out, AForm const &rhs);

#endif