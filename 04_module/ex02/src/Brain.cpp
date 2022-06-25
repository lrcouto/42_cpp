/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 00:27:43 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/22 20:19:05 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Brain.hpp"
# include <iostream>
# include <cstdlib>
# include <ctime>
# include <sstream>
# include <unistd.h>

Brain::Brain(void)
{
    usleep(1000000);
    std::srand(time(NULL));
    for (int i = 0; i < 100; i++)
    { 
        std::ostringstream idea;
        idea << rand() % 10000;
        this->ideas[i] = idea.str();
    }
    std::cout << "\033[0;35mBrain constructor called\033[0m" << '\n';
	return ;
}

Brain::~Brain(void)
{
    std::cout << "\033[0;35mBrain destructor called\033[0m" << '\n';
	return ;
}

Brain::Brain(Brain const &instancedObject)
{
	*this = instancedObject;
    std::cout << "\033[0;35mBrain copy constructor called\033[0m" << '\n';
	return ;
}

Brain &Brain::operator=(Brain const &rightHandSide)
{
	for(int i = 0; i < 100; i++)
		this->ideas[i] = rightHandSide.ideas[i];
    std::cout << "\033[0;35mBrain = operator overload function called\033[0m" << '\n';
	return (*this);
}
