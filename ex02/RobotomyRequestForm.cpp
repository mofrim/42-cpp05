/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 16:57:23 by fmaurer           #+#    #+#             */
/*   Updated: 2025/10/08 07:16:14 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "utils.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm():
  AForm("RobotomyRequestForm", 72, 45), _target("none")
{
  srand(time(0));
  dbg_msg("RobotomyRequestForm", "Default constructor called");
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other):
  AForm(other), _target(other._target)
{
  dbg_msg("RobotomyRequestForm", "Copy constructor called");
}

// this is private anymway...
RobotomyRequestForm& RobotomyRequestForm::operator=(
    const RobotomyRequestForm& other)
{
  (void)other;
  dbg_msg("RobotomyRequestForm", "Copy Assignment constructor called");
  return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
  dbg_msg("RobotomyRequestForm", "Destructor called");
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target):
  AForm("RobotomyRequestForm", 72, 45), _target(target)
{
  srand(time(0));
  dbg_msg("RobotomyRequestForm", "Target Constructor called");
}

std::string RobotomyRequestForm::getTarget() const { return (this->_target); }

// the custom RobotomyRequestForm formAction. Here the real work is done:
// make drilling noise, robotomize target with 50%
bool RobotomyRequestForm::_executeFormAction() const
{
  int randnum = get_rand_range(1, 10);
  std::cout << "* Rrrrrrrrrrrr drrrrrd drrr rrrttt *" << std::endl;
  if (randnum > 5)
    std::cout << "* Target \"" << this->_target << "\" has been robotomized *"
              << std::endl;
  else
    std::cout << "* Robotomization for target \"" << this->_target
              << "\" failed *" << std::endl;
  return (true);
}
