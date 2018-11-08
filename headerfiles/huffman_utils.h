#include "myarrlist.h"

/*
*  huffman auxiliary module
*  simple priority queue implementation
*  see implementation on "p_queue.cpp"
*/
template <class type>
class p_queue{

private:

  /* fields */
  /* simple arraylist, item holder */
  myarrlist <type> * queue;


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
  type get_top();

  /* add type t into the queue */
  void add(type t);

  /* return true if arrlist is empty */
  bool is_empty();

};


/*
*
*/

class huffman_compress{

private:




};
