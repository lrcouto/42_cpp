/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 22:04:39 by lcouto            #+#    #+#             */
/*   Updated: 2022/07/18 01:12:51 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

class Base
{
    public:
        virtual ~Base(void) {};
};

class A : public Base {};

class B : public Base {};

class C : public Base {};

Base    *generate(void)
{
    Base *ptr;
    unsigned int random;

    std::cout << "\nGenerating new class." << std::endl;

    std::srand((unsigned int)time(NULL));
	random = rand() % 3;

    switch (random)
    {
        case 0:
            ptr = new A();
            std::cout << "\e[0;34mGenerated class A\e[0m" << std::endl;
            break ;

        case 1:
            ptr = new B();
            std::cout << "\e[0;35mGenerated class B\e[0m" << std::endl;
            break ;

        case 2:
            ptr = new C();
            std::cout << "\e[0;32mGenerated class C\e[0m" << std::endl;
            break ;
    }
    return (ptr);
}

void    identify(Base* p)
{
	std::cout << "\nAttempting to identify class by pointer: " << std::endl;
	if (dynamic_cast<A*>(p))
		std::cout << "\e[0;34mType is A.\e[0m" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "\e[0;35mType is B.\e[0m" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "\e[0;32mType is C.\e[0m" << std::endl;
}

void    identify(Base& p)
{
	std::cout << "\nAttempting to identify class by reference" << std::endl;
	try 
	{
		A &cast = dynamic_cast<A &>(p);
		std::cout << "\e[0;34mType is A.\e[0m" << std::endl;
        static_cast<void>(cast);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\e[1;31m Type is NOT A.\e[0m" << std::endl;
	}
	try 
	{
		B &cast = dynamic_cast<B &>(p);
		std::cout << "\e[0;35mType is B.\e[0m" << std::endl;
        static_cast<void>(cast);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\e[1;31m Type is NOT B.\e[0m" << std::endl;
	}
	try 
	{
		C &cast = dynamic_cast<C &>(p);
		std::cout << "\e[0;32mType is C.\n\e[0m" << std::endl;
        static_cast<void>(cast);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\e[1;31m Type is NOT C.\n\e[0m" << std::endl;
	}
}

int main(void)
{   
    Base *mysteryPtr = generate();
    Base &referencePtr = *mysteryPtr;
    identify(mysteryPtr);
    identify(referencePtr);
    delete mysteryPtr;
    return (0);
}
