/*
 * A1_RangeBased.cpp
 *
 *  Created on: 28 Feb 2017
 *      Author: sven
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  {
    vector<int> myVec{1,2,3,4,5,6,7,8,9,10};

    for (auto &x: myVec)
      x = x * x;

    for (const auto x: myVec)
      cout << x << " ";
    cout << endl;
  }

  {
    vector<int> myVec{1,2,3,4,5,6,7,8,9,10};

    for_each(myVec.begin(), myVec.end(), [](int& x){ x = x * x; });

    for (const auto x: myVec)
      cout << x << " ";
    cout << endl;
  }

  return 0;
}
