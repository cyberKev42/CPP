/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:00:06 by kbrauer           #+#    #+#             */
/*   Updated: 2024/10/12 19:50:05 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class HumanB {
	private:
		Weapon 		weapon;
		std::string name;
	public:
		HumanB();
		HumanB(std::string name);
		~HumanB();
		void attack();
		void setWeapon(Weapon weapon);
};

#endif