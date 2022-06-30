/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 23:22:53 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/30 02:48:03 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "Form.hpp"
# include "Intern.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

Form    *tryUsingInternToCreateForm(std::string formName, std::string formTarget)
{
    try 
    {
        Intern intern;
        std::cout <<  "\nCreating form with keyword \"" << formName << "\"" << std::endl;
        Form *newForm = intern.makeForm(formName, formTarget);
        return (newForm);
    }
    catch (const Intern::FormDoesntExistException& e)
    {
        std::cout << e.what() << std::endl;
        return (0);
    }
}

int main(void)
{
    Form *shrubbery = tryUsingInternToCreateForm("shrubberycreation", "this_directory");
    std::cout <<  "\n----------" << std::endl;
    Form *robotomy = tryUsingInternToCreateForm("robotomyrequest", "Cláudia do Departamento de Treinamento Corporativo");
    std::cout <<  "\n----------" << std::endl;
    Form *pardon = tryUsingInternToCreateForm("presidentialpardon", "Nameless Intern");
    std::cout <<  "\n----------" << std::endl;
    Form *randomshit = tryUsingInternToCreateForm("randomshit", "Irrelevant");
    std::cout <<  "\n----------" << std::endl;

        std::cout <<  "\nMaking a bureaucrat to execute all those forms" << std::endl;

    Bureaucrat bigwig = Bureaucrat("Mr. Bigwig Formsigner", 1);
    std::cout << bigwig << std::endl;

    std::cout <<  "\n----------" << std::endl;
    bigwig.executeForm(*shrubbery);
    std::cout <<  "\n----------" << std::endl;
    bigwig.executeForm(*robotomy);
    std::cout <<  "\n----------" << std::endl;
    bigwig.executeForm(*pardon);
    std::cout <<  "\n----------" << std::endl;

    delete shrubbery;
    delete robotomy;
    delete pardon;
    delete randomshit;
    return (0);
}
