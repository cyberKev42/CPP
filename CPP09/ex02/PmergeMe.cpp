/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:37:32 by kbrauer           #+#    #+#             */
/*   Updated: 2025/06/12 18:31:13 by kbrauer          ###   ########.fr       */
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

template <typename T> void PmergeMe::_add_num_to_container(T& container, char** argv) {
	int i = 1;
	while (argv[i]) {
		container.push_back(atoi(argv[i]));
		i++;
	}
}


//#######################################

int PmergeMe::nbr_of_comps = 0;

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& original) { (void)original; }
PmergeMe& PmergeMe::operator=(const PmergeMe& P)
{
    (void)P;
    return *this;
}
PmergeMe::~PmergeMe() {}

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

template <typename T> bool _comp(T lv, T rv) {
    PmergeMe::nbr_of_comps++;
    return *lv < *rv;
}

template <typename T> T next(T it, int steps)
{
    std::advance(it, steps);
    return it;
}

template <typename T> void PmergeMe::_swap_pair(T it, int pair_level)
{
    T start = next(it, -pair_level + 1);
    T end = next(start, pair_level);
    while (start != end)
    {
        std::iter_swap(start, next(start, pair_level));
        start++;
    }
}

template <typename T> void PmergeMe::_sort_and_recurse(T& container, int pair_level)
{
    typedef typename T::iterator Iterator;

    int pair_units_nbr = container.size() / pair_level;

    if (pair_units_nbr < 2)
        return;

    bool is_odd = pair_units_nbr % 2 == 1;

    Iterator start = container.begin();
    Iterator last = next(start, pair_level * pair_units_nbr);
    Iterator end = next(last, -(is_odd * pair_level));

    int jump = 2 * pair_level;
    for (Iterator it = start; it != end; std::advance(it, jump))
    {
        Iterator this_pair = next(it, pair_level - 1);
        Iterator next_pair = next(it, (pair_level * 2) - 1);
        if (_comp(next_pair, this_pair))
            _swap_pair(this_pair, pair_level);
    }
    _merge_insertion_sort(container, pair_level * 2); // Recursive call
}

template <typename T> void PmergeMe::_initialize_chains(T& container, int pair_level, std::vector<typename T::iterator>& main, std::vector<typename T::iterator>& pend, bool is_odd, typename T::iterator end_it)
{
    int pair_units_nbr = container.size() / pair_level;

    /* Initialize the main chain with the {b1, a1}. */
    main.insert(main.end(), next(container.begin(), pair_level - 1));
    main.insert(main.end(), next(container.begin(), pair_level * 2 - 1));

    /* Insert the rest of a's into the main chain.
       Insert the rest of b's into the pend. */
    for (int i = 4; i <= pair_units_nbr; i += 2)
    {
        pend.insert(pend.end(), next(container.begin(), pair_level * (i - 1) - 1));
        main.insert(main.end(), next(container.begin(), pair_level * i - 1));
    }

    /* Insert an odd element to the pend, if there are any. */
    if (is_odd)
    {
        pend.insert(pend.end(), next(end_it, pair_level - 1));
    }
}

template <typename T> void PmergeMe::_insert_pend_elements(std::vector<typename T::iterator>& main, std::vector<typename T::iterator>& pend, bool is_odd) // Removed pair_level
{
    /* Insert the pend into the main in the order determined by the
       Jacobsthal numbers. */
    int prev_jacobsthal = _jacobsthal_number(1);
    int inserted_numbers = 0;
    for (int k = 2;; k++)
    {
        int curr_jacobsthal = _jacobsthal_number(k);
        int jacobsthal_diff = curr_jacobsthal - prev_jacobsthal;

        if (jacobsthal_diff > static_cast<int>(pend.size()))
            break;
        int nbr_of_times = jacobsthal_diff;
        typename std::vector<typename T::iterator>::iterator pend_it = next(pend.begin(), jacobsthal_diff - 1);
        typename std::vector<typename T::iterator>::iterator bound_it =
            next(main.begin(), curr_jacobsthal + inserted_numbers);
        while (nbr_of_times)
        {
            typename std::vector<typename T::iterator>::iterator idx =
                std::upper_bound(main.begin(), bound_it, *pend_it, _comp<typename T::iterator>);
            typename std::vector<typename T::iterator>::iterator inserted = main.insert(idx, *pend_it);
            nbr_of_times--;
            pend_it = pend.erase(pend_it);
            std::advance(pend_it, -1);
            int offset = (inserted - main.begin()) == curr_jacobsthal + inserted_numbers;
            bound_it = next(main.begin(), curr_jacobsthal + inserted_numbers - offset);
        }
        prev_jacobsthal = curr_jacobsthal;
        inserted_numbers += jacobsthal_diff;
    }

    /* Insert the remaining elements in the reversed order. */
    for (ssize_t i = pend.size() - 1; i >= 0; i--)
    {
        typename std::vector<typename T::iterator>::iterator curr_pend = next(pend.begin(), i);
        typename std::vector<typename T::iterator>::iterator curr_bound =
            next(main.begin(), main.size() - pend.size() + i + is_odd);
        typename std::vector<typename T::iterator>::iterator idx =
            std::upper_bound(main.begin(), curr_bound, *curr_pend, _comp<typename T::iterator>);
        main.insert(idx, *curr_pend);
    }
}

template <typename T> void PmergeMe::_copy_sorted_values_back(T& container, const std::vector<typename T::iterator>& main, int pair_level)
{
    typedef typename T::iterator Iterator;

    std::vector<int> copy;
    for (typename std::vector<Iterator>::const_iterator it = main.begin(); it != main.end(); it++)
    {
        for (int i = 0; i < pair_level; i++)
        {
            Iterator pair_start = *it;
            std::advance(pair_start, -pair_level + i + 1);
            copy.push_back(*pair_start); // Use push_back instead of insert(end(), ...)
        }
    }

    Iterator container_it = container.begin();
    typename std::vector<int>::iterator copy_it = copy.begin();
    while (copy_it != copy.end())
    {
        *container_it = *copy_it;
        container_it++;
        copy_it++;
    }
}


template <typename T> void PmergeMe::_merge_insertion_sort(T& container, int pair_level)
{
    typedef typename T::iterator Iterator;

    int pair_units_nbr = container.size() / pair_level;

    std::cout << "pair_level: " << pair_level << std::endl;

    if (pair_units_nbr < 2)
        return;
    std::cout << "pair_units_nbr: " << pair_units_nbr << std::endl << std::endl;

    bool is_odd = pair_units_nbr % 2 == 1;

    // last = one after last element (boundary), end_it = last element
    Iterator last = next(container.begin(), pair_level * (pair_units_nbr));
    Iterator end_it = next(last, -(is_odd * pair_level));

    // Phase 1: Sort pairs and recurse on the larger elements
    _sort_and_recurse(container, pair_level);

    // Phase 2: Initialize main and pend chains with iterators
    std::vector<Iterator> main;
    std::vector<Iterator> pend;
    _initialize_chains(container, pair_level, main, pend, is_odd, end_it);

    // Phase 3 & 4: Insert pend elements into main (Jacobsthal and remaining)
    _insert_pend_elements<T>(main, pend, is_odd); // Explicitly specify template argument <T>

    // Phase 5: Copy sorted values back to the original container
    _copy_sorted_values_back(container, main, pair_level);
}

