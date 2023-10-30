#pragma once

#include <map>
#include <string>
#include "HuffmanTree.h"

// Function to generate Huffman codes for each symbol in the tree
std::map<char, std::string> generateHuffmanCodes(Node *root);
