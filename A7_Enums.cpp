/*
 * A7_Enums.cpp
 *
 *  Created on: 2 Mar 2017
 *      Author: sven
 */

int main()
{
  enum class Alert { green, yellow, red };
  enum class Color : int{ red, blue };

  Color c = Color::blue; //ok
  // int ci = c; // Error:  error: cannot convert ‘Color’ to ‘int’ in initialization
  int ci = static_cast<int>(c);

  return 0;
}
