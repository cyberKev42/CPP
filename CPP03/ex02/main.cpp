/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:00:49 by kbrauer           #+#    #+#             */
/*   Updated: 2025/02/13 17:08:28 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {

    ClapTrap C1("Larry");
    ScavTrap S1("Hank");
    FragTrap F1("Sabine");
	FragTrap F2_copy(F1);

	std::cout << std::endl;

    C1.attack("Hank");
    C1.takeDamage(2);
    C1.takeDamage(1);
    // C1.takeDamage(8);
    C1.beRepaired(2);
    C1.beRepaired(2);
    C1.beRepaired(2);
    C1.beRepaired(2);
    C1.beRepaired(2);
    C1.beRepaired(2);
    C1.beRepaired(2);
    C1.beRepaired(2);
    C1.beRepaired(2);
    C1.beRepaired(2);

	std::cout << std::endl;

    S1.guardGate();
    S1.attack("Larry");
    S1.takeDamage(40);
    S1.beRepaired(20);

	std::cout << std::endl;
    
    F1.attack("Larry");
    F1.takeDamage(66);
    F1.beRepaired(23);
    F1.highFivesGuys();

	std::cout << std::endl;

	F2_copy.attack("Larry_copy");
    F2_copy.takeDamage(66);
    F2_copy.beRepaired(23);
    F2_copy.highFivesGuys();

	std::cout << std::endl;
}
