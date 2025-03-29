/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 17:52:40 by kbrauer           #+#    #+#             */
/*   Updated: 2025/03/29 18:11:36 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <iomanip>
#include <fstream>


class BitcoinExchange {
private:
public:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange& original);
	BitcoinExchange& operator=(const BitcoinExchange& B);
	~BitcoinExchange();
	

	
};




#endif