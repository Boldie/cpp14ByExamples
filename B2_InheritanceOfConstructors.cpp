/*
 * B2_InheritanceOfConstructors.cpp
 *
 *  Created on: 1 Mar 2017
 *      Author: sven
 */

namespace oldstyle {
  class Base {
  public:
    virtual ~Base() {}

    Base( int i ): m_i(i) {}

  private:
    int m_i;
  };

  class Derived: public Base {
  public:
    Derived( int i ): Base(i) {}

  };
}

namespace cpp14style {
  class Base {
  public:
    virtual ~Base() {}

    Base( int i ): m_i(i) {}

  private:
    int m_i;
  };

  class Derived: public Base {
  public:
    using Base::Base;

  };
}

int main()
{
  oldstyle::Derived osDer( 9 );

  cpp14style::Derived nsDer( 9 );


  return 0;
}

////////////////////////////////////////////////////////////////////////////////
// A word of warning

namespace cpp14style_NonIniitialized {
  class Base {
  public:
    virtual ~Base() {}

    Base( int i ): m_i(i) {}

  private:
    int m_i;
  };

  class Derived: public Base {
  public:
    using Base::Base;

  private:
    bool m_more; // Urgs, not initialized!
  };
}

namespace cpp14style_MultipleInheritance {
  class Base1 {
  public:
    virtual ~Base1() {}
    Base1( int i ): m_i(i) {}
  private:
    int m_i;
  };

  class Base2 {
  public:
    virtual ~Base2() {}
    Base2( int i ): m_i(i) {}
  private:
    int m_i;
  };

  class Derived: public Base1, public Base2 {
  public:
    using Base1::Base1;
    using Base2::Base2;

    // We have to make this explicit here.
    Derived(int v): Base1(v), Base2(v) {}
  };

  void createInstance()
  {
    Derived d( int(8) ); // Which constructor will be called here?
  }
}

