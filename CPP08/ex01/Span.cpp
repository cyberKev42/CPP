/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:49:01 by kbrauer           #+#    #+#             */
/*   Updated: 2025/03/29 16:57:37 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _N(0) {}
Span::Span(unsigned int N) : _N(N) {}
Span::Span(const Span& original) : _N(original._N), _V(original._V) {}
Span& Span::operator=(const Span& S) {
	if (this != &S) {
		this->_N = S._N;
		this->_V = S._V;
	}
	return *this;
}
Span::~Span() {}

void Span::addNumber(int number) {
	if (_V.size() < _N)
		this->_V.push_back(number);
}

void Span::addSequence(int* bgn, int* end) {
	while (bgn != end) {
		if (_V.size() < _N)
			this->_V.push_back(*bgn);
		bgn++;	
	}
	if (_V.size() < _N)
		this->_V.push_back(*bgn);
}

unsigned int Span::shortestSpan() {
	int shortest_span = 2147483647;
	for (std::vector<int>::iterator it = _V.begin(); it != _V.end(); ++it) {
		for (std::vector<int>::iterator it2 = _V.begin() + 1; it2 != _V.end(); ++it2) {
			if (it != it2) {
				if (abs(*it2 - *it) < shortest_span)
					shortest_span = abs(*it2 - *it);
			}
		}
	}
	return shortest_span;
}

unsigned int Span::longestSpan() {
	if (_V.size() <= 1)
		return 0;
	return (*std::max_element(_V.begin(), _V.end()) - *std::min_element(_V.begin(), _V.end()));
}

void  Span::printV() {
	for (std::vector<int>::iterator it = _V.begin(); it != _V.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}