#include "HuffmanTree.h"
#include<iostream>
Node::Node(char _symbol, int _frequency) : symbol(_symbol), frequency(_frequency), left(nullptr), right(nullptr) {}

Node::Node(char _symbol, int _frequency, Node *_left, Node *_right)
    : symbol(_symbol), frequency(_frequency), left(_left), right(_right) {}


bool CompareNodes::operator()(Node *a, Node *b) {
    return a->frequency > b->frequency;
}

Node* buildHuffmanTree(const std::map<char, int> &frequencyMap) {
    std::priority_queue<Node *, std::vector<Node *>, CompareNodes> minHeap;

    // Create nodes for each symbol and its frequency and push them into the min-heap
    for (const auto &entry : frequencyMap) {
        minHeap.push(new Node(entry.first, entry.second));
    }

    // Build the Huffman tree by merging nodes from the min-heap
    while (minHeap.size() > 1) {
        Node *left = minHeap.top(); minHeap.pop();
        Node *right = minHeap.top(); minHeap.pop();

        // Create a parent node with combined frequency
        Node *parent = new Node('\0', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;
        minHeap.push(parent);
    }

    // The root of the Huffman tree is the remaining node in the heap
    return minHeap.top();
}
