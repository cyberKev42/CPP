/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 14:08:01 by kbrauer           #+#    #+#             */
/*   Updated: 2025/04/05 14:59:45 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv) {
	
	if (argc != 2)
		return (std::cout << "Error: exactly one argument needed.", 1);

	RPN myClass;
		
	if (myClass.calculate(argv[1]))
		return 1;
	
	return 0;
}