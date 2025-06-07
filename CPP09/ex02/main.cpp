/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:37:47 by kbrauer           #+#    #+#             */
/*   Updated: 2025/06/07 17:21:00 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static int check_input(char** argv) {
	int i = 0;
	while (argv[++i]) {
		if (argv[i][0] == '-')
			return 1;
		long number = atol(argv[i]);
		if (number == 0 && (std::string)argv[i] != "0")
			return 2;
		if (number > INT_MAX)
			return 3;
	}
	return 0;	
}

int main(int argc, char **argv) {
	
	if (argc < 2)
		return (std::cerr << "Error: no arguments" << std::endl, 1);
	switch (check_input(argv)) {
	case 1:
		return (std::cerr << "Error: no negative numbers " << std::endl, 1);
	case 2:
		return (std::cerr << "Error: invalid input" << std::endl, 1);
	case 3:
		return (std::cerr << "Error: numbers too big" << std::endl, 1);
	default:
		break;
	}
	
	PmergeMe MergeSort;

	clock_t start = clock();
	MergeSort.sort_vec(argv);
    double time_vec = static_cast<double>(clock() - start) / CLOCKS_PER_SEC;

	start = clock();
	MergeSort.sort_deq(argv);
    double time_deq = static_cast<double>(clock() - start) / CLOCKS_PER_SEC;

	std::cout << "Before: ";
	for (int i = 1; i < argc; i++)
		std::cout << argv[i] << " ";
	std::cout << std::endl;
	std::cout << "After:  ";
	MergeSort.print_vec();
	std::cout << std::endl;
	std::cout 	<< "Time to process a range of " << argc - 1
				<< " elements with std::vector : " << std::setprecision(6) << time_vec << " us" << std::endl
				<< "Time to process a range of " << argc - 1
				<< " elements with std::deque : " << time_deq << " us" << std::endl;
}


/*

static std::set<int> argv_to_set(int argc, char** argv)
{
    std::set<int> res;
    for (int i = 1; i < argc; i++)
    {
        res.insert(atoi(argv[i]));
    }
    return res;
}

template <typename T> static bool is_sorted(const T& container)
{
    if (container.size() == 0 || container.size() == 1)
        return true;
    typename T::const_iterator end = container.end();
    std::advance(end, -1);
    for (typename T::const_iterator it = container.begin(); it != end; it++)
    {
        typename T::const_iterator next = it;
        std::advance(next, 1);
        if (*it > *next)
            return false;
    }
    return true;
}

static std::string argv_to_str(int argc, char** argv)
{
    std::string res("");
    res.reserve(argc + 1);
    res += "[";
    res += argv[1];
    for (int i = 2; argv[i]; i++)
    {
        res += " ";
        res += argv[i];
    }
    res += "]";
    return res;
}

static std::string vec_to_str(std::vector<int>& vec)
{
    std::stringstream ss;
    ss << "[" << vec[0];
    for (size_t i = 1; i < vec.size(); i++)
    {
        ss << " " << vec[i];
    }
    ss << "]";
    return ss.str();
}

static bool retained_original_values(std::set<int>& original_values, std::vector<int>& vec)
{
	for (int i = 0; i < (int)vec.size(); i++)
	{
		if (original_values.find(vec[i]) == original_values.end())
			return false;
		original_values.erase(vec[i]);
	}
	return true;
}

int main(int argc, char** argv)
{
    PmergeMe pm;
	
    std::string status = validate(argc, argv);
    if (status != "")
    {
        std::cerr << "Error: " << status << "\n";
        return EXIT_FAILURE;
    }
	std::set<int> original_values = argv_to_set(argc, argv);

    clock_t start_vec = clock();
    std::vector<int> vec = argv_to_vector(argc, argv);
    pm.sort_vec(vec);
    clock_t end_vec = clock();
    double time_elapsed_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC;

	PmergeMe::nbr_of_comps = 0;
    clock_t start_deque = clock();
    std::deque<int> deque = argv_to_deque(argc, argv);
    pm.sort_deque(deque);
    clock_t end_deque = clock();
    double time_elapsed_deque = static_cast<double>(end_deque - start_deque) / CLOCKS_PER_SEC;

    if (!is_sorted(vec) || (int)deque.size() != (argc - 1) || !retained_original_values(original_values, vec))
	{
        std::cout << "Vector was not sorted properly.\n";
		return 1;
	}
    if (!is_sorted(deque) || (int)deque.size() != (argc - 1))
	{
        std::cout << "Deque was not sorted properly.\n";
		return 1;
	}

    std::cout << "Before: " << argv_to_str(argc, argv) << "\n";
    std::cout << "After:  " << vec_to_str(vec) << "\n";
    std::cout << "Time to process a range of " << vec.size()
              << " elements with std::vector: " << std::fixed << std::setprecision(6)
              << time_elapsed_vec << "s\n";
    std::cout << "Time to process a range of " << vec.size()
              << " elements with std::deque:  " << std::fixed << std::setprecision(6)
              << time_elapsed_deque << "s\n";
	std::cout << "Number of comparisons: " << PmergeMe::nbr_of_comps << '\n';
}


*/