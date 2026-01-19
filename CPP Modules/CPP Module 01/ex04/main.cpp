#include <iostream>
#include <fstream>
#include <string>
#include "Replacer.hpp"

int main(int argc, char* argv[]) {
	if (argc != 4) {
		std::cerr << "Usage: " << argv[0] << " <filename> <old> <new>" << std::endl;
		return 1;
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	if (s1.empty()) {
		std::cerr << "Error: s1 must not be empty." << std::endl;
		return 1;
	}
	std::ifstream infile(filename.c_str());
	if (!infile) {
		std::cerr << "Error: can't open input file." << std::endl;
		return 1;
	}
	std::string content((std::istreambuf_iterator<char>(infile)), std::istreambuf_iterator<char>());
	infile.close();
	std::string replaced = Replacer::replaceAll(content, s1, s2);
	std::ofstream outfile((filename + ".replace").c_str());
	if (!outfile) {
		std::cerr << "Error: can't open output file." << std::endl;
		return 1;
	}
	outfile << replaced;
	outfile.close();
	return 0;
}
