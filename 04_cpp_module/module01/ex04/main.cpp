#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) {
	if (argc != 4) {
		std::cout << "Enter three values" << std::endl;
		return 1;
	}

	std::string s1 = argv[2];
	std::string s2 = argv[3];
	int len_s1 = s1.length();
	int len_s2 = s2.length();

	std::ifstream ifs(argv[1]);
	if (!ifs.is_open()) {
		std::cout << "Failed to open the input file." << std::endl;
		return 1;
	}
	std::ofstream ofs(std::string(argv[1]) + ".replace");
	if (ofs.fail()) {
		std::cout << "Failed to open the output file." << std::endl;
		ifs.close();
		return 1;
	}
	std::string buffer = "";
	int c;
    while ((c = ifs.get()) != EOF) {
        buffer += static_cast<unsigned char>(c);
    }
	size_t pos1 = 0;
	size_t pos2 = 0;
	while (true) {
		pos1 = buffer.find(s1, pos2);
		if (pos1 == std::string::npos)
			break;
		buffer.erase(pos1, len_s1);
		buffer.insert(pos1, s2);
		pos2 = pos1 + len_s2;
	}
	ofs << buffer;

	ifs.close();
	ofs.close();
	return 0;
}
