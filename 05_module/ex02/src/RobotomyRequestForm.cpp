/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 02:56:50 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/29 03:13:39 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <fstream>
# include "RobotomyRequestForm.hpp"
# include "Form.hpp"
# include <cstdlib>
# include <ctime>

RobotomyRequestForm::RobotomyRequestForm(void) : Form("Robotomy Request Form", 45, 72)
{
    this->setTarget("HOME");
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :  Form("Robotomy Request Form", 45, 72) 
{
    this->setTarget(target);
    return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    return ;
}

RobotomyRequestForm   &RobotomyRequestForm::operator=(RobotomyRequestForm const &rightHandSide)
{
    this->m_isFormSigned = rightHandSide.getSignedStatus();
    this->m_target = rightHandSide.getTarget();
    return (*this);
}

std::ostream    &operator<<(std::ostream &output, RobotomyRequestForm const &instance)
{
    std::string signedStatus = (instance.getSignedStatus() == true) ? "Yes" : "No";
    return (output << "Form name: " << instance.getName() << '\n'
            << "Grade required to sign: " << instance.getGradeToSign() << "\n"
            << "Grade required to execute: " << instance.getGradeToExecute() << "\n"
            << "Execution target: " << instance.getTarget() << "\n"
            << "Is the form signed?: " << signedStatus << "\n");
}

bool    RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() <= this->getGradeToExecute())
    {
        std::srand(time(NULL));
        std::cout << "*HORRIFYING DRILLING NOISES*" << std::endl;
        if((rand() % 2) == 1)
            std::cout << this->getTarget() << " has been successfully robotomized!" << std::endl;
        else
            std::cout << this->getTarget() << "'s robotomy has failed. Please contact our corporate life insurance provider." << std::endl;
        return (true);
    }
    else
        return (false);

}
