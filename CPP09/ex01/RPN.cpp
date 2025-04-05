/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 14:08:27 by kbrauer           #+#    #+#             */
/*   Updated: 2025/04/05 17:43:28 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(RPN& original) {
	this->_stack = original._stack;
}
RPN& RPN::operator=(const RPN& R) {
	if (this != &R)
		this->_stack = R._stack;
	return *this;
}
RPN::~RPN() {}

static int checkInput(std::string input) {
	int num_count = 0;
	int opr_count = 0;
	bool num_flag = false;
	bool opr_flag = false;
	std::string::iterator it = input.begin();
	
	while (it != input.end())
	{
		if (*it == ' ' || *it == '\t') {
			num_flag = false;
			opr_flag = false;
			it++;
			continue;
		}
		if ((*it < '0' || *it > '9') && (*it != '+' && *it != '-' && *it != '/' && *it != '*'))
			return 1;
		if ((*it >= '0' && *it <= '9')) {
			if (num_flag)
				return 1;
			opr_flag = false;
			num_flag = true;
			num_count++;
		}
		if (*it == '+' || *it == '-' || *it == '/'|| *it == '*') {
			if (opr_flag)
				return 1;
			num_flag = false;
			opr_flag = true;
			opr_count++;
		}
		it++;
	}
	if (opr_count != num_count - 1)
		return 1;
	return 0;
}

static double getResult(double num1, double num2, int opr) {
	if (opr == '+')
		return (num1 + num2);
	else if (opr == '-')
		return (num1 - num2);
	else if (opr == '/')
		return (num1 / num2);
	else //(opr == '*')
		return (num1 * num2);
}

int RPN::calculate(std::string input) {
	if (checkInput(input))
		return (std::cout << "Error: invalid input." << std::endl, 1);
	for (std::string::iterator it = input.begin(); it != input.end(); it++) {
		if (*it == ' ' || *it == '\t') {
			continue;
		}
		if ((*it >= '0' && *it <= '9'))
			this->_stack.push(*it - 48);
		if (*it == '+' || *it == '-' || *it == '/'|| *it == '*') {
			double num2 = _stack.top();
			this->_stack.pop();
			double num1 = _stack.top();
			this->_stack.pop();
			double result = getResult(num1, num2, *it);
			if (result == std::numeric_limits<double>::infinity())
				return (std::cout << "Error: you can not divide by zero." << std::endl, 1);
			this->_stack.push(result);
		}
	}
	std::cout << this->_stack.top() << std::endl;
	return 0;
}