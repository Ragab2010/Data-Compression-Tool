#pragma once

#include "HuffmanTree.h"
#include <string>
#include <map>

// Function to compress the input data using Huffman codes
std::string compressData(const std::string &data, const std::map<char, std::string> &huffmanCodes);
std::string addHuffmanTreeHeader(const Node *root) ;