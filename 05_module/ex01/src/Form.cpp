/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:04:30 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/27 01:46:45 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"
# include "Bureaucrat.hpp"

Form::Form(void) : m_name("Form 00A"), m_gradeRequiredToExecute(150), m_gradeRequiredToSign(150), m_isFormSigned(false)
{
    return ;
}

Form::Form(std::string name, int gradeRequiredToExecute, int gradeRequiredToSign) : m_name(name),
                                                                                    m_gradeRequiredToExecute(gradeRequiredToExecute),
                                                                                    m_gradeRequiredToSign(gradeRequiredToSign),
                                                                                    m_isFormSigned(false)
{
    validateGrade(this->m_gradeRequiredToExecute);
    validateGrade(this->m_gradeRequiredToSign);
    return ;
}

Form::~Form(void)
{
    return ;
}

Form::Form(Form const &instancedObject) :   m_name(instancedObject.getName()),
                                            m_gradeRequiredToExecute(instancedObject.getGradeToExecute()),
                                            m_gradeRequiredToSign(instancedObject.getGradeToSign())
{
    *this = instancedObject;
}

Form &Form::operator=(Form const &rightHandSide) 
{
    this->m_isFormSigned = rightHandSide.getSignedStatus();
    return (*this);
}

std::ostream &operator<<(std::ostream &output, Form const &instance)
{
    std::string signedStatus = (instance.getSignedStatus() == true) ? "Yes" : "No";
    return (output << "Form name: " << instance.getName() << '\n'
            << "Grade required to sign: " << instance.getGradeToSign() << "\n"
            << "Grade required to execute: " << instance.getGradeToExecute() << "\n"
            << "Is the form signed?: " << signedStatus << "\n");
}

void        Form::validateGrade(int grade) const
{
    if (grade < 1)
        throw Form::GradeTooHighException();
    if (grade > 150)
        throw Form::GradeTooLowException();
    return ;
}

std::string	Form::getName(void) const
{
    return (this->m_name);
}

int			Form::getGradeToSign(void) const
{
    return (this->m_gradeRequiredToSign);
}

int			Form::getGradeToExecute(void) const
{
    return (this->m_gradeRequiredToExecute);
}

int			Form::getSignedStatus(void) const
{
    return (this->m_isFormSigned);
}

void		Form::beSigned(Bureaucrat signatory)
{
	if (signatory.getGrade() > this->getGradeToSign())
		throw Form::RequiredGradeToSignTooLowException();
	else if (this->getSignedStatus() == true)
        throw Form::FormAlreadySignedException();
    else
		this->m_isFormSigned = true;
	return ;
}
