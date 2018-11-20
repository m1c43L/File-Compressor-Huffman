#include "headerfiles/huffman_utils.h"


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




char_map * map = new char_map(270);



for(int i = 0; i < 100; i++){
  map->increment_char( 97 + (i%10) );

}





myarrlist<char_node*> * arr = map->get_map();



p_queue * q = new p_queue();



for(int i = 0; i < arr->size(); i++){

    q->add((*arr)[i]);

}

q->build_heap();
/*
while(!q->is_empty()){
//  q->get_top();
char_node * t =q->get_top();
  cout << t->unique_char << " - " << t->frequency << endl ;
  cout << "Reached here***************" << endl;
}





*/

huffman_tree * t = new huffman_tree(q);




t->print_huffman_tree();














/*
p_queue  * t = new p_queue();



for(int i = 0; i < 10; i++){
  t->add( new char_node (97 + i, 100 - i, false));
}

t->add(new char_node (97, 0, false));
t->add(new char_node (97 + 1, 10, false));
t->add(new char_node (97 + 2, 15, false));
t->add(new  char_node (97 + 3, 20, false));
t->add(new char_node (97 + 4, 9, false));

  t->build_heap();
//t->heapify(0);

/*
while(!t->is_empty()){
  cout << " " << t->get_top()->unique_char << endl;
}

huffman_tree tree(t);

tree.print_huffman_tree();
*/


  return 0;

}
