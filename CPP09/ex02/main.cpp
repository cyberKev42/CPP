/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:37:47 by kbrauer           #+#    #+#             */
/*   Updated: 2025/04/11 16:33:34 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	
	if (argc < 2)
		return (std::cout << "Error: no argument." << std::endl, 1);
	
	Pmergeme MergeSort;

	int i = 1;
	while (argv[i]) {
		int c = 0;
		while (argv[i][c]) {
			if (!isdigit(argv[i][c]))
				return (std::cout << "Error: only positiv numbers allowed." << std::endl, 1);
			c++;
		}
		MergeSort.addNumberToVec(atoi(argv[i]));
		MergeSort.addNumberToDeq(atoi(argv[i]));
		i++;
	}
	MergeSort.printVec();
	MergeSort.printDeq();
}