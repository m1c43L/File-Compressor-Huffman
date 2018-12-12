compressor: compressor.cpp
	g++ -I -wall -o compressor compressor.cpp myarrlist.cpp p_queue.cpp huffman_tree.cpp char_map.cpp encoder.cpp decoder.cpp

clean: compressor
	rm compressor
