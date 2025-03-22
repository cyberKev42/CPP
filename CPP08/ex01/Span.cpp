/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:49:01 by kbrauer           #+#    #+#             */
/*   Updated: 2025/03/22 18:10:26 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _N(0) {}
Span::Span(unsigned int N) : _N(N) {}
Span::Span(Span& original) : _V(original._V), _N(original._N) {}
Span& Span::operator=(const Span& S) {
	if (this != &S) {
		this->_N = S._N;
		this->_V = S._V;
	}
}
Span::~Span() {}

void Span::addNumber(int number) {
	this->_V.push_back(number);
}

unsigned int Span::shortestSpan() {
	
}

unsigned int Span::longestSpan() {
	if (_N <= 1)
		return 0;
	return *std::min_element(_V.begin(), _V.end());
}