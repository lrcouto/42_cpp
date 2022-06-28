/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 23:22:53 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/27 01:52:51 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "Bureaucrat.hpp"
# include "Form.hpp"

void    tryCreateForm(std::string name, int gradeToExecute, int gradeToSign)
{
    try 
    {
        std::cout <<  "\nAttempting to create Form " << name << std::endl;
        Form form = Form(name, gradeToExecute, gradeToSign);
        std::cout << form << std::endl;
    }
    catch (const Form::GradeTooHighException& e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (const Form::GradeTooLowException& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void tryCreateAndSignForm(std::string name, int gradeToExecute, int gradeToSign)
{
    try 
    {
        std::cout <<  "\nCreating Bureaucrat Alcides da Contabilidade " << std::endl;
        Bureaucrat alcides = Bureaucrat("Alcides da Contabilidade", 42);
        std::cout << alcides << std::endl;
        std::cout <<  "\nCreating valid Form " << name << std::endl;
        Form form = Form(name, gradeToExecute, gradeToSign);
        std::cout << form << std::endl;
        alcides.signForm(form);
        std::cout << form << std::endl;
        std::cout <<  "------------------------" << std::endl;
    }
    catch (const Form::GradeTooHighException& e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (const Form::GradeTooLowException& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void trySigningFormTwice(std::string name, int gradeToExecute, int gradeToSign)
{
    try 
    {
        std::cout <<  "\nCreating Bureaucrat Alcides da Contabilidade " << std::endl;
        Bureaucrat alcides = Bureaucrat("Alcides da Contabilidade", 42);
        std::cout << alcides << std::endl;
        std::cout <<  "\nCreating valid Form " << name << std::endl;
        Form form = Form(name, gradeToExecute, gradeToSign);
        std::cout << form << std::endl;
        alcides.signForm(form);
        std::cout << form << std::endl;
        alcides.signForm(form);
        std::cout <<  "------------------------" << std::endl;
    }
    catch (const Form::GradeTooHighException& e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (const Form::GradeTooLowException& e)
    {
        std::cout << e.what() << std::endl;
    }
}


int main(void)
{
    std::cout <<  "\n ----- FORM OBJECT CREATION -----\n" << std::endl;
    tryCreateForm("Form 13245", 151, 10);
    tryCreateForm("Form 00234", 150, 0);
    tryCreateForm("Form 21452", -2, 100);
    tryCreateForm("Form 21452", 42, 21);
    std::cout <<  "\n ----- CREATING AND SIGNING FORMS -----\n" << std::endl;
    tryCreateAndSignForm("Form 42343", 100, 21);
    tryCreateAndSignForm("Form 00900", 100, 100);
    std::cout <<  "\n ----- ATTEMPTING TO SIGN A FORM TWICE -----\n" << std::endl;
    trySigningFormTwice("Form 32352", 99, 96);
    return (0);
}
