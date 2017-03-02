/*
 * A6_Lambda.cpp
 *
 *  Created on: 28 Feb 2017
 *      Author: sven
 */

#include <iostream>
#include <list>
#include <algorithm>

#include <boost/signals2.hpp>

using namespace std;


class SignalTester {
public:
  template<class SIG>
  void connectTo( SIG& signal) {
    signal.connect( [this](string s) { slotToReact(s); } );

    // Signal connection using boost::bind
    // signal.connect( boost::bind( &SignalTester::slotToReact, this, _1 ) );
  }

  void slotToReact( string s ) {
    std::cout << " SignalTester got " << s << endl;
  }
};

int main()
{
  const list<int> myList {1,5,10,90,102, 837, 50, 49, 51};
  const vector<string> myStringVec {"Eins","Zwei","Drei","Vier"};
  /////////////////////////////////////////////////////////////////////////////
  // Classical function object
  {
    struct Functor
    {
      Functor(int& value): m_v(value) {}
      bool operator()(int v) {
        return v > m_v;
      }

      int& m_v;
    };

    int i = 50;
    int myCounter = count_if( myList.begin(), myList.end(), Functor(i) );
    // fo(1);
    // fo(5);
    // ....
    cout << "Classical way: Found " << myCounter << " objects > 50." << endl;
  }



  /////////////////////////////////////////////////////////////////////////////
  // Count numbers > 50 inside the list ...
  {
    int value = 50;
    int count = count_if( myList.begin(), myList.end(),
        [&value](int v){ return v > value; }
    );

    cout << "Lambda way: Found " << count << " objects > 50." << endl;
  }

  {
    std::cout << "Separator lambdas .." << endl;
    string separator = " * ";
    auto sepAstClosure = [separator](int v)
        {std::cout << separator << v; };

    for_each( myList.begin(), myList.end(), sepAstClosure);
    std::cout << endl;

    separator = " XX ";
    auto sepXXClosure = [=](int v)
        {std::cout << separator << v; };

    for_each( myList.begin(), myList.end(), sepXXClosure);
    std::cout << endl;

    auto sepQuestionClosure = [&](int v)
        {std::cout << separator << v; };
    separator = " ??? ";

    for_each( myList.begin(), myList.end(), sepQuestionClosure);
    std::cout << endl;
  }

  {
    std::cout << "Generic lambdas .." << endl;
    // Task: create comma separated output from list:
    // Using mutable lambda with initialized capture variable
    // And a generic lambda function
    auto printingFunc = [first=true](auto v) mutable {
        if(!first)
          std::cout << ", ";
        else
          first=false;
        std::cout << v;
      };

    for_each( myList.begin(), myList.end(), printingFunc);
    std::cout << endl;

    // Use same lambda on different list types:
    for_each( myStringVec.begin(), myStringVec.end(), printingFunc);
    std::cout << endl;
  }

  {
    std::cout << "boost Signals with lambdas" << endl;
    boost::signals2::signal< void(string) > mySignal;

    int counter = 0;
    auto signalCounter = [&](string s){ ++counter; };
    auto signalPrinter = [](string s){ std::cout << "Signal happend: " << s << endl; };

    mySignal.connect( signalCounter );
    mySignal.connect( signalPrinter );

    SignalTester st;
    st.connectTo(mySignal);

    mySignal("Eins");
    mySignal("Zwei");

    std::cout << "We have " << counter << " counts." << endl;
  }


}
