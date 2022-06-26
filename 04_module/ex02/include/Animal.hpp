/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:43:35 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/22 21:32:19 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
    protected:
        std::string type;

    public:
		Animal(void);
        virtual ~Animal(void);
		Animal(Animal const &instancedObject);
		Animal &operator=(Animal const &rightHandSide);

        void                setType(std::string type);
        std::string         getType(void) const;
        virtual void        makeSound(void) const = 0;
        virtual std::string getIdea(int index) const = 0;
        virtual void        getBrainAddress(void) const = 0;
};

#endif
