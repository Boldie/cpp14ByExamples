/*
 * A5_Literals.cpp
 *
 *  Created on: 28 Feb 2017
 *      Author: sven
 */

#include <iostream>

using namespace std;

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

LengthInM operator "" _m(long double v)
{
  return LengthInM(v);
}

LengthInM operator "" _cm(unsigned long long v)
{
  return LengthInM(v/100);
}

int main()
{
  auto l1 = 500_cm;
  auto l2 = 10.0_m;

  auto area = l1 * l2;
  cout << " Area is " << area.get() << endl;

  return 0;
}
