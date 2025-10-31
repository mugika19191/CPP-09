#include "RPN.hpp"

bool its_all_num(std::string vars)
{
	for (unsigned long i = 0; i < vars.size(); i++)
	{
		if (vars[i] < '0' || vars[i] > '9')
			return false;
	}
	return true;
}

RPN::RPN()
{
}

RPN::~RPN()
{
}

void RPN::loop(std::string vars)
{
    size_t last_pos = 0;
    size_t pos = vars.find(' ');

    while (pos != std::string::npos)
    {
        if (pos > last_pos) {
            std::string param = vars.substr(last_pos, pos - last_pos);
            if (its_all_num(param))
            {
                std::cout << "[" << param << "]" << std::endl;
                stack.push(atoi(param.c_str()));
                std::cout << "size: "<< stack.size() << std::endl;
            }
            else if(param.size()==1)
            {
                switch (param[1])
                {
                case '+':
                    /* code */
                    break;
                case '-':
                    /* code */
                    break;
                case '*':
                    /* code */
                    break;
                case '/':
                    /* code */
                    break;
                default:
                    break;
                }
            }
        }
        last_pos = pos + 1;
        pos = vars.find(' ', last_pos);
    }
    if (last_pos < vars.size()) {
        std::string param = vars.substr(last_pos);
        std::cout << "[" << param << "]" << std::endl;
    }
}


void RPN::do_add()
{
}

void RPN::do_sub()
{
}

void RPN::do_mult()
{
}

void RPN::do_div()
{
}
