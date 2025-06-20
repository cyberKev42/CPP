/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:37:32 by kbrauer           #+#    #+#             */
/*   Updated: 2025/06/20 18:16:08 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
}
PmergeMe::PmergeMe(PmergeMe& original) {
	for (std::vector<int>::iterator it = original._num_vec.begin(); it != original._num_vec.end(); it++) {
		this->_num_vec.push_back(*it);
	}
	for (std::deque<int>::iterator it = original._num_deq.begin(); it != original._num_deq.end(); it++) {
		this->_num_deq.push_back(*it);
	}
}
PmergeMe& PmergeMe::operator=(const PmergeMe& P) {
	if (this != &P) {
		this->_num_vec = P._num_vec;
		this->_num_deq = P._num_deq;
	}
	return *this;
}
PmergeMe::~PmergeMe() {
}

template <typename T> void PmergeMe::_add_num_to_container(T& container, char** argv) {
	int i = 1;
	while (argv[i]) {
		container.push_back(atoi(argv[i]));
		i++;
	}
}

int PmergeMe::nbr_of_comps = 0;

/* Gives an index of the nth Jacobsthal number, starting from 1.
 * round((pow(2, n) + pow(-1, n - 1)) / 3) means that it starts from 0.*/
long _jacobsthal_number(long n) {
	return round((pow(2, n + 1) + pow(-1, n)) / 3);
}

void PmergeMe::sort_vec(char** argv) {
	_add_num_to_container(_num_vec, argv);
	_merge_insertion_sort<std::vector<int> >(_num_vec, 1);
}

void PmergeMe::sort_deq(char** argv) {
	_add_num_to_container(_num_deq, argv);
    _merge_insertion_sort<std::deque<int> >(_num_deq, 1);
}

void PmergeMe::print_vec() {
	for (std::vector<int>::iterator it = _num_vec.begin(); it != _num_vec.end(); it++) {
		std::cout << *it << " ";
	}
}

void PmergeMe::print_deq() {
	for (std::deque<int>::iterator it = _num_deq.begin(); it != _num_deq.end(); it++) {
		std::cout << *it << " ";
	}
}

template <typename T> bool compare(T lv, T rv) {
    PmergeMe::nbr_of_comps++;
    return *lv < *rv;
}

template <typename T> T move_iter(T it, int steps)
{
    std::advance(it, steps);
    return it;
}

template <typename T> void PmergeMe::_swap_pair(T it, int pair_size)
{
    T start = move_iter(it, -pair_size + 1);
    T end = move_iter(start, pair_size);
    while (start != end)
    {
        std::iter_swap(start, move_iter(start, pair_size));
        start++;
    }
}

template <typename T> void PmergeMe::_sort_and_recurse(T& container, int pair_size)
{
    typedef typename T::iterator Iterator;

    int nbr_of_pairs = container.size() / pair_size;

    if (nbr_of_pairs < 2)
        return;

    bool is_odd = nbr_of_pairs % 2 == 1;

    Iterator start = container.begin();
    Iterator last = move_iter(start, pair_size * nbr_of_pairs);
    Iterator end = move_iter(last, -(is_odd * pair_size));

    int jump = 2 * pair_size;
    for (Iterator it = start; it != end; std::advance(it, jump))
    {
        Iterator this_pair = move_iter(it, pair_size - 1);
        Iterator move_iter_pair = move_iter(it, (pair_size * 2) - 1);
        if (compare(move_iter_pair, this_pair))
            _swap_pair(this_pair, pair_size);
    }
    _merge_insertion_sort(container, pair_size * 2); // Recursive call
}

template <typename T> void PmergeMe::_fill_chains(T& container, int pair_size, std::vector<typename T::iterator>& main, std::vector<typename T::iterator>& pend, bool is_odd, typename T::iterator end)
{
    int nbr_of_pairs = container.size() / pair_size;

    /* Initialize the main chain with the {b1, a1}. */
    //main.insert(main.end(), move_iter(container.begin(), pair_size - 1));
    main.push_back(move_iter(container.begin(), pair_size - 1));
    main.push_back(move_iter(container.begin(), pair_size * 2 - 1));

    /* Insert the rest of a's into the main chain.
       Insert the rest of b's into the pend. */
    for (int i = 4; i <= nbr_of_pairs; i += 2)
    {
        pend.push_back(move_iter(container.begin(), pair_size * (i - 1) - 1));
        main.push_back(move_iter(container.begin(), pair_size * i - 1));
    }

    /* Insert an odd element to the pend, if there are any. */
    if (is_odd)
    {
        pend.push_back(move_iter(end, pair_size - 1));
    }
}

template <typename T> void PmergeMe::_insert_pend_into_main(std::vector<typename T::iterator>& main, std::vector<typename T::iterator>& pend, bool is_odd) // Removed pair_size
{
    /* Insert the pend into the main in the order determined by the
       Jacobsthal numbers. */
    int jacob_last = _jacobsthal_number(1);
    int inserted_numbers = 0;
    for (int k = 2;; k++)
    {
        int jacob_now = _jacobsthal_number(k);
        int jacob_diff = jacob_now - jacob_last;

        if (jacob_diff > static_cast<int>(pend.size()))
            break;
        int inserts_to_do = jacob_diff;
        typename std::vector<typename T::iterator>::iterator pend_it = move_iter(pend.begin(), jacob_diff - 1);
        typename std::vector<typename T::iterator>::iterator bound_it = move_iter(main.begin(), jacob_now + inserted_numbers);
        while (inserts_to_do)
        {
            typename std::vector<typename T::iterator>::iterator idx = std::upper_bound(main.begin(), bound_it, *pend_it, compare<typename T::iterator>);
            typename std::vector<typename T::iterator>::iterator inserted = main.insert(idx, *pend_it);
            inserts_to_do--;
            pend_it = pend.erase(pend_it);
            std::advance(pend_it, -1);
            int offset = (inserted - main.begin()) == jacob_now + inserted_numbers;
            bound_it = move_iter(main.begin(), jacob_now + inserted_numbers - offset);
        }
        jacob_last = jacob_now;
        inserted_numbers += jacob_diff;
    }

    /* Insert the remaining elements in the reversed order. */
    for (ssize_t i = pend.size() - 1; i >= 0; i--)
    {
        typename std::vector<typename T::iterator>::iterator this_pend = move_iter(pend.begin(), i);
        typename std::vector<typename T::iterator>::iterator this_bound = move_iter(main.begin(), main.size() - pend.size() + i + is_odd);
        typename std::vector<typename T::iterator>::iterator idx = std::upper_bound(main.begin(), this_bound, *this_pend, compare<typename T::iterator>);
        main.insert(idx, *this_pend);
    }
}

template <typename T> void PmergeMe::_copy_values_to_container(T& container, const std::vector<typename T::iterator>& main, int pair_size)
{
    typedef typename T::iterator Iterator;

    std::vector<int>tmp;
    for (typename std::vector<Iterator>::const_iterator it = main.begin(); it != main.end(); it++)
    {
        for (int i = 0; i < pair_size; i++)
        {
			Iterator pair_start = *it;
			std::advance(pair_start, -pair_size + i + 1);
			tmp.push_back(*pair_start);
        }
    }

    Iterator container_it = container.begin();
    typename std::vector<int>::iterator tmp_it =tmp.begin();
    while (tmp_it !=tmp.end())
    {
        *container_it = *tmp_it;
        container_it++;
        tmp_it++;
    }
}


template <typename T> void PmergeMe::_merge_insertion_sort(T& container, int pair_size)
{
    typedef typename T::iterator Iterator;
	std::vector<Iterator> main;
	std::vector<Iterator> pend;

    int nbr_of_pairs = container.size() / pair_size;
    if (nbr_of_pairs < 2)
        return;
    bool is_odd = nbr_of_pairs % 2 == 1;
	
    // last = one after last element (boundary), end = last element
    Iterator last = move_iter(container.begin(), nbr_of_pairs * pair_size);
    Iterator end = move_iter(last, -(is_odd * pair_size));
    _sort_and_recurse(container, pair_size);
    _fill_chains(container, pair_size, main, pend, is_odd, end);
    _insert_pend_into_main<T>(main, pend, is_odd);
    _copy_values_to_container(container, main, pair_size);
}

