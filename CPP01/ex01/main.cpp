/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:14:23 by kbrauer           #+#    #+#             */
/*   Updated: 2025/01/03 15:36:36 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main() {
	Zombie* horde;
	horde = horde->zombieHorde(5, "Larry");
	
	delete [] horde;
}
