/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:01:05 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/27 01:43:06 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "Form.hpp"

Bureaucrat::Bureaucrat(void) : m_name("Frederico Menezes de Sousa Jr."), m_grade(75)
{
    return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : m_name(name), m_grade(grade)
{
    this->checkGrade();
    return ;
}

Bureaucrat::~Bureaucrat(void)
{
    return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const &instancedObject)
{
    *this = instancedObject;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rightHandSide)
{
    this->m_grade = rightHandSide.getGrade();
    return (*this);
}

std::ostream &operator<<(std::ostream &output, Bureaucrat const &instance)
{
	return (output << instance.getName() << ", bureaucrat grade " << instance.getGrade());
}

std::string	Bureaucrat::getName(void) const
{
    return (this->m_name);
}

int			Bureaucrat::getGrade(void) const
{
    return (this->m_grade);
}

void		Bureaucrat::incrementGrade(void)
{
    this->m_grade--;
    this->checkGrade();
    return ;
}

void		Bureaucrat::decrementGrade(void)
{
    this->m_grade++;
    this->checkGrade();
    return ;
}

void	Bureaucrat::checkGrade(void)
{
	if (this->m_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (this->m_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void        Bureaucrat::signForm(Form &formToSign)
{
    try 
    {
		formToSign.beSigned(*this);
		std::cout << this->m_name << " wants to sign " << formToSign.getName() << std::endl;
	} 
	catch (const Form::RequiredGradeToSignTooLowException& e)
    {
		std::cout << "\033[1;31m" << this->m_name << "'s grade is too low to sign " << formToSign.getName() << "\033[0m" << std::endl;
	}
	catch (const Form::FormAlreadySignedException& e)
    {
		std::cout << "\033[1;31m" << formToSign.getName() << " has already been signed" << "\033[0m" << std::endl;
	}
}
