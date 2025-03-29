/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:19:33 by kbrauer           #+#    #+#             */
/*   Updated: 2025/03/29 17:38:08 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}
Intern::Intern(Intern& original) {
	*this = original;
}
Intern& Intern::operator=(const Intern& I) {
	if (this != &I)
		return *this;
	return *this;
}
Intern::~Intern() {}

AForm* Intern::makeForm(std::string formName, std::string targetName) {
	
	std::string formNames[3] = { "shrubbery creation",
								 "robotomy request",
								 "presidential pardon" };
	int i;
	for (i = 0; i < 3; i++) {
		if (formNames[i] == formName)
			break;
	}
	if (i == 3)
		throw FormDoesNotExist();
	AForm* forms[3] = { new ShrubberyCreationForm(targetName),
						new RobotomyRequestForm(targetName),
						new PresidentialPardonForm(targetName) };
	for (int k = 0; k < 3; k++) {
		if (k != i)
			delete forms[k];
	}
	std::cout << "Intern creates " << forms[i]->getName() << std::endl;
	return forms[i];	
}