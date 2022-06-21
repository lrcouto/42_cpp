/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 01:39:36 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/21 01:40:13 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
    protected:
        std::string type;

    public:
		WrongAnimal(void);
        ~WrongAnimal(void);
		WrongAnimal(WrongAnimal const &instancedObject);
		WrongAnimal &operator=(WrongAnimal const &rightHandSide);

        void        setType(std::string type);
        std::string getType(void) const;
        void        makeSound(void) const;
};

#endif
