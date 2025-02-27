/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:19:35 by kbrauer           #+#    #+#             */
/*   Updated: 2025/02/27 19:31:23 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
public:
	Intern();
	Intern(Intern& original);
	Intern& operator=(const Intern& I);
	~Intern();
	AForm* makeForm(std::string formName, std::string targetName);
	class FormDoesNotExist : public std::exception {
		const char* what() const noexcept override {
			return "Error: Form does not exist!";
		}
	};
};


#endif