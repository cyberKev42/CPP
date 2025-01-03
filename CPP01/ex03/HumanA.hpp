/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:00:02 by kbrauer           #+#    #+#             */
/*   Updated: 2024/10/12 19:54:08 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class HumanA {
	private:
		Weapon 		weapon;
		std::string name;
	public:
		HumanA();
		HumanA(std::string name, Weapon weapon);
		~HumanA();
		void attack();
		
};


#endif
