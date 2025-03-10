/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:19:22 by kbrauer           #+#    #+#             */
/*   Updated: 2025/01/10 13:29:19 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
#define SED_HPP

#include <string>
#include <fstream>
#include <iostream>

class Sed {
private:
	std::string _inputFile;
	std::string _outputFile;
public:
	Sed(std::string filename);
	~Sed();
	int replaceStr (std::string str1, std::string str2) const;
};

#endif