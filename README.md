# Simple file compressor that uses huffman coding to compress.

## Instructions on how to use :

### To compile:
####        Using g++ : 	g++ -I -wall -o compressor compressor.cpp myarrlist.cpp p_queue.cpp huffman_tree.cpp char_map.cpp encoder.cpp decoder.cpp


### To run:
####    ./compressor "mode" "filename"
####    modes are "-c" to compress a file, and "-d" to decompress a file. NOTE -d only works for files compressed by this compressor.
