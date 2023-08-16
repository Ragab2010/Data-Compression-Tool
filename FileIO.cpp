#include "FileIO.h"
#include <fstream>

std::string readFile(const std::string &filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        return "";
    }

    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    return content;
}

void writeFile(const std::string &filePath, const std::string &content) {
    std::ofstream file(filePath);
    if (file.is_open()) {
        file << content;
        file.close();
    }
}
