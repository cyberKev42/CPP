/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:38:33 by kbrauer           #+#    #+#             */
/*   Updated: 2025/02/27 18:09:41 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
	AForm("PresidentialPardonForm", 25, 5), _target("noTarget") {
}
PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	AForm("PresidentialPardonForm", 25, 5), _target(target) {
}
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& original) :
	AForm("PresidentialPardonForm", 25, 5), _target(original._target) {
}
PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm& P) {
	if (this != &P) {
		this->_target = P._target;
	}
	return *this;
}
PresidentialPardonForm::~PresidentialPardonForm() {
}

void PresidentialPardonForm::myExe() const {
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
