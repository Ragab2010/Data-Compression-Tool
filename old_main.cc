#include <iostream>
#include "FrequencyAnalysis.h"
#include "HuffmanTree.h"
#include "CodeGeneration.h"
#include "Compression.h"
#include "Decompression.h"

int main() {
    std::string input = "hello world"; // Replace with your input data
    
    // Frequency analysis
    std::map<char, int> frequencyMap = calculateFrequency(input);
    
    // Huffman tree construction
    Node *huffmanTree = buildHuffmanTree(frequencyMap);
    
    // Code generation
    std::map<char, std::string> huffmanCodes = generateHuffmanCodes(huffmanTree);
    
    // Data compression
    std::string compressedData = compressData(input, huffmanCodes);
    
    // Output results
    std::cout << "Original Data: " << input << std::endl;
    std::cout << "Compressed Data: " << compressedData << std::endl;

    // Data decompression
    std::string decompressedData = decompressData(compressedData, huffmanTree);

    std::cout << "Decompressed Data: " << decompressedData << std::endl;

    // Clean up memory for the Huffman tree nodes
    // Implement necessary cleanup here
    delete huffmanTree; // Clean up the root of the Huffman tree

    return 0;
}
