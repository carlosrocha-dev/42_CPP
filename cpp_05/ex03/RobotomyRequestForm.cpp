/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:37:40 by caalbert          #+#    #+#             */
/*   Updated: 2024/02/26 10:45:56 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("robotomy request", 72, 45) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src) {
	*this = src;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("robotomy request", 72, 45), _target(target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs) {
	(void)rhs;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (this->getSigned() != true)
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > this->getGradeToExecute())
			throw AForm::GradeTooLowException();
	else if ((1 + (std::rand() % 2)) == 1)
		std::cout << "Drillllllllll noises " << this->getTarget()
			<< " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Drillllllllll noises " << this->getTarget()
			<<" robotomized failed!" << std::endl;
}

std::string	RobotomyRequestForm::getTarget() const {
	return _target;
}