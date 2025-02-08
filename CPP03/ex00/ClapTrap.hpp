#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {
private:
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