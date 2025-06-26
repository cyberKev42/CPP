/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:35:29 by kbrauer           #+#    #+#             */
/*   Updated: 2025/06/26 17:25:36 by kbrauer          ###   ########.fr       */
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
	template <typename T> void _merge_insertion_sort(T& container, int pair_size);
	template <typename T> void _swap_pair(T it, int pair_size);
	template <typename T> void _sort_and_recurse(T& container, int pair_size);
	template <typename T> void _fill_chains(T& container, int pair_size, std::vector<typename T::iterator>& main, std::vector<typename T::iterator>& pend, bool is_odd, typename T::iterator end);
	template <typename T> void _insert_pend_into_main(std::vector<typename T::iterator>& main, std::vector<typename T::iterator>& pend, bool is_odd);
	template <typename T> void _copy_values_to_container(T& container, const std::vector<typename T::iterator>& main, int pair_size);
public:
	PmergeMe();
	PmergeMe(PmergeMe& original);
	PmergeMe& operator=(const PmergeMe& P);
	~PmergeMe();
	static int		comparisons;
	void	sort_vec(char** argv);
	void	sort_deq(char** argv);
	void	print_vec();
	void	print_deq();
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