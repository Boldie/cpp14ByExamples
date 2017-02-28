/*
 * AE1_Initializers.cpp
 *
 *  Created on: 28 Feb 2017
 *      Author: sven
 */

#include <vector>
#include <map>
#include <string>
#include <initializer_list>

#include <boost/assign.hpp>

using namespace std;

int main()
{
  //////////////////////////////////////////////////////////////////////////////
  // The standard way
  {
    vector<int> myVec;
    myVec.push_back(1);
    myVec.push_back(4);
    myVec.push_back(5);
    myVec.push_back(7);

    map<int, string> myMap;
    myMap.insert( std::make_pair(1, string("Eins")));
    myMap.insert( std::make_pair(2, string("Zwei")));
    myMap[3] = "Drei";
    myMap[4] = "Vier";
  }

  //////////////////////////////////////////////////////////////////////////////
  // The boost assign way
  {
    vector<int> myVec = boost::assign::list_of(1)(4)(5)(7);

    map<int, string> myMap
      = boost::assign::list_of( std::make_pair(1, string("Eins")) )
        ( std::make_pair(2, string("Zwei")) )
        ( std::make_pair(3, string("Drei")) )
        ( std::make_pair(4, string("Vier")) );
  }

  //////////////////////////////////////////////////////////////////////////////
  // The C++11
  {
    vector<int> myVec{1,4,5,7};

    map<int, string> myMap = {
          {1, "Eins" }
        , {2, "Zwei" }
        , {3, "Drei" }
        , {4, "Vier" }
    };
  }

  // How this stuff works?
  {
    // First creates an initializer_list class
    std::initializer_list<int> il {1,4,5,7};
    // Calls the constructor for the initializer_list
    vector<int> myVec( il );
  }

  // Some more good things to know
  {
    const float * oData = new float[4] {0.99, 0.189, 0.98, 1.00 };

    /////////////////////
    bool value {true};
    bool value2 = true;

    /////////////////////
    struct Values
    {
      int id;
      string value;
      double factor;
    };

    Values v {1, "URI", 0.98 };

  }

  return 0;
}


