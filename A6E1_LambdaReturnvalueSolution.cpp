/*
 * A6E1_LambdaReturnvalue.cpp
 *
 *  Created on: 2 Mar 2017
 *      Author: sven
 */

#include <iostream>
using namespace std;

int main()
{
  auto testFunc = [](int a, double b) -> double
      {
        if (a>b)
          return a;
        else
          return b;
      };

  std::cout << " testFunc: " << testFunc(4,9) << endl;

  return 0;
}
