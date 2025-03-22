/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:40:06 by kbrauer           #+#    #+#             */
/*   Updated: 2025/03/22 14:13:55 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template<typename T> int easyfind(T& first, int second) {
	if (std::find(first.begin(), first.end(), second) != first.end())
		return (std::cout << "Found" << std::endl, 0);
	else
		return (std::cout << "Not found" << std::endl, 1);
}

#endif