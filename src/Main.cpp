#include <iostream>
#include "FrequencyAnalysis.h"
#include "HuffmanTree.h"
#include "CodeGeneration.h"
#include "Compression.h"
#include "Decompression.h"
#include "CLIInterface.h"
#include "FileIO.h"
#include "HuffmanTreeSerialization.h" // Include the new serialization module
using namespace std;
int main() {
    char choice = displayMainMenu();

    if (choice == '1') {
        std::string inputPath, outputPath;
        getFilePaths(inputPath, outputPath);

        // Read the content of the input file
        std::string input = readFile(inputPath);
        std::cout<<"the string is :"<<input<<std::endl;
        // Frequency analysis
        std::map<char, int> frequencyMap = calculateFrequency(input);
        cout<<"/***the frequencyMap ****/"<<endl;

        // for(auto&[symbol , count]: frequencyMap){
        //     cout<<symbol<<" : "<<count<<endl;
        // }
        // cout<<"/**********************/"<<endl;

        // Huffman tree construction
        Node *huffmanTree = buildHuffmanTree(frequencyMap);

        // Code generation
        std::map<char, std::string> huffmanCodes = generateHuffmanCodes(huffmanTree);

        // Data compression
        std::string compressedData = compressData(input, huffmanCodes);

        // Save Huffman tree header
        std::string huffmanTreeHeader = addHuffmanTreeHeader(huffmanTree);
        std::cout<<"the huffmanTreeHeader:"<<huffmanTreeHeader<<std::endl;
        // Combine Huffman tree header and compressed data
        //std::string compressedWithHeader = huffmanTreeHeader + compressedData;
        // In the compression part
        std::string compressedWithHeader = huffmanTreeHeader + '\n' + compressedData;

        std::cout<<"the compressedWithHeader:"<<compressedWithHeader<<std::endl;
        // Write the compressed data (including the header) to the output file
        writeFile(outputPath, compressedWithHeader);

        std::cout << "File compressed successfully.\n";

        // Clean up memory for the Huffman tree nodes
        // Implement necessary cleanup here
        delete huffmanTree; // Clean up the root of the Huffman tree
    } else if (choice == '2') {
        std::string inputPath, outputPath;
        getFilePaths(inputPath, outputPath);
    
        // Read the content of the input file (including the Huffman tree header and compressed data)
        std::string compressedWithHeader = readFile(inputPath);
        std::cout<<"the compressedWithHeader:"<<compressedWithHeader<<std::endl;

        // Extract Huffman tree header and compressed data
        // In the decompression part
        size_t headerEnd = compressedWithHeader.find('\n');
        std::string huffmanTreeHeader = compressedWithHeader.substr(0, headerEnd);
        std::string compressedData = compressedWithHeader.substr(headerEnd + 1);

        std::cout << "Extracted Huffman Tree Header: " << huffmanTreeHeader << std::endl;


        std::cout<<"before : buildHuffmanTreeFromHeader"<<std::endl;
        // Build Huffman tree from header
        Node *huffmanTree = buildHuffmanTreeFromHeader(huffmanTreeHeader);

        // Decompress the data using the Huffman tree
        std::string decompressedData = decompressData(compressedData, huffmanTree);
        std::cout<<"the decompressedData:"<<decompressedData<<std::endl;
    
        // Write the decompressed data to the output file
        writeFile(outputPath, decompressedData);

        std::cout << "File decompressed successfully.\n";

        // Clean up memory for the Huffman tree nodes
        // Implement necessary cleanup here
        delete huffmanTree; // Clean up the root of the Huffman tree
    } else {
        std::cout << "Invalid choice.\n";
    }

    return 0;
}
