/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 21:06:08 by fmaurer           #+#    #+#             */
/*   Updated: 2025/09/25 12:38:37 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "utils.hpp"

#include <iostream>
#include <string>

// initializing class-global noname bureaucrat counter here as it fits more into
// context than in `main.cpp`.
long Bureaucrat::_noname_bureaucrat_count = 0;

// only in default constructor the noname counter is incremented.
Bureaucrat::Bureaucrat():
  _grade(150), _name("noname" + toString(this->_noname_bureaucrat_count))
{
  this->_noname_bureaucrat_count++;
  dbg_msg(this->_name,
          "Default-Constructor called with grade: " + toString(this->_grade));
}

Bureaucrat::Bureaucrat(const Bureaucrat& other):
  _grade(other._grade), _name(other._name)
{
  dbg_msg(this->_name,
          "Copy-Constructor called with grade: " + toString(this->_grade));
}

// not copying _name as it is supposed to be const per subject
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
  if (this != &other) {
    this->_grade = other._grade;
  }
  dbg_msg(this->_name,
          "Copy-Assginment-Constructor called with grade: " +
              toString(this->_grade) + " (keeping name)");
  return (*this);
}

Bureaucrat::~Bureaucrat() { dbg_msg(this->_name, "Destructor called"); }

Bureaucrat::Bureaucrat(const std::string& name, const long& grade): _name(name)
{
  if (grade < 1)
    throw(Bureaucrat::GradeTooHighException("Grade too high in " + this->_name +
                                            "'s constructor"));
  if (grade > 150)
    throw(Bureaucrat::GradeTooLowException("Grade too low in " + this->_name +
                                           "'s constructor"));
  this->_grade = grade;
  dbg_msg(this->_name, "Constructor called with grade: " + toString(grade));
}

// being strict here: implementing a constructor, even in this simple form is
// implementing a function, so this belongs here not in the header!
Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string msg):
  std::logic_error("Bureaucrat: " + msg)
{}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string msg):
  std::logic_error("Bureaucrat: " + msg)
{}

// post-inc. this is the way BTW. post-inc returns the un-incremented old value
// but applies incrementation to the original. the `(int)` arg is necessary here
// because otherwise the compiler could not distinguish the 2 operator
// definitions just by ther difference in return-type
//
// one more note on pre-/post-increment operators: it is a c++ language
// *requirement* (or part of the design) to define the post-ince op with the
// unsused int param. otherwise the compiler will not know we are trying to
// define a post-inc op here! the reasons are historic and originate in the fact
// that the post-inc-op was added later to the C language. in order to not break
// existing code it needed a different signature from the pre-inc.
Bureaucrat Bureaucrat::operator++(int)
{
  Bureaucrat old(*this);

  if (this->_grade == 1)
    throw(Bureaucrat::GradeTooHighException("Cannot increment " + this->_name +
                                            "'s grade any further!"));
  this->_grade--;
  return (old);
}

// pre-inc
Bureaucrat& Bureaucrat::operator++()
{
  if (this->_grade == 1)
    throw(Bureaucrat::GradeTooHighException("Cannot increment " + this->_name +
                                            "'s grade any further!"));
  this->_grade--;
  return (*this);
}

// post-dec
Bureaucrat Bureaucrat::operator--(int)
{
  Bureaucrat old(*this);

  if (this->_grade == 150)
    throw(Bureaucrat::GradeTooLowException("Cannot decrement " + this->_name +
                                           "'s grade any further!"));
  this->_grade++;
  return (old);
}

// pre-dec
Bureaucrat& Bureaucrat::operator--()
{
  if (this->_grade == 150)
    throw(Bureaucrat::GradeTooLowException("Cannot decrement " + this->_name +
                                           "'s grade any further!"));
  this->_grade++;
  return (*this);
}

const std::string& Bureaucrat::getName() const { return (this->_name); }

unsigned int Bureaucrat::getGrade() const { return (this->_grade); }

void Bureaucrat::setGrade(const long& grade)
{
  if (grade < 1)
    throw(Bureaucrat::GradeTooHighException("setGrade: grade " +
                                            toString(grade) + " too high!"));
  if (grade > 150)
    throw(Bureaucrat::GradeTooLowException("setGrade: grade " +
                                           toString(grade) + " too low!"));
  this->_grade = grade;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
  os << b.getName() << ", bureaucrat grade " << b.getGrade();
  return (os);
}

void Bureaucrat::signForm(Form& f) const
{
  try {
    f.beSigned(*this);
  } catch (const Form::GradeTooLowException& e) {
    std::cout << this->_name << " couldn't sign " << f.getName()
              << " because his grade was too low." << std::endl;
  }
  std::cout << this->_name << " signed " << f.getName() << std::endl;
}
