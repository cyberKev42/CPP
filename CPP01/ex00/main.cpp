/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:56:10 by kbrauer           #+#    #+#             */
/*   Updated: 2024/10/12 16:10:15 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>

int main() {
	Zombie* zombie_henry = newZombie("Henry");
	randomChump("Mike");

	delete zombie_henry;
}