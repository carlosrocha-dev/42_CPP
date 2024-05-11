/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:53:31 by caalbert          #+#    #+#             */
/*   Updated: 2024/02/26 11:20:44 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(std::string name, size_t gradeToSign, size_t gradeToExecute) : _name(name) , _signed(false) , _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}


Form::Form(Form const & src) : _name(""), _signed(false), _gradeToSign(0) ,_gradeToExecute(0)
{
	*this = src;
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw Form::GradeTooLowException();
}


Form::~Form() {}

Form &Form::operator=(Form const & rhs) {
	if (this != &rhs) {
		const_cast<std::string&> (this->_name) = rhs.getName();
		this->_signed = rhs.getSigned();
		const_cast<size_t&>(this->_gradeToSign) = rhs.getGradeToSign();
		const_cast<size_t&>(this->_gradeToExecute) = rhs.getGradeToExecute();
	}
	return *this;
}

std::string	Form::getName() const {
	return _name;
}

bool		Form::getSigned() const {
	return _signed;
}

size_t		Form::getGradeToSign() const {
	return _gradeToSign;
}

size_t		Form::getGradeToExecute() const {
	return _gradeToExecute;
}

void		Form::beSigned(Bureaucrat const &bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	this->_signed = true;
}

const char* Form::GradeTooHighException::what(void) const throw() {
	return "Grade too high";
}

const char* Form::GradeTooLowException::what(void) const throw() {
	return "Grade too low";
}

std::ostream &operator<<(std::ostream &out, Form const &rhs) {
	out << rhs.getName() << (rhs.getSigned() ? " is signed" : " is not signed" )<< " and requires a grade of " << rhs.getGradeToSign() << " to sign and " << rhs.getGradeToExecute() << " to execute.";
	return (out);
}