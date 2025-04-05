/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 18:05:26 by kbrauer           #+#    #+#             */
/*   Updated: 2025/04/05 14:54:17 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string input_user, std::string input_data) {
	this->_input_user = input_user;
	this->_input_data = input_data;
}
BitcoinExchange::BitcoinExchange(BitcoinExchange& original) {
	this->_data = original._data;
	this->_input_user = original._input_user;
	this->_input_data = original._input_data;
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& B) {
	if (this != &B) {
		this->_data = B._data;
		this->_input_user = B._input_user;
		this->_input_data = B._input_data;
	}
	return *this;
}
BitcoinExchange::~BitcoinExchange() {
}

static int checkData(std::string date, std::string value_str, double amount) {
	int		year = atoi(date.substr(0, 4).c_str());
	int		month = atoi(date.substr(5, 2).c_str());
	int		day = atoi(date.substr(8, 2).c_str());
	bool	is_gap_year = false;
	bool	has31days[] = {false, true, false, true, false, true, false, 
							true, true, false, true, false, true};
	// calculate gap year
	if (year % 4 == 0)
		is_gap_year = true;
	if ((year % 4 == 0) && (year % 100 == 0))
		is_gap_year = false;
	if ((year % 4 == 0) && (year % 100 == 0) && (year % 400 == 0))
		is_gap_year = true;
	// check valid date
	if ((year < 2009 || year > 2024) || (month < 1 || month > 12) || (day < 1))
		return 1;
	if ((!has31days[month] && day > 30) || (has31days[month] && day > 31))
		return 1;
	if (month == 2 && ((!is_gap_year && day > 28) || (is_gap_year && day > 29)))
		return 1;
	if (date[4] != '-' || date[7] != '-')
		return 1;
	// check valid value
	std::string::iterator it = value_str.begin();
	for (int flag = 0; it != value_str.end(); it++) {
		if (*it == '.' && !flag) {
			flag++;
			continue;		
		}
		if (*it < '0' || *it > '9')
			return 1;
	}
	// check valid bitcoin value, max. value on 24th Dec 2024 -> 103,332.30 USD
	double value = atof(value_str.c_str());
	if (value > 105000 || value < 0 || amount < 0 || amount > 1000)
		return 1;
	return 0;
}

void BitcoinExchange::readData() {
	std::ifstream file;
	file.open(this->_input_data.c_str());
	if (!file.is_open())
		throw BitcoinExchange::InvalidReadData();

	std::string line;
	std::getline(file, line);
	int i = 2;
	while (file) {
		std::getline(file, line);
		if (file.eof())
			return ;
		if (line.size() == 0)
			continue;
		if ((line.size() < 11) || checkData(line.substr(0, 10), line.substr(11, line.size() - 11), 0)) {
			std::cout << "Line " << i << std::endl;	
			throw BitcoinExchange::InvalidData();
		}
		this->_data.insert(std::make_pair(line.substr(0, 10), atof(line.substr(11, line.size() - 11).c_str())));
		i++;
	}
}

static int checkInput(std::string date, std::string amount_str) {
	int		year = atoi(date.substr(0, 4).c_str());
	int		month = atoi(date.substr(5, 2).c_str());
	int		day = atoi(date.substr(8, 2).c_str());
	bool	is_gap_year = false;
	bool	has31days[] = {false, true, false, true, false, true, false, 
							true, true, false, true, false, true};
	// calculate gap year
	if (year % 4 == 0)
		is_gap_year = true;
	if ((year % 4 == 0) && (year % 100 == 0))
		is_gap_year = false;
	if ((year % 4 == 0) && (year % 100 == 0) && (year % 400 == 0))
		is_gap_year = true;
	// check valid date
	if ((year < 2009 || year > 2024) || (month < 1 || month > 12) || (day < 1))
		return (std::cout << "Error: bad input => " << date.substr(0, 10) << std::endl, 1);
	if ((!has31days[month] && day > 30) || (has31days[month] && day > 31))
		return (std::cout << "Error: bad input => " << date.substr(0, 10) << std::endl, 1);
	if (month == 2 && ((!is_gap_year && day > 28) || (is_gap_year && day > 29)))
		return (std::cout << "Error: bad input => " << date.substr(0, 10) << std::endl, 1);
	if (date[4] != '-' || date[7] != '-' || date[10] != ' ' || date[11] != '|' || date[12] != ' ')
		return (std::cout << "Error: bad input => "  << date.substr(0, 10) << std::endl, 1);
	// check valid value
	std::string::iterator it = amount_str.begin();
	for (int flag = 0; it != amount_str.end(); it++) {
		if (*it == '.' && !flag) {
			flag++;
			continue;		
		}
		if (*it < '0' || *it > '9')
		return (std::cout << "Error: not a valid positive number." << std::endl, 1);
	}
	// check valid bitcoin amount
	double amount = atof(amount_str.c_str());
	if (amount < 0 || amount > 1000)
		return (std::cout << "Error: too large a number." << std::endl, 1);
	return 0;
}

void BitcoinExchange::calculateData() {
	std::ifstream file;
	file.open(this->_input_user.c_str());
	if (!file.is_open())
		throw BitcoinExchange::InvalidReadInput();

	std::string line;
	std::getline(file, line);
	// int i = 2;
	while (file) {
		if (file.eof())
			return ;
		std::getline(file, line);
		// std::cout << i++ << " ";
		if (line.size() == 0) {
			std::cout << std::endl;
			continue;
		}
		if (line.size() < 13) {
			std::cout << "Error: bad input => " << line.substr(0, 10) << std::endl;
			continue;
		}
		if (checkInput(line.substr(0, 13), line.substr(13, line.size() - 13)))
			continue;
		
		
		std::map<std::string, double>::iterator it = _data.find(line.substr(0, 10));
		if (it == _data.end()) {
			it = _data.lower_bound(line.substr(0, 10));
			if (it == _data.begin()) {
				std::cout << "Error: date too early => " << line.substr(0, 10) << std::endl;
				continue;	
			}
			--it;
		}
		std::cout 	<< it->first << " => " << atof(line.substr(13, line.size() - 13).c_str())
					<< " = " << it->second * atof(line.substr(13, line.size() - 13).c_str()) << std::endl;
		
	}
}