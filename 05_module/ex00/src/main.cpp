/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 23:22:53 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/26 01:03:03 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "Bureaucrat.hpp"

void    tryCreateBureaucratOverLimit(void)
{
    try 
    {
        std::cout << std::endl << "Attempting to create Bureaucrat Dr. Márcio Ferreira de Carvalho with grade 0." << std::endl;
        Bureaucrat drMarcio = Bureaucrat("Dr. Márcio Ferreira de Carvalho", 0);
        std::cout << drMarcio << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void    tryCreateBureaucratUnderLimit(void)
{
    try 
    {
        std::cout << std::endl << "Attempting to create Bureaucrat Estagiário Juquinha do Segundo Ano de Administração with grade 151." << std::endl;
        Bureaucrat juquinha = Bureaucrat("Estagiário Juquinha do Segundo Ano de Administração", 0);
        std::cout << juquinha << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void    tryIncrementBureaucratPastLimit(void)
{
    try 
    {
        std::cout << std::endl << "Attempting to increment Bureaucrat Dra. Cláudia do Jurídico beyond level 1." << std::endl;
        Bureaucrat draClaudia = Bureaucrat("Dra. Cláudia do Jurídico", 1);
        std::cout << draClaudia << std::endl;
        draClaudia.incrementGrade();
        std::cout << draClaudia << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void    tryDecrementBureaucratPastLimit(void)
{
    try 
    {
        std::cout << std::endl << "Attempting to decrement Bureaucrat Toninho que só Entrou na Empresa por Nepotismo below level 150." << std::endl;
        Bureaucrat toninho = Bureaucrat("Toninho que só Entrou na Empresa por Nepotismo", 150);
        std::cout << toninho << std::endl;
        toninho.decrementGrade();
        std::cout << toninho << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void    tryCreateValidBuraucrat(void)
{
    try 
    {
        std::cout << std::endl << "Attempting to create valid Bureaucrat Alcides da Contabilidade." << std::endl;
        Bureaucrat alcides = Bureaucrat("Alcides da Contabilidade", 42);
        std::cout << alcides << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void    tryIncrementBureaucratWhithinLimit(void)
{
    try 
    {
        std::cout << std::endl << "Attempting to increment Bureaucrat Cleide da Logística whithin valid limits." << std::endl;
        Bureaucrat cleide = Bureaucrat("Cleide da Logística", 30);
        std::cout << cleide << std::endl;
        cleide.incrementGrade();
        std::cout << cleide << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cout << e.what() << std::endl;
        }
    }

void    tryDecrementBureaucratWhithinLimit(void)
{
    try 
    {
        std::cout << std::endl << "Attempting to decrement Bureaucrat Hélio do time de Recrutamento e Seleção whithin valid limits." << std::endl;
        Bureaucrat helio = Bureaucrat("Hélio do time de Recrutamento e Seleção", 30);
        std::cout << helio << std::endl;
        helio.decrementGrade();
        std::cout << helio << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cout << e.what() << std::endl;
    }
}

int main(void)
{
    tryCreateBureaucratOverLimit();
    tryCreateBureaucratUnderLimit();
    tryIncrementBureaucratPastLimit();
    tryDecrementBureaucratPastLimit();
    tryCreateValidBuraucrat();
    tryIncrementBureaucratWhithinLimit();
    tryDecrementBureaucratWhithinLimit();
    return (0);
}
