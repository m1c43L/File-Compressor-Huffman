huffman: huffman.cpp
	g++ -I -wall -o huffman huffman.cpp myarrlist.cpp p_queue.cpp huffman_tree.cpp char_map.cpp

clean: huffman
	rm huffman
