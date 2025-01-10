/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:18:16 by kbrauer           #+#    #+#             */
/*   Updated: 2025/01/10 13:29:32 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

Sed::Sed(std::string filename){
	this->_inputFile = filename;
	this->_outputFile = filename.append(".replace");
}
Sed::~Sed(){
}

int Sed::replaceStr(std::string str1, std::string str2) const {
	std::ifstream	ifs (this->_inputFile);
	std::ofstream	ofs (this->_outputFile);
	std::string		tmp;
	int 			pos;
	char 			c;

	if (!ifs.is_open())
		return (std::cout << "Cannot read input file!" << std::endl, 0);
	if (!ofs.is_open())
		return (std::cout << "Cannot open output file!" << std::endl, 0);
	while (!ifs.eof()){	
		ifs >> std::noskipws >> c;
		tmp.append(1, c);
	}
	while (1){
		pos = tmp.find(str1);
		if (pos == -1)
			break;
		tmp.erase(pos, str1.size());
		tmp.insert(pos, str2);
	}
	int	len = tmp.size();
	tmp.erase(len-1, 1);
	ofs << tmp;
	return 0;
}
