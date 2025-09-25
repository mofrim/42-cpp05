/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:46:35 by fmaurer           #+#    #+#             */
/*   Updated: 2025/09/25 08:27:59 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "utils.hpp"

#include <cassert>
#include <iostream>
#include <limits>

int main() {

  print_test_section_header("constructors");
  {
    print_test_topic("default constructor");
    Bureaucrat at0;
    std::cout << at0 << std::endl;

    // direct constructor (little recap: is prefered over copy assignement as
    // the latter creates a temporary object before copying values)
    print_test_topic("direct constructor");
    Bureaucrat at1("kalle", 42);
    std::cout << at1 << std::endl;
  }

  print_test_section_header("decrement");
  {
    // decrement
    Bureaucrat at0("at0", 1);
    std::cout << at0 << std::endl;
    std::cout << at0-- << std::endl;
    std::cout << at0 << std::endl;
    std::cout << --at0 << std::endl;

    print_test_section_header("increment");

    Bureaucrat at1("at1", 42);
    std::cout << at1 << std::endl;
    std::cout << at1++ << std::endl;
    std::cout << at1 << std::endl;
    std::cout << ++at1 << std::endl;
  }

  print_test_section_header("exceptions");
  {
    print_test_topic(
        "grade incrementation until >1, catching generic exception");
    {
      Bureaucrat at("at", 42);
      bool       caught_execption = false;
      while (!caught_execption)
        try {
          at++;
        } catch (std::exception& e) {
          caught_execption = true;
          std::cout << "caught exception: " << e.what() << std::endl;
        }
    }

    print_test_topic(
        "grade incrementation until >1, catching generic exception");
    {
      Bureaucrat at("at", 42);
      bool       caught_execption = false;
      while (!caught_execption)
        try {
          at--;
        } catch (std::exception& e) {
          caught_execption = true;
          std::cout << "caught exception: " << e.what() << std::endl;
        }
    }

    print_test_topic("exception in constructor, catching specific exeception");
    {
      try {
        Bureaucrat at1("hoinz_GradeTooLow", 151);
      } catch (Bureaucrat::GradeTooLowException& e) {
        std::cout << "caught exeception: " << e.what() << std::endl;
      }
      try {
        Bureaucrat at2("hoinz_GradeTooHigh", -123);
      } catch (Bureaucrat::GradeTooHighException& e) {
        std::cout << "caught exeception: " << e.what() << std::endl;
      }
    }

    print_test_topic("exception in setGrade()");
    {
      Bureaucrat at("ZeroCool", 23);
      try {
        at.setGrade(-400);
      } catch (Bureaucrat::GradeTooHighException& e) {
        std::cout << "caught exeception: " << e.what() << std::endl;
      }
      try {
        at.setGrade(500);
      } catch (Bureaucrat::GradeTooLowException& e) {
        std::cout << "caught exeception: " << e.what() << std::endl;
      }
    }

    print_test_topic("testing the limits...");
    {
      Bureaucrat at("ZeroCool", 23);
      try {
        at.setGrade(std::numeric_limits<long>::max() + 1);
      } catch (std::exception& e) {
        std::cout << "caught exeception: " << e.what() << std::endl;
      }
    }
  }

  print_test_section_header("default constructor naming");
  {
    Bureaucrat *bs = new Bureaucrat[10];
    for (size_t i = 0; i < 10; i++) {
      std::cout << "hi, my name is " << bs[i].getName() << std::endl;
    }
    delete[] bs;
  }

  return (0);
}
