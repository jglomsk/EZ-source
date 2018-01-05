#include "ez.hpp"
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
		if (answer != "") {
			std::string fi = to_string(rand());
			std::ofstream fp(fi.c_str());
			fp << answer.c_str();
			fp.close();
			x.translate(fi.c_str(), variables, values, baskets, count);
			remove(fi.c_str());
		}
		std::cout << "EZr: ";
		std::getline(std::cin, answer);
	}
	x.end_n_del(x.funcs, x.line_count);
	endp(0, x.flush);
}
