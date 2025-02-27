/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:38:31 by kbrauer           #+#    #+#             */
/*   Updated: 2025/02/27 18:04:18 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
	AForm("RobotomyRequestForm", 72, 45), _target("noTarget") {
}
RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	AForm("RobotomyRequestForm", 72, 45), _target(target) {
}
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& original) :
	AForm("RobotomyRequestForm", 72, 45), _target(original._target) {
}
RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& R) {
	if (this != &R) {
		this->_target = R._target;
	}
	return *this;
}
RobotomyRequestForm::~RobotomyRequestForm() {
}

void RobotomyRequestForm::myExe() const {
    int n = time(0);
	std::cout << "Drilling Noises" << std::endl;
	if (n % 2 == 0)
		std::cout << this->_target << " has been robotomized" << std::endl;
	else
		std::cout << this->_target << "'s robotomization failed" << std::endl;
}
