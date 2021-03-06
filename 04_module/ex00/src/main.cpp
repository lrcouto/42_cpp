/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:55:08 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/22 20:50:39 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"
# include "WrongAnimal.hpp"
# include "WrongCat.hpp"


int		main(void)
{
	const Animal* animal = new Animal();
	const Animal* cat = new Cat();
	const Animal* dog = new Dog();

	std::cout << "\nCat type: " << cat->getType() << '\n';
	std::cout << "Dog type: " << dog->getType() << '\n';
	std::cout << "Cat says "; 
	cat->makeSound();
	std::cout << "Dog says ";
	dog->makeSound();
	std::cout << "Undefined proto-animal blob says "; 
	animal->makeSound();

	std::cout << "\nCopying a cat" << '\n';
	const Animal* copyCat(cat);
	std::cout << "copyCat is a " << copyCat->getType() << '\n';
	std::cout << "copyCat says ";
	copyCat->makeSound();

	std::cout << "\nCopying a dog" << '\n';
	const Animal* copyDog(dog);
	std::cout << "copyDog is a " << copyDog->getType() << '\n';
	std::cout << "copyDog says ";
	copyDog->makeSound();
	std::cout << "\nMaking a wrong animal + wrong cat" << '\n';

	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << "WrongCat type: " << wrongCat->getType() << '\n';
	std::cout << "WrongAnimal says "; 
	wrongAnimal->makeSound();
	std::cout << "WrongCat says "; 
	wrongCat->makeSound();

	std::cout << "\nYeah that sounded pretty wrong\n" << '\n';

	delete cat;
	delete dog;
	delete animal;
	delete wrongAnimal;
	delete wrongCat;
	
	return (0);
}

