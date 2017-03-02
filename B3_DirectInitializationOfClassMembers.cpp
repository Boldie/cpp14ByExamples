/*
 * B3_DirectInitializationOfClassMembers.cpp
 *
 *  Created on: 1 Mar 2017
 *      Author: sven
 */

class MyClass
{
public:
  MyClass( int value ): m_myValue(value + 534) {}

  int getValue() const { return m_myValue; }

private:
  int m_myValue;
};

class BetterMyClass
{
public:
  BetterMyClass( int value ): m_myValue(value), m_isCalculated(false) {}

  // Some times later this constructor was added, but someone forgot to add the
  // isCalculated flag ... urgs, a lot of debugging may needed to find this issue.
  BetterMyClass( double value ): m_myValue(int(value)) {}

  int getValue() {
    if (!m_isCalculated) {
      m_myValue += 534;
      m_isCalculated = true;
    }
    return m_myValue;
  }

private:
  int m_myValue;

  bool m_isCalculated;
};


class BetterCpp14MyClass
{
public:
  BetterCpp14MyClass( int value ): m_myValue(value) {}
  BetterCpp14MyClass( double value ): m_myValue(int(value)) {}

  int getValue() {
    if (!m_isCalculated) {
      m_myValue += 534;
      m_isCalculated = true;
    }
    return m_myValue;
  }

private:
  int m_myValue;

  bool m_isCalculated = false;
};

int main()
{
  return 0;
}
