/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 23:22:53 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/29 01:53:17 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "Bureaucrat.hpp"
# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"

void    tryCreateAndExecuteShrubberyCreationForm(std::string formName, std::string formTarget, int bureaucratGrade)
{
    try 
    {
        Bureaucrat valdir = Bureaucrat("Valdir do Marketing", bureaucratGrade);
        std::cout <<  "\nAttempting to create Form " << formName << std::endl;
        ShrubberyCreationForm scform = ShrubberyCreationForm(formName, formTarget);
        std::cout << scform << std::endl;
        std::cout << valdir << " will attempt to sign " << formName << std::endl;
        valdir.executeForm(scform);
    }
    catch (const Form::RequiredGradeToExecuteTooLowException& e)
    {
        std::cout << e.what() << std::endl;
    }
}

int main(void)
{
    std::cout <<  "\n ----- SHRUBBERY CREATION FORM -----\n" << std::endl;
    tryCreateAndExecuteShrubberyCreationForm("Form 349245", "VeryImportantDocument", 95);
    std::cout <<  "\n----------" << std::endl;
    tryCreateAndExecuteShrubberyCreationForm("Form 000098", "NotSoImportantDocument", 146);
    return (0);
}
