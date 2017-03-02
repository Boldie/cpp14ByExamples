all:  A1_Initializers A2_Auto A3_RangeBasedForLoop A3E_RangeBased_Solution A4_Decltype A5_Literals A6_Lambda A6E1_LambdaReturnvalue B1_ConstructorDelegation

A1_Initializers: A1_Initializers.cpp
	g++ -std=c++11 -o  $@  $^

A2_Auto: A2_Auto.cpp
	g++ -std=c++11 -o  $@  $^

A3_RangeBasedForLoop: A3_RangeBasedForLoop.cpp
	g++ -std=c++11 -o  $@  $^

A3E_RangeBased_Solution: A3E_RangeBased_Solution.cpp
	g++ -std=c++11 -o  $@  $^

A4_Decltype: A4_Decltype.cpp
	g++ -std=c++11 -o  $@  $^

A5_Literals: A5_Literals.cpp
	g++ -std=c++11 -o  $@  $^

A6_Lambda: A6_Lambda.cpp
	g++ -std=c++14 -o  $@  $^

A6E1_LambdaReturnvalue: A6E1_LambdaReturnvalue.cpp
	g++ -std=c++14 -o  $@  $^

B1_ConstructorDelegation: B1_ConstructorDelegation.cpp
	g++ -std=c++14 -o  $@  $^

