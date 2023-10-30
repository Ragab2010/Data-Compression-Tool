#include "CodeGeneration.h"

// Recursive function to generate Huffman codes by traversing the tree
void generateCodes(Node *node, const std::string &prefix, std::map<char, std::string> &huffmanCodes);

std::map<char, std::string> generateHuffmanCodes(Node *root) {
    std::map<char, std::string> huffmanCodes;
    
    // Start code generation from the root of the Huffman tree
    generateCodes(root, "", huffmanCodes);
    
    return huffmanCodes;
}

void generateCodes(Node *node, const std::string &prefix, std::map<char, std::string> &huffmanCodes) {
    if (node == nullptr) {
        return;
    }
    
    // Leaf node represents a symbol, store its code in the map
    if (node->left == nullptr && node->right == nullptr) {
        huffmanCodes[node->symbol] = prefix;
    }
    
    // Traverse left and right subtrees, appending '0' and '1' respectively to the prefix
    generateCodes(node->left, prefix + '0', huffmanCodes);
    generateCodes(node->right, prefix + '1', huffmanCodes);
}
