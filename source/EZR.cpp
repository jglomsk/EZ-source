#include "EZ.hpp"
int main()
{
	std::string answer = "";
	std::vector<std::string> values(20);
	std::vector<std::string> variables(20);
	std::vector<std::vector<var> > baskets;
	int count = 0;
	Main x;
	srand(0);
	while (answer != "exit") {
		if (answer.find("while") != std::string::npos ||
				answer.find("push") != std::string::npos ||
				answer.find("if") != std::string::npos ||
				answer.find("else") != std::string::npos ||
				answer.find("basket") != std::string::npos || // this one you just can't use cuz you can't push into it
				answer.find("make") != std::string::npos) { // ALL OF THESE CAUSE SEG FAULT
			std::cout << "Make an ez file and use the interpreter on it for all the features of EZ.\n";
			std::cout << "Keywords included in this interactive shell are: set (w/o basket), show, with, call\n";
		}
		else if (answer != "") {
			std::string fi = to_string(rand());
			std::ofstream fp(fi.c_str());
			fp << answer.c_str();
			fp.close();
			x.translate(fi.c_str(), variables, values, baskets, count);
			remove(fi.c_str());
		}
		if (answer.find("input") == std::string::npos) std::cout << "EZr: ";
		std::getline(std::cin, answer);
	}
	x.end_n_del(x.funcs, x.line_count);
	return 0;
}