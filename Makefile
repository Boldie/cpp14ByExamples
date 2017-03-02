all:  A1_Initializers A2_Auto A3_RangeBasedForLoop A3E_RangeBased_Solution A4_Decltype A5_Literals A6_Lambda A6E1_LambdaReturnvalueSolution A6E2_LambdaSortingSolution B1_ConstructorDelegation B4_ExplicitClassDefinitions

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

A6E1_LambdaReturnvalueSolution: A6E1_LambdaReturnvalueSolution.cpp
	g++ -std=c++14 -o  $@  $^

A6E2_LambdaSortingSolution: A6E2_LambdaSortingSolution.cpp
	g++ -std=c++14 -o  $@  $^

B1_ConstructorDelegation: B1_ConstructorDelegation.cpp
	g++ -std=c++14 -o  $@  $^

B4_ExplicitClassDefinitions: B4_ExplicitClassDefinitions.cpp
	g++ -std=c++14 -o  $@  $^

