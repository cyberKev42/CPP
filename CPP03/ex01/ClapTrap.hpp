/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:01:09 by kbrauer           #+#    #+#             */
/*   Updated: 2025/02/13 13:18:33 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {
private:
protected:
    std::string     _name;
    int             _hp;
    int             _ep;
    int             _atk;
public:
	ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(ClapTrap& original);
    ~ClapTrap();
    ClapTrap& operator=(const ClapTrap& C);
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif