/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:00:49 by kbrauer           #+#    #+#             */
/*   Updated: 2025/02/13 13:04:31 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {

    ClapTrap C1("Larry");
    ScavTrap S1("Hank");
	ScavTrap S2_copy(S1);

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
    S1.takeDamage(4);
    S1.beRepaired(2);

	std::cout << std::endl;

	S2_copy.guardGate();
    S2_copy.attack("Larry_copy");
    S2_copy.takeDamage(4);
    // S2_copy.takeDamage(100);
    S2_copy.beRepaired(2);

	std::cout << std::endl;
}
