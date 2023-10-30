#include "Compression.h"
#include "HuffmanTreeSerialization.h"
#include <sstream>

std::string compressData(const std::string &data, const std::map<char, std::string> &huffmanCodes) {
    std::string compressedData;
    
    // Loop through each symbol in the input data and append its Huffman code
    for (char symbol : data) {
        compressedData += huffmanCodes.at(symbol);
    }
    
    return compressedData;
}


std::string addHuffmanTreeHeader(const Node *root) {
    return serializeHuffmanTree(root);
}
