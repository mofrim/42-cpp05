/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:46:35 by fmaurer           #+#    #+#             */
/*   Updated: 2025/10/01 13:15:28 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "utils.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
  // TODO: investigate the randomness of rand()! do we get a uniform
  // distribution? meaning p(w) = 1/10 for a range of [1..10]?
  srand(time(0));

  print_test_section_header("ShrubberyCreationForm");
  {
    print_test_topic("execution");
    {
      Bureaucrat            at("at", 42);
      ShrubberyCreationForm s("bla");
      ShrubberyCreationForm sc("everywhere");
      std::cout << s << std::endl;
      std::cout << sc << std::endl;
      s.beSigned(at);
      sc.beSigned(at);
      std::cout << s << std::endl;
      std::cout << sc << std::endl;
      at.executeForm(s);
      at.executeForm(sc);

      const std::string cmd("cat ./bla_shrubbery");
      print_test_file_header(cmd);
      if (std::system(cmd.c_str()) != 0)
        std::cout << "couldn't output shrubbery-file!" << std::endl;
      print_test_file_header("---");

      const std::string cmdc("cat ./everywhere_shrubbery");
      print_test_file_header(cmdc);
      if (std::system(cmd.c_str()) != 0)
        std::cout << "couldn't output shrubbery-file!" << std::endl;
      print_test_file_header("---");
    }

    print_test_topic("exceptions");
    {
      Bureaucrat            at0("Bob Low", 150);
      Bureaucrat            at1("Bob High", 1);
      ShrubberyCreationForm s("moon");

      // bob low's grade is too low
      try {
        s.beSigned(at0);
      } catch (const AForm::GradeTooLowException& e) {
        std::cout << "cannot sign form: " << e.what() << std::endl;
      }

      // bob high's grade is high enough, but the form is not yet signed.
      try {
        at1.executeForm(s);
      } catch (const AForm::FormNotSignedException& e) {
        std::cout << "cannot execute form: " << e.what() << std::endl;
      }

      s.beSigned(at1);
      at1.executeForm(s);
    }
  }

  print_test_section_header("RobotomyRequestForm");
  {
    Bureaucrat          killa("Killa", 23);
    RobotomyRequestForm rrr("Homer");

    killa.signForm(rrr);
    killa.executeForm(rrr);
    killa.executeForm(rrr);
    killa.executeForm(rrr);
    killa.executeForm(rrr);
    killa.executeForm(rrr);
    killa.executeForm(rrr);
    killa.executeForm(rrr);
    killa.executeForm(rrr);
  }

  return (0);
}
