/*
 * B1_ConstructorDelegation.cpp
 *
 *  Created on: 1 Mar 2017
 *      Author: sven
 */

#include <string>
using namespace std;

/**
 * Example for a delegating constructor.
 */
class MyClass {
public:
  MyClass( int a, string b ) {}        // 1: The real constructor.

  MyClass(): MyClass(1, "Eins") {}     // 2: Will call 1

  MyClass( double a): MyClass( int(a), "A" ) {} // 3: Will call 1

  MyClass( char a): MyClass(int(1)) {} // 4: Ill formed, will call 5
  MyClass( int a): MyClass('a') {}     // 5: Ill formed, will call 4

private:
};

int main()
{
  MyClass mc(int(8)); // With gcc 5.4, this will create a segfault!
  // Clang will create an error: clang  -std=c++14 B1_ConstructorDelegation.cpp

  return 0;
}
