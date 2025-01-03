/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:56:17 by kbrauer           #+#    #+#             */
/*   Updated: 2024/10/12 16:10:39 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
	private:
		std::string name;
	public:
		Zombie(std::string name);
		~Zombie();
		void announce(void);		
};

Zombie* newZombie(std::string name);
void 	randomChump(std::string name);

#endif