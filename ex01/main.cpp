/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:46:35 by fmaurer           #+#    #+#             */
/*   Updated: 2025/09/25 15:46:40 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "utils.hpp"

#include <iostream>

int main() {

  print_test_section_header("basic stuff about Form class");
  {
    print_test_topic("default constructor & << operator");
    {
      Form bla;
      std::cout << bla << std::endl;
    }
    print_test_topic("direct init constructor & << operator");
    {
      Form bla("bla", 42, 1);
      std::cout << bla << std::endl;
    }
    print_test_topic("getters");
    {
      Form bla("important", 2, 50);
      std::cout << "name: " << bla.getName() << std::endl;
      std::cout << "signGrade: " << bla.getSignGrade() << std::endl;
      std::cout << "execGrade: " << bla.getExecGrade() << std::endl;
      std::cout << "isSigned: " << bla.isSigned() << std::endl;
    }
  }
  print_test_section_header("Form class exceptions");
  {
    print_test_topic("exceptions from constructor");
    {
      try {
        Form at("at", -32, 2);
      } catch (const Form::GradeTooHighException &e) {
        std::cout << "caught error: " << e.what() << std::endl;
      }

      try {
        Form at("at", 151, 2);
      } catch (const Form::GradeTooLowException &e) {
        std::cout << "caught error: " << e.what() << std::endl;
      }

      try {
        Form at("at", 2, -2);
      } catch (const Form::GradeTooHighException &e) {
        std::cout << "caught error: " << e.what() << std::endl;
      }

      try {
        Form at("at", 2, 200);
      } catch (const Form::GradeTooLowException &e) {
        std::cout << "caught error: " << e.what() << std::endl;
      }
    }
  }

  print_test_section_header("Bureaucrat Form interactions");
  {
    Bureaucrat a("Kalle", 41);
    Bureaucrat b("Friedrich", 42);
    Bureaucrat c("Hoinz", 43);
    Form f("VeryImportant", 42, 2);
    a.signForm(f);
    b.signForm(f);
    c.signForm(f);
    std::cout << f << std::endl;
  }

  return (0);
}
