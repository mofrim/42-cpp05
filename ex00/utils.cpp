
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:37:16 by fmaurer           #+#    #+#             */
/*   Updated: 2025/08/03 19:06:32 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

#include <iostream>
#include <sstream>
#include <string>

void dbg_msg(const std::string& name, const std::string& msg)
{
  if (DEBUG)
    std::cout << "--- \"" << name << "\" " << msg << " ---" << std::endl;
}

void newline() { std::cout << std::endl; }

void print_test_section_header(const std::string& title)
{
  std::cout << "\e[35m[TESTING] __" << title << "__" << "\e[0m" << std::endl;
}

void print_test_topic(const std::string& what)
{
  std::cout << "\e[34m[TEST] " << what << "\e[0m" << std::endl;
}

// convert an integer to string, as there is no such thing in c++1972 :(
std::string toString(long num)
{
  std::ostringstream oss;
  oss << num;
  return (oss.str());
}
