/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:37:19 by kbrauer           #+#    #+#             */
/*   Updated: 2025/02/27 19:45:40 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
	

	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	rrf->myExe();
	delete rrf;
	
	rrf = someRandomIntern.makeForm("presidential pardon", "Render");
	rrf->myExe();
	delete rrf;
	
	rrf = someRandomIntern.makeForm("shrubbery creation", "Sender");
	rrf->myExe();
	delete rrf;
	
	try {
		rrf = someRandomIntern.makeForm("invalid form name", "target");
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}


	return 0;
}
