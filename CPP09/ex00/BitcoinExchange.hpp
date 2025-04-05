/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 17:52:40 by kbrauer           #+#    #+#             */
/*   Updated: 2025/04/05 14:34:23 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>


class BitcoinExchange {
private:
	std::map<std::string, double> 	_data;
	std::string						_input_user;
	std::string						_input_data;
	BitcoinExchange();
public:
	BitcoinExchange(std::string input_user, std::string input_data);
	BitcoinExchange(BitcoinExchange& original);
	BitcoinExchange& operator=(const BitcoinExchange& B);
	~BitcoinExchange();
	void	readData();
	void	calculateData();
	
	class InvalidData : public std::exception {
		const char* what() const throw() {
			return "Error: database contains invalid data.";
		}
	};
	class InvalidInput : public std::exception {
		const char* what() const throw() {
			return "Error: input contains invalid formatting.";
		}
	};
	class InvalidReadInput : public std::exception {
		const char* what() const throw() {
			return "Error: could not open input file.";
		}
	};
	class InvalidReadData : public std::exception {
		const char* what() const throw() {
			return "Error: could not open data file.";
		}
	};
};




#endif