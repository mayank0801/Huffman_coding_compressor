# Huffman_coding_compressor

# Introduction
This project is to design compression and decompression programs based on Huffman Coding. The idea of Huffman Coding is to minimize the weighted expected length of the code by means of assigning shorter codes to frequently-used characters code.

# Implementation Details
The programs can compress and decompress file consisting of 128 ASCII characters.

# Compression
Count and store the frequencies of different characters;
Construct Priority Queue and then Huffman Tree;
Calculate Huffman Encode Table;
Encode the file, store Huffman Encode Table and encoded to the desired file.

# Decompression
Open file, recreate Huffman Tree based on Huffman Encode Table;
Decode the file based on the tree and store it to the desired file.
