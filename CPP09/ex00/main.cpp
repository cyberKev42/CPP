/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 17:51:53 by kbrauer           #+#    #+#             */
/*   Updated: 2025/03/29 18:14:38 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {

	if (argc != 2)
		return (std::cout << "Only/At least one file name as input needed!", 1);
	
	std::ofstream f;
	f.open(argv[1]);
	// if (open(argv[1]))
	

	return 0;
}