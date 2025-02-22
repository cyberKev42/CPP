/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:28:36 by kbrauer           #+#    #+#             */
/*   Updated: 2025/02/22 15:36:58 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("") , _signed(false) , _sign_grade(0) , _exec_grade(0) {
}
Form::Form(std::string name, int sign_grade, int exec_grade) :
	_name(name) , _signed(false) , _sign_grade(sign_grade) , _exec_grade(exec_grade) {
		if (this->_sign_grade < 1 || this->_exec_grade < 1)
			throw GradeTooHighException();
		else if (this->_sign_grade > 150 || this->_exec_grade > 150)
			throw GradeTooLowException();
}
Form::Form(Form& original) :
	_name(original._name) , _signed(original._signed) , _sign_grade(original._sign_grade) , _exec_grade(original._exec_grade) {
}
Form& Form::operator=(const Form& F) {
	if (this != &F) {
		this->_signed = F._signed;
	}
	return *this;	
}
Form::~Form() {
}

const std::string Form::getName() const {
	return this->_name;
}

bool Form::getSigned() const {
	return this->_signed;
}

const int Form::getSignGrade() const {
	return this->_sign_grade;
}

const int Form::getExecGrade() const {
	return this->_exec_grade;
}

void Form::beSigned(Bureaucrat& B) {
	if (B.getGrade() <= this->_sign_grade)
		this->_signed = true;
	else
		throw GradeTooLowException();
}


std::ostream& operator<< (std::ostream& os, Form& F) {
	os	<< "Form name:                    | " << F.getName()		<< std::endl
		<< "Signed status (0=NO 1=YES)    | " << F.getSigned()		<< std::endl
		<< "Min Sign grade required:      | " << F.getSignGrade()	<< std::endl
		<< "Min Execution grade required: | " << F.getExecGrade()	<< std::endl;
	return os;
}
