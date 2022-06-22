/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 00:27:43 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/22 03:40:12 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Brain.hpp"
# include <iostream>
# include <cstdlib>
# include <ctime>
# include <sstream>

std::string Brain::ideas[100] = {};

Brain::Brain(void)
{
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 100; i++)
    { 
        std::ostringstream idea;
        idea << rand() % 1000;
        this->ideas[i] = idea.str();
    }
	return ;
}

Brain::~Brain(void)
{
	return ;
}

Brain::Brain(Brain const &instancedObject)
{
	*this = instancedObject;
	return ;
}

Brain &Brain::operator=(Brain const &rightHandSide)
{
	for(int i = 0; i < 100; i++)
		this->ideas[i] = rightHandSide.ideas[i];
	return (*this);
}
