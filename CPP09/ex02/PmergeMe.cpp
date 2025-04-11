/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:37:32 by kbrauer           #+#    #+#             */
/*   Updated: 2025/04/11 17:07:59 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Pmergeme::Pmergeme() {
	
// }
// Pmergeme::Pmergeme(Pmergeme& original) {
	
// }
// Pmergeme& Pmergeme::operator=(const Pmergeme& P) {
	
// }
// Pmergeme::~Pmergeme() {
	
// }

void Pmergeme::addNumberToVec(int number) {
	static int index = 0;
	this->_num_vec.push_back(std::make_pair(number, index));
	index++;
	// std::cout << _num_vec.capacity() << std::endl;  // print size of allocated memory
}

void Pmergeme::printVec() {
	for (int i = 0; i < static_cast<int>(this->_num_vec.size()); i++)
		std::cout << this->_num_vec[i].first << " ";
	std::cout << std::endl;
	for (int i = 0; i < static_cast<int>(this->_num_vec.size()); i++)
		std::cout << this->_num_vec[i].second << " ";
	std::cout << std::endl;
}

void Pmergeme::addNumberToDeq(int number) {
	static int index = 0;
	this->_num_deq.push_back(std::make_pair(number, index));
	index++;
}

void Pmergeme::printDeq() {
	for (int i = 0; i < static_cast<int>(this->_num_deq.size()); i++)
		std::cout << this->_num_deq[i].first << " ";
	std::cout << std::endl;
	for (int i = 0; i < static_cast<int>(this->_num_deq.size()); i++)
		std::cout << this->_num_deq[i].second << " ";
	std::cout << std::endl;
}

void Pmergeme::cal(std::vector<typename T> input) {

	
	
}