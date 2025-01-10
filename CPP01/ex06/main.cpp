/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:03:14 by kbrauer           #+#    #+#             */
/*   Updated: 2025/01/10 17:19:07 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cout << "One argument needed, not more or less!" << std::endl, 1);
	Harl harl;
	harl.complain(argv[1]);	
	return 0;
}
