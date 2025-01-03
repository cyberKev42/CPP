/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:00:10 by kbrauer           #+#    #+#             */
/*   Updated: 2025/01/03 16:17:58 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include "HumanA.hpp"
#include "HumanB.hpp"
#include <string>

class Weapon {
	private:
		std::string type;
	public:
		Weapon(std::string type);
		~Weapon();
		const std::string& 	getType();
		void				setType(std::string type);
};

#endif