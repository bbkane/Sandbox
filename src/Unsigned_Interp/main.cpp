//#include <boost/iostreams/stream.hpp>
//#include <boost/iostreams/tee.hpp>

#include <iostream>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <string>
#include <fstream>
#include <stdexcept>

using unsigned_type = unsigned int;

static_assert(sizeof(unsigned_type) > 1, "If type not greater than one byte, Carry out won't work");

std::string get_hex(unsigned_type in)
{
	std::stringstream buffer;
	buffer << std::hex << unsigned(in & 0xff);
	return buffer.str();
}

std::string get_bin(unsigned_type in)
{
	return std::bitset<8>(in).to_string();
}

#define DO_OP(op_sign) if (op == #op_sign) { return arg1 op_sign arg2; }
unsigned_type do_op(unsigned_type arg1, std::string op, unsigned_type arg2)
{
	DO_OP(+)
	DO_OP(-)
	DO_OP(|)
	DO_OP(^)
	DO_OP(&)
	throw std::invalid_argument("invalid operand: " + op);
}
#undef DO_OP

std::string intro_message =
R"(Enter: <Uint8> <whitespace> <op> <whitespace> <Uint8>
Enter: 'bin' to switch to binary entry mode
Enter: 'hex' to switch to hexadecimal mode (default)
Enter: 'clear' to clear the screen
Enter: 'help' to display this help message
Enter: 'q' or press Ctrl-C to quit)";

int main()
{
	//using Tee = boost::iostreams::tee_device<std::ostream, std::ofstream>;
	//using TeeStream = boost::iostreams::stream<Tee>;

	//std::ofstream file("log.txt");
	//Tee tee(std::cout, file);
	//TeeStream both(tee);

	std::cout << intro_message << std::endl;

	std::string mode = "hex";
	int base = 16;
	unsigned_type arg1, arg2, ans;
	for (;;)
	{
		std::string first, op, second;

		std::cout << mode << " >>> ";
		std::cin >> first;
		if (first == "quit" || first == "exit" || first == "q") { break; }
		if (first == "clear" || first == "clr")
		{
			system("clear");
			continue;
		}
		if (first == "help")
		{
			std::cout << intro_message << std::endl;
			continue;
		}
		if (first == "bin")
		{
			base = 2;
			std::cout << "Switched to binary mode" << std::endl;
			mode = "bin";
			continue;
		}
		if (first == "hex")
		{
			base = 16;
			std::cout << "Switched to hexadecimal mode" << std::endl;
			mode = "hex";
			continue;
		}
		try
		{
			arg1 = static_cast<unsigned_type>(std::stoul(first, 0, base));
		}
		catch (std::invalid_argument & invalid)
		{
			std::cout << invalid.what() << std::endl;
			continue;
		}
		std::cin >> op >> second;
		try
		{
			arg2 = static_cast<unsigned_type>(std::stoul(second, 0, base));
			ans = do_op(arg1, op, arg2);
		}
		catch (std::invalid_argument & invalid)
		{
			std::cout << invalid.what() << std::endl;;
			continue;
		}

		if (ans > 0xff) { std::cout << "Carry-out: 1" << std::endl; }
		std::cout << get_hex(arg1) << " " << op << " " << get_hex(arg2) << " = " << get_hex(ans) << std::endl;
		std::cout << get_bin(arg1) << " " << op << "\n" << get_bin(arg2) << " =\n" << get_bin(ans) << std::endl;
	}
}
