/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:38:27 by kbrauer           #+#    #+#             */
/*   Updated: 2025/02/27 18:13:09 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm("ShrubberyCreationForm", 145, 137), _target("noTarget") {
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	AForm("ShrubberyCreationForm", 145, 137), _target(target) {
}
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& original) :
	AForm("ShrubberyCreationForm", 145, 137), _target(original._target) {
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& S) {
	if (this != &S) {
		this->_target = S._target;
	}
	return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm() {
}

void ShrubberyCreationForm::myExe() const {
	std::ofstream ofile(this->_target + "_shrubbery");
	if (ofile.is_open()) {
		ofile << "        *        " << std::endl;
		ofile << "        *        " << std::endl;
		ofile << "       ***       " << std::endl;
		ofile << "      *****      " << std::endl;
		ofile << "     *******     " << std::endl;
		ofile << "    *********    " << std::endl;
		ofile << "   ***********   " << std::endl;
		ofile << "  *************  " << std::endl;
		ofile << " *************** " << std::endl;
		ofile << "*****************" << std::endl;
		ofile << "       |||       " << std::endl;
		ofile << "       |||       " << std::endl;
		ofile << "       |||       " << std::endl;
		ofile << "       |||       " << std::endl;
		ofile.close();
	}
	else {
		std::cout << "Couldn't write to " << this->_target + "_shrubbery" << std::endl;
	}
}
