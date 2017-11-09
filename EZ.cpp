#include "ez.hpp"
int main(int argc, char** argv)
{
	if (argc < 2) {
		std::cout << "Usage: " << argv[0] << " <full_path_to_file>" << std::endl;
		endp(1);
	} else {
		translate(argv[1]);
		end_n_del(funcs);
		endp(0);
	}
}