/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:39:42 by kbrauer           #+#    #+#             */
/*   Updated: 2025/03/29 16:48:12 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <deque>

int main() {

	std::vector<int> arr_1;
	arr_1.push_back(1);
	arr_1.push_back(2);
	arr_1.push_back(3);
	arr_1.push_back(4);
	arr_1.push_back(5);
	std::cout << easyfind(arr_1, 5) << std::endl;
	std::cout << easyfind(arr_1, 6) << std::endl << std::endl;
	
	std::deque<int> arr_2;
	arr_2.push_back(1);
	arr_2.push_back(2);
	arr_2.push_back(3);
	arr_2.push_back(4);
	arr_2.push_back(5);
	std::cout << easyfind(arr_2, 5) << std::endl;
	std::cout << easyfind(arr_2, 6) << std::endl;

}