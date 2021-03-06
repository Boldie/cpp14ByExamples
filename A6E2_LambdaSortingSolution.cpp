/*
 *  Created on: 2 Mar 2017
 *      Author: sven
 */

#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
  vector< pair<int, int> > myList { {44,4}, {99,9}, {11,1}, {44,12}, {33,44}, {44, 80} };

  auto sortFunc = [](auto l, auto r)
          {
            if (l.first < r.first) return true;
            else if (l.first == r.first) return l.second < r.second;
            else return false;
          };

  sort(myList.begin(), myList.end(), sortFunc );

  for ( auto i: myList )
    std::cout << " (" << i.first << "," << i.second << ")";

  std::cout << endl;

  return 0;
}
