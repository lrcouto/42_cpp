/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:37:45 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/21 01:11:39 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include <iostream>

class Dog : public Animal
{
    public:
		Dog(void);
		~Dog(void);
		Dog(Dog const &instancedObject);
		Dog &operator=(Dog const &rightHandSide);
    
        void        makeSound(void) const;
};

#endif
