/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 16:57:23 by fmaurer           #+#    #+#             */
/*   Updated: 2025/10/08 10:54:48 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

#include "utils.hpp"

#include <iostream>

PresidentialPardonForm::PresidentialPardonForm():
  AForm("PresidentialPardonForm", 25, 5), _target("none")
{
  dbg_msg("PresidentialPardonForm", "Default constructor called");
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm& other): AForm(other), _target(other._target)
{
  dbg_msg("PresidentialPardonForm", "Copy constructor called");
}

// this is private anymway...
PresidentialPardonForm& PresidentialPardonForm::operator=(
    const PresidentialPardonForm& other)
{
  (void)other;
  dbg_msg("PresidentialPardonForm", "Copy Assignment constructor called");
  return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
  dbg_msg("PresidentialPardonForm", "Destructor called");
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target):
  AForm("PresidentialPardonForm", 25, 5), _target(target)
{
  dbg_msg("PresidentialPardonForm", "Target Constructor called");
}

std::string PresidentialPardonForm::getTarget() const
{
  return (this->_target);
}

// the custom PresidentialPardonForm formAction. Here the real work is done:
// make drilling noise, robotomize target with 50%
bool PresidentialPardonForm::_executeFormAction() const
{
  std::cout << "* Target " + this->_target +
          " has been pardoned by Zaphod Beeblebrox *"
            << std::endl;

  return (true);
}
