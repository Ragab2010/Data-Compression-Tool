#include "HuffmanTreeSerialization.h"

std::string serializeHuffmanTreeHelper(const Node *node) {
    if (node == nullptr) {
        return "N"; // Null node
    }

    if (node->left == nullptr && node->right == nullptr) {
        return "L" + std::string(1, node->symbol); // Leaf node
    }

    return "I" + serializeHuffmanTreeHelper(node->left) + serializeHuffmanTreeHelper(node->right); // Internal node
}

std::string serializeHuffmanTree(const Node *node) {
    return serializeHuffmanTreeHelper(node);
}
Node* deserializeHuffmanTreeHelper(std::istringstream &headerStream) {
    char nodeType;
    headerStream >> nodeType;

    if (nodeType == 'N') {
        return nullptr; // Null node
    } else if (nodeType == 'L') {
        char symbol;
        headerStream >> symbol;
        return new Node(symbol, 0); // Leaf node
    } else if (nodeType == 'I') {
        Node *leftNode = deserializeHuffmanTreeHelper(headerStream);
        Node *rightNode = deserializeHuffmanTreeHelper(headerStream);
        return new Node('\0', leftNode->frequency + rightNode->frequency, leftNode, rightNode); // Internal node
    }

    return nullptr; // Invalid node type
}

Node* deserializeHuffmanTree(const std::string &header) {
    std::istringstream headerStream(header);
    return deserializeHuffmanTreeHelper(headerStream);
}
