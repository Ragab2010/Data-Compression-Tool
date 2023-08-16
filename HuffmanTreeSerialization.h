// #pragma once

// #include <iostream>
// #include <sstream>
// #include "HuffmanTree.h"

// // Function to serialize the Huffman tree and add its structure to the header
// std::string serializeHuffmanTreeHelper(const Node *node);

// // Function to serialize the Huffman tree and add its structure to the header
// std::string serializeHuffmanTree(const Node *node);

// // Function to deserialize the Huffman tree structure from the header
// Node* deserializeHuffmanTreeHelper(std::istringstream &headerStream);

// // Function to deserialize the Huffman tree structure from the header
// Node* deserializeHuffmanTree(const std::string &header);
#pragma once

#include <iostream>
#include <sstream>
#include "HuffmanTree.h"

// Function to serialize the Huffman tree and add its structure to the header
std::string serializeHuffmanTree(const Node *node);

// Function to deserialize the Huffman tree structure from the header
Node* deserializeHuffmanTree(const std::string &header);
