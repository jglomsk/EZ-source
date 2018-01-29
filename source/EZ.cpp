#include "EZ.hpp"
int main(int argc, char** argv)
{
	if (argc < 2) {
		std::cout << "Usage: " << argv[0] << " <full_path_to_file>" << std::endl;
		endp(1);
	} else {
		Main x;
		std::vector<std::string> varis(20);
		std::vector<std::string> valis(20);
		std::vector<std::vector<var> > baskets;
		int count = 0;
		std::ifstream fp(argv[1]);
		if (fp.good()) {
			x.translate(argv[1], varis, valis, baskets, count);
			x.end_n_del(x.funcs, x.line_count);
			endp(0, x.flush);
		}
		else {
			std::cout << "Use an ez file that exists.\n";
			endp(2);
		}
	}
}
