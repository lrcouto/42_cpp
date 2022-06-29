/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 03:16:52 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/29 03:18:41 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <fstream>
# include "PresidentialPardonForm.hpp"
# include "Form.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : Form("Presidential Pardon Form", 5, 25)
{
    this->setTarget("HOME");
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :  Form("Presidential Pardon Form", 5, 25) 
{
    this->setTarget(target);
    return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    return ;
}

PresidentialPardonForm   &PresidentialPardonForm::operator=(PresidentialPardonForm const &rightHandSide)
{
    this->m_isFormSigned = rightHandSide.getSignedStatus();
    this->m_target = rightHandSide.getTarget();
    return (*this);
}

std::ostream    &operator<<(std::ostream &output, PresidentialPardonForm const &instance)
{
    std::string signedStatus = (instance.getSignedStatus() == true) ? "Yes" : "No";
    return (output << "Form name: " << instance.getName() << '\n'
            << "Grade required to sign: " << instance.getGradeToSign() << "\n"
            << "Grade required to execute: " << instance.getGradeToExecute() << "\n"
            << "Execution target: " << instance.getTarget() << "\n"
            << "Is the form signed?: " << signedStatus << "\n");
}

bool    PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() <= this->getGradeToExecute())
    {
        std::cout << this->getTarget() << ", you have been pardoned by Zaphod Beeblebrox." << std::endl;
        return (true);
    }
    else
        return (false);

}
