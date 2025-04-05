/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 14:08:37 by kbrauer           #+#    #+#             */
/*   Updated: 2025/04/05 16:47:42 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <list>
#include <limits>

class RPN {
private:
	std::stack<double, std::list<double> > _stack;
public:
	RPN();
	RPN(RPN& original);
	RPN& operator=(const RPN& R);
	~RPN();
	int calculate(std::string input);
};

#endif