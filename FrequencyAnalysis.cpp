#include "FrequencyAnalysis.h"

std::map<char, int> calculateFrequency(const std::string &data) {
    std::map<char, int> frequencyMap;
    
    // Loop through each symbol in the input data
    for (char symbol : data) {
        // Increment the frequency count for the symbol
        frequencyMap[symbol]++;
    }
    
    return frequencyMap;
}
