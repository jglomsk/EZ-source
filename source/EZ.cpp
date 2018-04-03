#include "EZ.hpp"
int main(int argc, char** argv)
{
	if (argc < 2) {
		std::cout << "Usage: " << argv[0] << " <full_path_to_file>" << std::endl;
		endp(1);
	}
	else {
		for (int i = 1; argv[i] != 0; i++) {
			Main x;
			std::vector<std::string> varis;
			std::vector<std::string> valis;
			std::vector<std::vector<var> > baskets;
			int count = 0;
			std::ifstream fp(argv[i]);
			if (fp.good()) {
				if (argv[2] != 0) {
					std::cout << ":::File " << i << ":::\n";
				}
				x.translate(argv[i], varis, valis, baskets, count);
				x.end_n_del(x.funcs, x.line_count);
				std::cout << "Press enter to continue...";
				if (x.flush > 0) {
					std::cin.clear();
					std::cin.get();
				}
				std::cin.ignore();
			}
			else {
				std::cout << "Use an ez file that exists.\n";
				endp(2);
			}
		}
	}
}
