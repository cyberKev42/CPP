/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:35:29 by kbrauer           #+#    #+#             */
/*   Updated: 2025/04/11 17:08:10 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include <deque>

class Pmergeme {
private:
	std::vector< std::pair<int, int> >	_num_vec;
	std::deque< std::pair<int, int> > 	_num_deq;
	std::vector< std::pair<typename T , typename T> > _test;
public:
	// Pmergeme();
	// Pmergeme(Pmergeme& original);
	// Pmergeme& operator=(const Pmergeme& P);
	// ~Pmergeme();
	void addNumberToVec(int number);
	void printVec();
	void addNumberToDeq(int number);
	void printDeq();
	void cal(std::vector<typename T> input);
};



#endif