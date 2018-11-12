#include "myarrlist.h"

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

};



/*
*
*/

class huffman_tree{

private:

  char_node * root;

  void tree_print_traverse(char_node *);

public:

  huffman_tree(p_queue * queue);

  ~huffman_tree();

  void print_huffman_tree();

};
