/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:17:41 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/13 18:52:52 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie* zombieHorde;
    zombieHorde = new Zombie[N];

    for (int i = 0; i < N; i++)
    {
        zombieHorde[i].setZombieName(name);
        zombieHorde[i].announce();
    }
    return (zombieHorde);
}

void destroyHorde(Zombie *zombieHorde)
{
    delete [] zombieHorde;
}
