/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:55:08 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/22 20:35:48 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"
# include "Brain.hpp"

int		main(void)
{
	int	n = 6;
	std::cout << std::endl << "\n****** ANIMAL ARRAY *******\n" << std::endl;

	std::cout << std::endl << "------ CONSTRUCTORS -------" << std::endl;
	Animal	*animals[n];

	for (int i = 0; i < n / 2; i++)
		animals[i] = new Dog();
	for (int i = n / 2; i < n; i++)
		animals[i] = new Cat();

	std::cout << std::endl << "------ DESTRUCTORS -------" << std::endl;
	for (int i = 0; i < n; i++)
		delete animals[i];
	
	std::cout << std::endl << "\n****** DEEP COPY *******\n" << std::endl;
	std::cout << std::endl << "------ CONSTRUCTORS -------" << std::endl;
	Dog	*dog = new Dog();
	Dog	*dogCopy = new Dog(*dog);
	Cat cat;
	Cat catCopy(cat);

	std::cout << std::endl << "------ BRAIN ADDRESSES -------" << std::endl;

	dog->getBrainAddress();
	dogCopy->getBrainAddress();
	cat.getBrainAddress();
	catCopy.getBrainAddress();

	std::cout << std::endl << "------ IDEAS -------" << std::endl;

	std::cout << dog->getIdea(15) << std::endl;
	std::cout << dogCopy->getIdea(15) << std::endl;
	std::cout << cat.getIdea(15) << std::endl;
	std::cout << catCopy.getIdea(15) << std::endl;

	std::cout << std::endl << "------ DESTRUCTORS -------" << std::endl;
	delete dog;
	delete dogCopy;
	return (0);
}

