#include "CLIInterface.h"

char displayMainMenu() {
    char choice;
    std::cout << "Data Compression Tool\n";
    std::cout << "1. Compress File\n";
    std::cout << "2. Decompress File\n";
    std::cout << "3. Exit\n";
    std::cout << "Enter your choice (1/2): ";
    std::cin >> choice;
    return choice;
}

void getFilePaths(std::string &inputPath, std::string &outputPath) {
    std::cout << "Enter input file path: ";
    std::cin >> inputPath;
    std::cout << "Enter output file path: ";
    std::cin >> outputPath;
}
