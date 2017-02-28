/*
 * AE1_Auto.cpp
 *
 *  Created on: 28 Feb 2017
 *      Author: sven
 */


#include <iostream>
#include <string>
#include <map>
#include <vector>

#include <boost/bind.hpp>

using namespace std;

class MyClass {
public:
  typedef std::map<int, string> MyMap;

  MyMap& getMap() {return m_instance; }

private:
  MyMap m_instance;
};

int main()
{
  auto i = 99;
  auto &iRef = i;                            // int &
  auto *iPtr = &i;                            // int *

  const auto iConst = i;                      // volatile int
  static auto iStatic = i;                    // static int

  vector<int> myVec;

  auto itVec = myVec.begin();                 // vector<int>::iterator
  auto p = std::make_pair(1, string("Eins")); // std::pair<int, string>

  //////////////////////////////////////////////////////////////////////////////
  // A More motivating example when this may be usefull
  MyClass cls;

  std::map<int, string> myMap = cls.getMap();
  // -> Redefine Type ?? -> urgs, what a pain!

  MyClass::MyMap myMap2 = cls.getMap();
  // Better, but a typedef is needed

  auto myMap3 = cls.getMap();
  // Easy to use.

  // Template types are sometimes hard to determine, but do we really need to
  // know them? No!
  auto myBinding = boost::bind(&MyClass::getMap, &cls); // Type ???
  auto myMap4 = myBinding();

  return 0;
}
