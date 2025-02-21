/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:37:21 by kbrauer           #+#    #+#             */
/*   Updated: 2025/02/21 18:22:51 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Anonymous") {
	this->_grade = 0;
}
Bureaucrat::Bureaucrat(std::string name, int num) : _name(name) {
	if (num < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (num > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = num;
}
Bureaucrat::Bureaucrat(Bureaucrat& original) : _name(original.getName()) {
	this->_grade = original.getGrade();
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& B) {
	if (this != &B) {
		this->_grade = B.getGrade();
	}
	return *this;
}
Bureaucrat::~Bureaucrat() {
}

const std::string Bureaucrat::getName() const {
	return this->_name;
}

int Bureaucrat::getGrade() const {
	return this->_grade;
}

void Bureaucrat::incrementGrade(int n) {
	if (this->getGrade() - n < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade -= n;
}

void Bureaucrat::decrementGrade(int n) {
	if (this->getGrade() + n > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade += n;
}

std::ostream& operator<<(std::ostream& os, Bureaucrat& B) {
	os << B.getName() << ", bureaucrat grade " << B.getGrade();
	return os;
}