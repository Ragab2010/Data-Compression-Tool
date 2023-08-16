#pragma once

#include <queue>
#include <vector>
#include <map>

// Node structure for Huffman tree
// Huffman tree node structure
struct Node {
    char symbol;
    int frequency;
    Node *left;
    Node *right;

    // Constructor for leaf nodes
    Node(char _symbol, int _frequency);

    // Constructor for internal nodes
    Node(char _symbol, int _frequency, Node *_left, Node *_right);
};


// Comparison function for the priority queue
struct CompareNodes {
    bool operator()(Node *a, Node *b);
};

// Function to build the Huffman tree
Node* buildHuffmanTree(const std::map<char, int> &frequencyMap);
