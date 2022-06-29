/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 02:50:23 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/29 03:06:20 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include "Form.hpp"

class RobotomyRequestForm : public Form
{
    private:
        bool					execute(Bureaucrat const &executor) const;

    public:
        RobotomyRequestForm(void);
        RobotomyRequestForm(std::string target);
        ~RobotomyRequestForm(void);
		RobotomyRequestForm(RobotomyRequestForm const& instance);
		RobotomyRequestForm	&operator=(RobotomyRequestForm const &rightHandSide);
};

std::ostream &operator<<(std::ostream &output, RobotomyRequestForm const &instance);

#endif
