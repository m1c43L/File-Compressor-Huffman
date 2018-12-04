compressor: compressor.cpp
	g++ -I -wall -o compressor compressor.cpp myarrlist.cpp p_queue.cpp huffman_tree.cpp char_map.cpp encoder.cpp

clean: compressor
	rm compressor


#compressor: compressor.cpp
#  g++ -I -wall -o compressor compressor.cpp myarrlist.cpp p_queue.cpp huffman_tree.cpp char_map.cpp encoder.cpp

#clean: huffman
#	rm huffman





#huffman: huffman.cpp
#	g++ -I -wall -o huffman huffman.cpp myarrlist.cpp p_queue.cpp huffman_tree.cpp char_map.cpp

#clean: huffman
#	rm huffman
