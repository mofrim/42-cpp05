/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constfuncpointarr.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 09:37:06 by fmaurer           #+#    #+#             */
/*   Updated: 2025/10/08 09:41:18 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int *func1(int i)
{
  int *j = new int;
  *j     = i + 1;
  return (j);
}

int *func2(int i)
{
  int *j = new int;
  *j     = i + 2;
  return (j);
}

int *func3(int i)
{
  int *j = new int;
  *j     = i + 3;
  return (j);
}

int main(void)
{
  int *p;
  int *(*const funcArr0[])(int) = {func1, func2, func3};
  int *(*const funcArr1[])(int) = {func1, func2, func3};

  // now stuff like this is not possible anymore because of const qualifier:
  // funcArr0[0] = func2;

  p = funcArr0[0](42);
  std::cout << "p = " << *p << std::endl;
  delete p;
  p = funcArr0[1](42);
  std::cout << "p = " << *p << std::endl;
  delete p;
  p = funcArr0[2](42);
  std::cout << "p = " << *p << std::endl;
  delete p;

  return (0);
}
