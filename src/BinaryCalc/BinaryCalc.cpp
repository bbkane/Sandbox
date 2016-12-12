#include <iostream>
#include <vector>
#include <string>

#include "StringFunctions.h"

class Var;
class Parser;

//class Var
//{
//public:
//	Var(std::string name, int value)
//		: value(static_cast<bool>(value)), name(name)
//	{ }
//	Var(std::string name, bool value)
//		: value(value), name(name)
//	{ }
//
//	Var(std::string name, std::string value)
//		: name(name)
//	{
//		if (value == "0" || value == "false") {this->value = false;}
//		else if (value == "1" || value == "true") {this->value = true;}
//		else { std::cerr << "Error: value cannot be initialized" << std::endl;}
//	}
//
//	bool value{ false };
//	std::string name{ "uninitialized" };
//
//	friend std::ostream& operator<<(std::ostream& out, const Var &var)
//	{
//		out << "name: " << var.name << " value: " << std::boolalpha << var.value << std::endl;
//		return out;
//	}
//};
//
//class Parser
//{
//public:
//	void parse_assignment(std::string expr)
//	{
//		expr = trim_left(expr);
//		
//		std::size_t equals_pos = expr.find('=');
//		if (equals_pos == std::string::npos)
//		{
//			std::cerr << "Error: aborting" << std::endl;
//			std::terminate();
//		}
//
//		std::string name = trim_left(expr.substr(0, equals_pos - 1));
//		std::string value = trim_left(expr.substr(equals_pos));
//
//		values.push_back(Var(name, value));
//	}
//
//	std::vector<Var> values;
//	friend std::ostream &operator<<(std::ostream &out, const Parser &parser)
//	{
//		for (auto i : parser.values)
//		{
//			out << i;
//		}
//		return out;
//	}
//};



int main()
{
	{
		std::string expr = "a = 1";
		expr = trim_left(expr);
		std::cout << expr << std::endl;
	}
	return 0;
	//Parser parser;
	//while (true)
	//{
	//	std::string expr;

	//	std::getline(std::cin, expr);
	//	parser.parse_assignment(expr);
	//	std::cout << parser;
	//}
}