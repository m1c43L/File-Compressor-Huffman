#include "myarrlist.h"
#include <fstream>
/*
*  huffman auxiliary module
*  simple priority queue implementation
*  see implementation on "p_queue.cpp"
*  NOTE : this p_queue is specialized for char_node* type only
*/
class p_queue{

private:

  /* fields */
  /* simple arraylist, item holder */
  myarrlist <char_node*> * queue;

  /* perform heap operation */
  void heapify(int indx);

  /* return left child index */
  int left(int indx);

  /* return right child index */
  int right(int indx);

  /* swap value between indx1 and indx2 */
  void swap(int indx1, int indx2);

  /* returns indx of lesser value from queue */
  int least(int indx1, int indx2);


public:

  p_queue();

  ~p_queue();

  /* builds heap, iteratively calls heapify */
  void build_heap();

  /* remove and return the top of the heap */
  char_node* get_top();

  /* add type t into the queue */
  void add(char_node* t);

  /* return true if arrlist is empty */
  bool is_empty();

  /* return the size of the current queue */
  int size();

};



/*
*   builds huffman and store huffman tree.
*/
class huffman_tree{

private:

  /* root of the huffman tree */
  char_node * root;

  /* helper func for print_huffman_tree, traverse tree and prints each leaf nodes */
  void tree_print_traverse(char_node *);

  /* recursively assign code to each char_node */
  void encode(char_node*, string);

public:

  /* builds tree from queue upon contuction */
  huffman_tree(p_queue * queue);

  /* free root */
  ~huffman_tree();

  /* prints tree, calls tree_print_traverse */
  void print_huffman_tree();

  /* iterate bits to generate chars that are printed on file original_file_name*/
  void decode_write(myarrlist <bool> *bits, string original_file_name);

};



/*
* simulation hashmap specialized for char map.
* NOTE : upon construction, limit the map cap to max value of unsigned char
*/

class char_map{

private:

  /*number of char stored*/
  int char_node_count;

  myarrlist <char_node*> * map;

public:

  char_map(int );

  ~char_map();

  /* return an arraylist of the map.
  *  NOTE : arraylist will only contain char_node with frequency > 0
  */
  myarrlist<char_node*> * get_map();

  /* increment (char) int*/
  void increment_char(int );

  /* get the huffman code of char int*/
  string get_code(int );

  /* get the frequency of char*/
  int get_frequency(char );

  /* get string value of map*/
  string to_string();

  /* return the count of items ini map */
  int get_char_node_count();

};
