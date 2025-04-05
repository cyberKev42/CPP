/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 17:51:53 by kbrauer           #+#    #+#             */
/*   Updated: 2025/04/04 19:10:01 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {

	if (argc != 2)
		return (std::cout << "Only/At least one file name as input needed!", 1);
	
	BitcoinExchange btc(argv[1], "data.csv");
	
	try
	{
		btc.readData();
		btc.calculateData();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	

		
	return 0;
}