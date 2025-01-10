/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:51:37 by kbrauer           #+#    #+#             */
/*   Updated: 2025/01/09 19:48:05 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

int main(int argc, char** argv){
	
	if (argc != 4)
		return (std::cout << "Wrong number of arguments!" << std::endl, 1);
	Sed sed(argv[1]);
	sed.replaceStr(argv[2], argv[3]);
	return 0;
}

// Create a program that takes three parameters in the following order: a filename and
// two strings, s1 and s2.
// It will open the file <filename> and copies its content into a new file
// <filename>.replace, replacing every occurrence of s1 with s2.
// Using C file manipulation functions is forbidden and will be considered cheating. All
// the member functions of the class std::string are allowed, except replace. Use them
// wisely!
// Of course, handle unexpected inputs and errors. You have to create and turn in your
// own tests to ensure your program works as expected.