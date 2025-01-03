/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:12:45 by kbrauer           #+#    #+#             */
/*   Updated: 2024/10/12 13:55:13 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void c_up(char *old_str){
	std::string str = old_str;
	for (unsigned long i = 0; i < str.length(); i++)
		std::cout << (char)toupper(str[i]);
}

int	main(int argc, char **argv){
	int string_n = 1;
	if (argc == 1){
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (argc-- > 1)
	{
		c_up(argv[string_n++]);
		if (argc == 1)
			std::cout << std::endl;
	}
}
