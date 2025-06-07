/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:35:29 by kbrauer           #+#    #+#             */
/*   Updated: 2025/06/07 17:17:53 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <climits>
#include <iomanip>
#include <cmath>
#include <vector>
#include <deque>

class PmergeMe {
private:
	std::vector<int>	_num_vec;
	std::deque<int> 	_num_deq;
	template <typename T> void _add_num_to_container(T& container, char** argv);
	template <typename T> void _merge_insertion_sort(T& container, int pair_level);
	template <typename T> void _swap_pair(T it, int pair_level);
	template <typename T> void _sort_and_recurse(T& container, int pair_level);
	template <typename T> void _initialize_chains(T& container, int pair_level, std::vector<typename T::iterator>& main, std::vector<typename T::iterator>& pend, bool is_odd, typename T::iterator end_it);
	template <typename T> void _insert_pend_elements(std::vector<typename T::iterator>& main, std::vector<typename T::iterator>& pend, bool is_odd);
	template <typename T> void _copy_sorted_values_back(T& container, const std::vector<typename T::iterator>& main, int pair_level);
public:
	PmergeMe();
	PmergeMe(const PmergeMe& original);
	PmergeMe& operator=(const PmergeMe& P);
	~PmergeMe();
	void sort_vec(char** argv);
	void sort_deq(char** argv);
	void print_vec();
	void print_deq();
	static int nbr_of_comps;
};

/*
class Pmergeme {
	private:
	std::vector<int>	_num_vec;
	std::deque<int> 	_num_deq;
	//std::vector< std::pair<typename T , typename T> > _test;
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
*/



#endif