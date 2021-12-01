/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:55:59 by lcouto            #+#    #+#             */
/*   Updated: 2021/11/30 21:46:07 by lcouto           ###   ########.fr       */
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

		void	announce(void);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif