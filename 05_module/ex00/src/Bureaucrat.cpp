/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:01:05 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/26 01:34:17 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

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

std::ostream &operator<<(std::ostream &output, Bureaucrat const &rightHandSide)
{
	return (output << rightHandSide.getName() << ", bureaucrat grade " << rightHandSide.getGrade());
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
