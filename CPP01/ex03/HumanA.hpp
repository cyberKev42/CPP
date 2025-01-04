/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:00:02 by kbrauer           #+#    #+#             */
/*   Updated: 2025/01/04 17:11:28 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class HumanA {
	private:
		Weapon& 	_weapon;
		std::string _name;
		HumanA();
	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA();
		void attack();
};

#endif
