/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:38:15 by caalbert          #+#    #+#             */
/*   Updated: 2024/02/26 10:46:42 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	#include "PresidentialPardonForm.hpp"

	PresidentialPardonForm::PresidentialPardonForm() : AForm("presidential pardon", 25, 5) {}

	PresidentialPardonForm::~PresidentialPardonForm() {}

	PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm(src) {
		*this = src;
	}

	PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("presidential pardon", 25, 5), _target(target) {}

	PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs) {
		(void)rhs;
		return (*this);
	}

	void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
		if (this->getSigned() != true)
			throw AForm::FormNotSignedException();
		else if (executor.getGrade() > this->getGradeToExecute())
				throw AForm::GradeTooLowException();
		else
			std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}

	std::string	PresidentialPardonForm::getTarget() const {
		return _target;
	}