/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Claptrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 00:03:52 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/19 20:34:30 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Claptrap.hpp"

ClapTrap::ClapTrap(void)
{
    this->m_name = "CL4P-TP";
    this->m_attackDamage = 0;
    this->m_energyPoints = 10;
    this->m_hitPoints = 10;
    std::cout << "Booting sequence complete. Hello! I am your new steward bot. Designation: CL4P-TP." << std::endl;
    return ;
}

ClapTrap::ClapTrap(std::string name)
{
    this->m_name = name;
    this->m_attackDamage = 0;
    this->m_energyPoints = 10;
    this->m_hitPoints = 10;
    std::cout << "Booting sequence complete. Hello! I am your new steward bot. Designation: " << this->getName() << std::endl;
    return ;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "I'll die the way I lived: annoying!" << std::endl;
    std::cout << this->getName() << " has been destroyed in a glorious explosion." << std::endl;
    return ;
}
ClapTrap::ClapTrap(ClapTrap const &instancedObject)
{
	*this = instancedObject;
    std::cout << "Look out everybody! Things are about to get awesome!" << std::endl;
	return ;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rightHandSide)
{
	this->m_name = rightHandSide.getName();
	this->m_hitPoints = rightHandSide.getHitPoints();
	this->m_energyPoints = rightHandSide.getHitPoints();
	this->m_attackDamage = rightHandSide.getAttackDamage();
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
    if (this->m_energyPoints > 0 && this->m_hitPoints > 0)
    {
        std::cout << "I am a tornado of death and bullets!" << std::endl;
        std::cout << this->getName() << " attacks " << target << " for " << this->getAttackDamage() << " damage." << std::endl;
        this->m_energyPoints -= 1;
    }
    else
        std::cout << this->getName() << " seems to be inactive." << std::endl;
    return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
    if (this->m_energyPoints > 0 && this->m_hitPoints > 0)
    {
        std::cout << "I'm leaking! No, nononono NO!" << std::endl;
        std::cout << this->getName() << " loses " << amount << " hit points" << std::endl;
        this->m_hitPoints -= amount;
    }
    else if (this->m_energyPoints <= 0 || this->m_hitPoints <= 0)
    {
        std::cout << this->getName() << " seems to be inactive, but you can still kick it around for fun if you want." << std::endl;
        std::cout << this->getName() << " loses " << amount << " hit points" << std::endl;
        this->m_hitPoints -= amount;
    }
    return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
    if (this->m_energyPoints > 0 && this->m_hitPoints > 0)
    {
        std::cout << "Hahahahaha! I'm alive!" << std::endl;
        std::cout << this->getName() << " recovers " << amount << " hit points." << std::endl;
        this->m_energyPoints -= 1;
        this->m_hitPoints += amount;
    }
    else if (this->m_energyPoints <= 0 || this->m_hitPoints <= 0)
        std::cout << this->getName() << " seems to be inactive. Maybe kick it to see if it wakes up?" << std::endl;
    return ;
}

void    ClapTrap::setName(std::string const name)
{
    this->m_name = name;
    return ;
}

void    ClapTrap::setHitPoints(int const hitPoints)
{
    this->m_hitPoints = hitPoints;
    return ;
}

void    ClapTrap::setEnergyPoints(int const energyPoints)
{
    this->m_energyPoints = energyPoints;
    return ;
}

void    ClapTrap::setAttackDamage(int const attackDamage)
{
    this->m_attackDamage = attackDamage;
    return ;
}

std::string ClapTrap::getName(void) const
{
    return (this->m_name);
}

int ClapTrap::getHitPoints(void) const
{
    return (this->m_hitPoints);
}

int ClapTrap::getEnergyPoints(void) const
{
    return (this->m_energyPoints);
}

int ClapTrap::getAttackDamage(void) const
{
    return (this->m_attackDamage);
}