/*
 * A4_Decltype.cpp
 *
 *  Created on: 28 Feb 2017
 *      Author: sven
 */

#include <iostream>
using namespace std;

int func(int in)
{
  return in + 5;
}

int main()
{
  int i = 99;
  decltype(i) ii = i; // int

  const auto ci = i;  // const int
  decltype(ci) cii = ci; // const int

  const decltype(i) ci2 = i; // const int

  auto myFunc = func;  // func*
  decltype(myFunc) myFuncD = myFunc; // (int)(*)(int)

  myFunc(9);
  myFuncD(99);

  myFunc = func;
  myFuncD = func;

  auto & myFuncRef = func;  // (int)(*)(int)
  decltype(myFunc) myFuncRefD = myFuncRef; // (int)(*)(int)

  myFuncRef(9);
  myFuncRefD(99);

  return 0;
}

////////////////////////////////////////////////////////////////////////////////
// Intermezzo: New function definition
int add(int a, int b) {
  return a + b;
}

auto add2(int a, int b) -> int {
  return a+b;
}

////////////////////////////////////////////////////////////////////////////////
class AreaInSquareMeter;

class LengthInM{
public:
  explicit LengthInM(double value): m_value(value) {}

  LengthInM operator+(LengthInM right) const;
  LengthInM operator*(double right) const;
  AreaInSquareMeter operator*(LengthInM right) const ;

  double get() const { return m_value; }
private:
  double m_value;
};

class AreaInSquareMeter{
public:
  explicit AreaInSquareMeter( double value ): m_value(value) {}

  double get() const {return m_value;}
private:
  double m_value;
};

LengthInM LengthInM::operator+(LengthInM right) const {
  return LengthInM( m_value + right.m_value);
}

LengthInM LengthInM::operator*(double right) const {
  return LengthInM( m_value * right);
}

AreaInSquareMeter LengthInM::operator*(LengthInM right) const {
  return AreaInSquareMeter( m_value * right.m_value);
}


void calculateArea()
{
  LengthInM l1(  5 );
  LengthInM l2( 10 );

  auto area = l1 * l2;
  cout << " Area is " << area.get() << endl;
}

void calculateSquare()
{
  LengthInM len(  5 );
  auto area = len * len;
  cout << " Area is " << area.get() << endl;
}

template<class T>
auto square(const T& in) -> decltype( in * in) {
  return in * in;
}

void calculateSquareTemplated()
{
  LengthInM len(  5 );
  auto area = square(len);
  cout << " Area is " << area.get() << endl;

  double value = 5.55;
  auto squaredValue = square(len);
}
