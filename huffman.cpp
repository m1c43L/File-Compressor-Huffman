#include "headerfiles/huffman_utils.h"
#include <fstream>

/*TODO
* create a heap to be used for huffman algorithm.
* create vector for repackaging of bits.
* simple hashmap for tracking unique chars count.
* create file io handler.
*/

/* properties************************************
*  generate .huff as the compressed file output.
*  each outputfile will contain a code table for reading and decompression.
*  each output file (.huff) will contain a special hash to indicate its a valid huffman compressed file.
*  reads file composed only of ascii.
*  be able to decompress file to original forms.
*/

/*store unique char with detatils*/



/*
 TODO :
*/

using namespace std;

int main(){

 ofstream s;
 s.open("test.txt", ofstream::out | ofstream::trunc);
 int count = 97;
 char xa = 97;
 s<< count;
 s<< 97;
 s << xa;
char_map * map = new char_map(270);



for(int i = 0; i < 200; i++){
  map->increment_char( 97 + (i%5) );

}

map->increment_char( 97 + (1) );
map->increment_char( 97 + (1) );
map->increment_char( 97 + (0) );
map->increment_char( 97 + (5) );
map->increment_char( 97 + (8) );
map->increment_char( 97 + (8) );
map->increment_char( 97 + (8) );
map->increment_char( 97 + (11) );
map->increment_char( 97 + (11) );
map->increment_char( 97 + (10) );



myarrlist<char_node*> * arr = map->get_map();



p_queue * q = new p_queue();



for(int i = 0; i < arr->size(); i++){

    q->add((*arr)[i]);

}

q->build_heap();

huffman_tree * t = new huffman_tree(q);


t->print_huffman_tree();




  return 0;

}
