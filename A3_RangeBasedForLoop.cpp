/*
 * rangeBasedForLoog.cpp
 *
 *  Created on: 28 Feb 2017
 *      Author: sven
 */
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
  vector<int> myVec{1,11,21,31,41};

  cout << "Simple Range based for loop with auto and vector:" << endl;

  for (int elem: myVec)
    cout << " " << elem << std::endl;

  //////////////////////////////////////////////////////////////////////////////
  cout << "Manipulate the vector" << endl;

  for ( int& elem: myVec)
    elem--;

  for (auto elem: myVec)
    cout << elem << " ";
  cout << endl;

  //////////////////////////////////////////////////////////////////////////////
  cout << "Example for using a map within a range based for loop: " << endl;
  map<int, string> myMap{
      { 5, "Fünf"}
    , { 7, "Sieben"}
    , { 10, "Zehn"}
  };

  for (auto v: myMap)
    cout << v.first << " => " << v.second << endl;

  for( map<int, string>::const_iterator it = myMap.begin(); it != myMap.end(); ++it)
    cout << it->first << " => " << it->second << endl;

  //////////////////////////////////////////////////////////////////////////////
  cout << "Using a direct expression to iterate over some elements" << endl;
  for (auto x: {1,2,4,8,16,32,64})
    cout << x << " ";
  cout << endl;

  return 0;
}
