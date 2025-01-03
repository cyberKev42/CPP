/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:14:28 by kbrauer           #+#    #+#             */
/*   Updated: 2025/01/03 15:33:02 by kbrauer          ###   ########.fr       */
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
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void announce(void);		
		Zombie* zombieHorde(int N, std::string name);
		// std::string getName();
};


#endif
