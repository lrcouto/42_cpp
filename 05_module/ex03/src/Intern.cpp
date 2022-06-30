/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 00:56:06 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/30 02:34:52 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include "Intern.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

Intern::Intern(void)
{
    return ;
}

Intern::~Intern(void)
{
    return ;
}

Intern::Intern(Intern const& instancedObject)
{
    *this = instancedObject;
    return ;
}
Intern	&Intern::operator=(Intern const &rightHandSide)
{
    (void)rightHandSide;
    return (*this);
}

Form	*Intern::makeForm(std::string formName, std::string target)
{
    std::string formTypes[3] = {"shrubberycreation", "robotomyrequest", "presidentialpardon"};
    std::string formattedTypes[3] = {"Shrubbery Creation Form", "Robotomy Request Form", "Presidential Pardon Form"};
    Form        *(Intern::*formPtrs[3])(std::string target) = {&Intern::createShrubberyCreationForm, &Intern::createRobotomyRequestForm, &Intern::createPresidentialPardonForm};
    
    for(int i = 0; i < 3; i++)
	{
		if(formName == formTypes[i])
		{
			std::cout << "The nameless intern creates a " << formattedTypes[i] << std::endl;
			return ((this->*formPtrs[i])(target));
		}
	}
	throw Intern::FormDoesntExistException();
	return (0);
}

Form    *Intern::createShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

Form    *Intern::createRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

Form    *Intern::createPresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}
