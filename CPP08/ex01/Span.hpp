/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:49:05 by kbrauer           #+#    #+#             */
/*   Updated: 2025/03/29 16:55:27 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

class Span {
private:
	unsigned int _N;
	std::vector<int> _V;
public:
	Span();
	Span(unsigned int N);
	Span(const Span& original);
	Span& operator=(const Span& S);
	~Span();
	void addNumber(int number);
	void addSequence(int* bgn, int* end);
	unsigned int shortestSpan();
	unsigned int longestSpan();
	void printV();
	class AlreadyFull : public std::exception {
		const char* what() const throw() {
			return "Container is already full";
		}
	};
};




#endif