
# Data Compression Tool.
***Description:*** Compress/decompress program for files to reduce their size using the Huffman algorithm. <br>
***Technology:***(C++ lang, VScode,  CLI interface,  Implement compression algorithms ( Huffman), STD Data structures for compression and decompression processes, file systems interface for reading and writing compressed files ).<br>
## steps of compression:
1-get the string from the Txt file.<br>
2-calculate the frequency of every character by using unordered_map 3-build the Huffman Tree.<br>
4-generate the Huffman tree header.<br>
5-generate from the Huffman tree header the string of compressed code.<br>
6-generate the compressed bin file and write on it the Huffman tree header + compressed code.<br>
## steps of decompression:
1-get the string from the bin file and the Huffman tree header.<br>
2-rebuild the Huffman Tree.<br>
4-get the characters from the Huffman Tree, to build the decompressed.<br>
5-write the decompressed file with the original text.<br>
