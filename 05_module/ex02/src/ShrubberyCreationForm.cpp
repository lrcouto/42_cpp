/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 02:35:00 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/29 01:48:06 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <fstream>
# include "ShrubberyCreationForm.hpp"
# include "Form.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("Shrubbery Creation Form", 137, 145)
{
    this->setTarget("HOME");
    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name, std::string target) :  Form(name, 137, 145) 
{
    this->setTarget(target);
    return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    return ;
}

ShrubberyCreationForm   &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rightHandSide)
{
    this->m_isFormSigned = rightHandSide.getSignedStatus();
    this->m_target = rightHandSide.getTarget();
    return (*this);
}

std::ostream    &operator<<(std::ostream &output, ShrubberyCreationForm const &instance)
{
    std::string signedStatus = (instance.getSignedStatus() == true) ? "Yes" : "No";
    return (output << "Form name: " << instance.getName() << '\n'
            << "Grade required to sign: " << instance.getGradeToSign() << "\n"
            << "Grade required to execute: " << instance.getGradeToExecute() << "\n"
            << "Execution target: " << instance.getTarget() << "\n"
            << "Is the form signed?: " << signedStatus << "\n");
}

bool    ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() <= this->getGradeToExecute())
    {
        std::string fileName = this->getTarget() + "_shrubbery";
        std::ofstream outputFile(fileName.c_str(), std::ios::out | std::ios::trunc);

        std::string shrubs = "               ,@@@@@@@,\n       ,,,.   ,@@@@@@/@@,  .oo8888o.\n    ,&%%&%&&%,@@@@@/@@@@@@,8888/88/8o\n   ,%&/%&&%&&%,@@@/@@@/@@@88/88888/88'\n   %&&%&%&/%&&%@@/@@/ /@@@88888/88888'\n   %&&%/ %&%%&&@@/ V /@@' `88/8 `/88'\n   `&%/ ` /%&'    |.|        / '|8'\n       |o|        | |         | |\n       |.|        | |         | |\n    \\/ ._///_/__/  ,/_//__\\/.  /_//__/_\n";
        outputFile << shrubs << std::endl;
        outputFile.close();
        return (true);
    }
    else
        return (false);

}
