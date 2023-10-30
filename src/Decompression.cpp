#include "Decompression.h"
#include "HuffmanTreeSerialization.h"

std::string decompressData(const std::string &compressedData, Node *root) {
    std::string decompressedData;
    
    Node *currentNode = root;
    
    // Traverse the Huffman tree using the compressed data to decode symbols
    for (char bit : compressedData) {
        if (bit == '0') {
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }
        
        // Leaf node reached, append the symbol to the decompressed data
        if (currentNode->left == nullptr && currentNode->right == nullptr) {
            decompressedData += currentNode->symbol;
            currentNode = root; // Reset to the root for the next symbol
        }
    }
    
    return decompressedData;
}
Node* buildHuffmanTreeFromHeader(const std::string &header) {
    return deserializeHuffmanTree(header);
}
