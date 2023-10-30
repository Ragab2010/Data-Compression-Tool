#pragma once

#include <string>

// Function to read the content of a file
std::string readFile(const std::string &filePath);

// Function to write content to a file
void writeFile(const std::string &filePath, const std::string &content);
