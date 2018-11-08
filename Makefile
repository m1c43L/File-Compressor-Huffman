huffman: huffman.cpp
	g++ -I -wall -o huffman huffman.cpp myarrlist.cpp p_queue.cpp

clean: huffman
	rm huffman
