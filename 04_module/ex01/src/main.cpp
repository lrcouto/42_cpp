/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:55:08 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/22 19:56:51 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"
# include "Brain.hpp"
# include <unistd.h>

int		main(void)
{
	int	n = 4;
	std::cout << std::endl << "****** ANIMAL ARRAY *******" << std::endl;

	std::cout << std::endl << "------ CONSTRUCTOR -------" << std::endl;
	Animal	*animals[n];

	for (int i = 0; i < n / 2; i++)
		animals[i] = new Dog();
	for (int i = n / 2; i < n; i++)
		animals[i] = new Cat();

	std::cout << std::endl << "------ DESTRUCTOR -------" << std::endl;
	for (int i = 0; i < n; i++)
		delete animals[i];
	
	std::cout << std::endl << "****** DEEP COPY *******" << std::endl;
	std::cout << std::endl << "------ CONSTRUCTOR -------" << std::endl;
	Dog	*dog = new Dog();
	Dog	dogCopy = Dog(*dog);


	dog->getBrainAddress();
	dogCopy.getBrainAddress();

	std::cout << std::endl << "------ DESTRUCTOR -------" << std::endl;
	std::cout << dog->getIdea(15) << std::endl;
	std::cout << dogCopy.getIdea(15) << std::endl;
	delete dog;
	return (0);
}

