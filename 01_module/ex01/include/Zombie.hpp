/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:55:59 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/13 18:06:02 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
	private:
		std::string _name;
	
	public:
		Zombie(std::string name);
		Zombie(void);
		~Zombie(void);

		void	setZombieName(std::string name);
		void	announce(void);
};

Zombie	*zombieHorde(int N, std::string name);
void	destroyHorde(int N, Zombie *zombieHorde);

#endif