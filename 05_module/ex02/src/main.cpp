/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 23:22:53 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/29 03:25:59 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "Bureaucrat.hpp"
# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

void    tryCreateAndExecuteShrubberyCreationForm(std::string formTarget, int bureaucratGrade)
{
    try 
    {
        Bureaucrat valdir = Bureaucrat("Valdir do Marketing", bureaucratGrade);
        std::cout <<  "\nAttempting to create Shrubbery Creation Form" << std::endl;
        ShrubberyCreationForm scform = ShrubberyCreationForm(formTarget);
        std::cout << scform << std::endl;
        std::cout << valdir << " will attempt to execute the Shrubbery Creation Form" << std::endl;
        valdir.executeForm(scform);
    }
    catch (const Form::RequiredGradeToExecuteTooLowException& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void    tryCreateAndExecuteRobotomyRequestForm(std::string formTarget, int bureaucratGrade)
{
    try 
    {
        Bureaucrat claudia = Bureaucrat("Cláudia do Departamento de Treinamento Corporativo", bureaucratGrade);
        std::cout <<  "\nAttempting to create Robotomy Request Form" << std::endl;
        RobotomyRequestForm rrform = RobotomyRequestForm(formTarget);
        std::cout << rrform << std::endl;
        std::cout << claudia << " will attempt to execute the Robotomy Request Form" << std::endl;
        claudia.executeForm(rrform);
    }
    catch (const Form::RequiredGradeToExecuteTooLowException& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void    tryCreateAndExecutePresidentialPardonForm(std::string formTarget, int bureaucratGrade)
{
    try 
    {
        Bureaucrat ppvtceo = Bureaucrat("Paulo Pedro Vinícios Tiago de Carvalho e Pereira, CEO", bureaucratGrade);
        std::cout <<  "\nAttempting to create Presidential Pardon Form" << std::endl;
        PresidentialPardonForm ppform = PresidentialPardonForm(formTarget);
        std::cout << ppform << std::endl;
        std::cout << ppvtceo << " will attempt to execute the Presidential Pardon Form" << std::endl;
        ppvtceo.executeForm(ppform);
    }
    catch (const Form::RequiredGradeToExecuteTooLowException& e)
    {
        std::cout << e.what() << std::endl;
    }
}

int main(void)
{
    std::cout <<  "\n ----- SHRUBBERY CREATION FORM -----\n" << std::endl;
    tryCreateAndExecuteShrubberyCreationForm("VeryImportantDocument", 95);
    std::cout <<  "\n----------" << std::endl;
    tryCreateAndExecuteShrubberyCreationForm("NotSoImportantDocument", 146);
    std::cout <<  "\n ----- ROBOTOMY REQUEST FORM -----\n" << std::endl;
    tryCreateAndExecuteRobotomyRequestForm("Estagiário Juquinha", 10);
    std::cout <<  "\n----------" << std::endl;
    tryCreateAndExecuteRobotomyRequestForm("Jovem Aprendiz Rafinha", 100);
    std::cout <<  "\n ----- PRESIDENTIAL PARDON FORM -----\n" << std::endl;
    tryCreateAndExecutePresidentialPardonForm("Cláudia do Treinamento, acusada do homicídio culposo do Estagiário Juquinha", 1);
    std::cout <<  "\n----------" << std::endl;
    tryCreateAndExecutePresidentialPardonForm("Bode Expiatório da Cláudia", 15);
    return (0);
}
