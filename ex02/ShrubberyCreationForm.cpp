/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 16:57:23 by fmaurer           #+#    #+#             */
/*   Updated: 2025/09/26 11:24:15 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "utils.hpp"

#include <fstream>

// making the trees class global as this is the way to go!
const std::string ShrubberyCreationForm::_ascii_tree = "\n\
       +\n\
      + +\n\
     + + +\n\
    + + + +\n\
      |||\n";

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137)
    , _target("none")
{
    dbg_msg("ShrubberyCreationForm", "Default constructor called");
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other)
    , _target(other._target)
{
    dbg_msg("ShrubberyCreationForm", "Copy constructor called");
}

// this is private anymway...
ShrubberyCreationForm&
ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    (void)other;
    dbg_msg("ShrubberyCreationForm", "Copy Assignment constructor called");
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    dbg_msg("ShrubberyCreationForm", "Destructor called");
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137)
    , _target(target)
{
    dbg_msg("ShrubberyCreationForm", "Target Constructor called");
}

std::string ShrubberyCreationForm::getTarget() const { return (this->_target); }

// the custom ShrubberyCreationForm formAction. Here the real work is done:
// planting ASCII trees into a file!
bool ShrubberyCreationForm::_executeFormAction() const
{
    std::ofstream shrubFile((this->getTarget() + "_shrubbery").c_str(),
                            std::ofstream::out);
    if (!shrubFile)
        throw(AForm::FormActionFailedException(
            "Could not execute " + this->getName() + "'s action"));
    shrubFile << this->_ascii_tree << this->_ascii_tree << this->_ascii_tree
              << std::endl;
    return (true);
}
