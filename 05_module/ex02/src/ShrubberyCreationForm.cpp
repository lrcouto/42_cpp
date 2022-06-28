/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 02:35:00 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/28 03:29:30 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"
# include "Form.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) :    m_name("Form 00A")
                                                        m_gradeRequiredToExecute(137),
                                                        m_gradeRequiredToSign(145),
                                                        m_isFormSigned(false),
                                                        m_target("Home")
{
    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name, std::string target) :    m_name(name)
                                                                                        m_gradeRequiredToExecute(137),
                                                                                        m_gradeRequiredToSign(145),
                                                                                        m_isFormSigned(false),
                                                                                        m_target(target)
{
    return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& instancedObject) :    m_name(instancedObject.getName()),
                                                                                                m_gradeRequiredToExecute(instancedObject.getGradeToExecute()),
                                                                                                m_gradeRequiredToSign(instancedObject.getGradeToSign())
                                                                                                m_target(instancedObject.getTarget())
{
    *this = instancedObject;
}

ShrubberyCreationForm   &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rightHandSide)
{
    this->m_isFormSigned = rightHandSide.getSignedStatus();
    return (*this);
}

std::ostream    &operator<<(std::ostream &output, ShrubberyCreationForm const &instance)
{
    std::string signedStatus = (instance.getSignedStatus() == true) ? "Yes" : "No";
    return (output << "Form name: " << instance.getName() << '\n'
            << "Grade required to sign: " << instance.getGradeToSign() << "\n"
            << "Grade required to execute: " << instance.getGradeToExecute() << "\n"
            << "Execution target: " << instance.getGradeToExecute() << "\n"
            << "Is the form signed?: " << signedStatus << "\n");
}

std::string     ShrubberyCreationForm::getTarget(void);
{
    return (this->m_target);
}

bool    ShrubberyCreationForm::execute(Bureaucrat const &executor) const;
{
    //TODO: write this
}
