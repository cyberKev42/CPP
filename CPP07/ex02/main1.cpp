/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:11:49 by kevin             #+#    #+#             */
/*   Updated: 2025/03/20 19:13:36 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Array.hpp"

int main() {
    Array<int>* a = new Array<int>(4);

	try
	{
		std::cout << a->size() << std::endl;
		a->arr[4] = 3;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete a;
}
