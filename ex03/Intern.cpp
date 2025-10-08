/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 07:28:38 by fmaurer           #+#    #+#             */
/*   Updated: 2025/10/08 09:19:40 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "utils.hpp"

AForm *createShrubberyCreationForm(const std::string& target)
{
  return (new ShrubberyCreationForm(target));
}

AForm *createPresidentialPardonForm(const std::string& target)
{
  return (new PresidentialPardonForm(target));
}

AForm *createRobotomyRequestForm(const std::string& target)
{
  return (new RobotomyRequestForm(target));
}

const std::string Intern::_allowedForms[3] = {"ShrubberyCreationForm",
    "PresidentialPardonForm",
    "RobotomyRequestForm"};

AForm *(*const Intern::_formFuncs[3])(const std::string&) = {
    createShrubberyCreationForm,
    createPresidentialPardonForm,
    createRobotomyRequestForm,
};

const int Intern::_numOfForms = 3;

Intern::Intern() { dbg_msg("Intern", "Default constructor has been called."); }

Intern::Intern(const Intern& other) { (void)other; }

Intern& Intern::operator=(const Intern& other)
{
  (void)other;
  return (*this);
}

Intern::~Intern() { dbg_msg("Intern", "Destructor has been called."); }

Intern::InexistentFormException::InexistentFormException(
    const std::string& msg):
  std::logic_error("Intern::InexistentFormException: " + msg)
{}

int Intern::_getFormIdx(const std::string& fname) const
{
  int i = 0;
  while (i < this->_numOfForms && fname != this->_allowedForms[i])
    i++;
  return (i);
}

AForm *Intern::makeForm(const std::string& fname,
    const std::string&                     target) const
{
  int formIdx = this->_getFormIdx(fname);

  if (formIdx >= this->_numOfForms)
    throw Intern::InexistentFormException(
        "Form \"" + fname + "\" does not exist!");
  return (this->_formFuncs[formIdx](target));
}
