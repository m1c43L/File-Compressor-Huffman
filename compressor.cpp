#include "headerfiles/encoder.h"

using namespace std;


int main(){

encoder * compress = new encoder("test.txt", 10000);

char_map * map = new char_map(270);


compress->load_chars_to(map);
myarrlist<char_node*> * arr = map->get_map();
p_queue * q = new p_queue();
for(int i = 0; i < arr->size(); i++){
    q->add((*arr)[i]);
}

//
q->build_heap();
huffman_tree * t = new huffman_tree(q) ;
t->print_huffman_tree();
compress->load_bits_from(map);

 //cout << "complete!!" << endl;
compress->encode();
/*
delete compress;
delete map;
delete arr;
delete q;
delete t;
*/
  return 0;
}
