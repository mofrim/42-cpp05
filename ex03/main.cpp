/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:46:35 by fmaurer           #+#    #+#             */
/*   Updated: 2025/10/08 09:25:43 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "utils.hpp"

#include <iostream>

int main()
{
  print_test_section_header("intern at work");
  {
    print_test_topic("intern making ShrubberyCreationForm");
    Intern     i;
    AForm     *s = i.makeForm("ShrubberyCreationForm", "Sun");
    Bureaucrat horst("Horst", 1);
    horst.signForm(*s);
    horst.executeForm(*s);
    delete s;
    print_test_topic("intern making PresidentialPardonForm");
    s = i.makeForm("PresidentialPardonForm", "Sun");
    horst.signForm(*s);
    horst.executeForm(*s);
    delete s;
    print_test_topic("intern making RobotomyRequestForm");
    s = i.makeForm("RobotomyRequestForm", "Sun");
    horst.signForm(*s);
    horst.executeForm(*s);
    delete s;
  }
  print_test_section_header("things going wrong");
  {
    print_test_topic("trying to create non-existent form");
    {
      Intern i;
      AForm *s;

      try {
        s = i.makeForm("Blabla", "blub");
      } catch (const std::exception& e) {
        std::cout << "caught exception: " << e.what() << std::endl;
      }
      (void)s;
    }
    print_test_topic("same thing with catching exact exception");
    {
      Intern i;
      AForm *s;

      try {
        s = i.makeForm("Blabla", "blub");
      } catch (const Intern::InexistentFormException& e) {
        std::cout << "caught exception: " << e.what() << std::endl;
      }
      (void)s;
    }
    print_test_topic("same thing with catching wrong exception");
    {
      Intern i;
      AForm *s;

      try {
        s = i.makeForm("Blabla", "blub");
      } catch (const std::overflow_error& e) {
        std::cout << "caught exception: " << e.what() << std::endl;
      } catch (...) {
        std::cout << "you see! only caught by fall-through catch." << std::endl;
      }
      (void)s;
    }
  }

  return (0);
}
