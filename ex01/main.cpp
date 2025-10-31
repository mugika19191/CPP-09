#include <iostream>
#include "RPN.hpp"

int main(int count, char **args)
{
	if (count != 2)
		return 1;
	RPN stacksss;
	stacksss.loop(args[1]);
	return 0;
}