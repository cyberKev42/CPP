/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:39:42 by kbrauer           #+#    #+#             */
/*   Updated: 2025/03/22 14:16:59 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <array>
#include <vector>
#include <set>

int main() {

	std::array<int, 5> arr = {1,2,3,4,5};
	std::cout << easyfind(arr, 5) << std::endl;
	std::cout << easyfind(arr, 6) << std::endl << std::endl;
	
	std::vector<int> arr_1 = {1,2,3,4,5};
	std::cout << easyfind(arr_1, 5) << std::endl;
	std::cout << easyfind(arr_1, 6) << std::endl << std::endl;
	
	std::set<int> arr_2 = {1,2,3,4,5};
	std::cout << easyfind(arr_2, 5) << std::endl;
	std::cout << easyfind(arr_2, 6) << std::endl;

}