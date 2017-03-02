/*
 * B4_ExplicitClassDefinitions.cpp
 *
 *  Created on: 1 Mar 2017
 *      Author: sven
 */

class NonCopyableClass {
public:
  NonCopyableClass() = default;
  NonCopyableClass( const NonCopyableClass& ) = delete;

  NonCopyableClass& operator=( const NonCopyableClass& ) = delete;
};

int main()
{
  NonCopyableClass c;
  // NonCopyableClass c2(c);
  return 0;
}
