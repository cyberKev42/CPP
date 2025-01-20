
#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

class FragTrap : ClapTrap {
private:
public:
    FragTrap(std::string name);
    FragTrap(FragTrap& original);
    ~FragTrap();
    FragTrap& operator=(const FragTrap& S);
    void highFivesGuys(void);
}

#endif