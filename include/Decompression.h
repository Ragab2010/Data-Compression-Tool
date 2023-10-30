#pragma once

#include <string>
#include "HuffmanTree.h"
#include <sstream>

// Function to decompress the compressed data using the Huffman tree
std::string decompressData(const std::string &compressedData, Node *root);
Node* buildHuffmanTreeFromHeader(const std::string &header) ;