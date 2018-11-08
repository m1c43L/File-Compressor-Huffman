#include "headerfiles/huffman_utils.h"
#include <iostream>

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





using namespace std;

int main(){

p_queue <int> * t = new p_queue<int>();


t->add(10);
t->add(3);
t->add(5);
t->add(8);
t->add(2);
t->add(7);
t->add(8);


t->build_heap();

while(!(t->is_empty()) ){
  cout << t->get_top() << endl;
}

delete t;
  return 0;

}
