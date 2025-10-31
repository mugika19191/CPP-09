#include <stack>
#include <iostream>
#include <cstdlib>

class RPN
{
	public:
		std::stack<int> stack;
		RPN();
		~RPN();
		void loop(std::string vars);
		void do_add();
		void do_sub();
		void do_mult();
		void do_div();
};