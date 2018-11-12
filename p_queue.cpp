#include "headerfiles/huffman_utils.h"


int p_queue::left(int indx){

    if(indx) return 2 * indx;
    return 1;

}



int p_queue::right(int indx){

    if(indx) return 2 * indx + 1;
    return 2;

}



void p_queue::swap(int indx1, int indx2){

    char_node * temp = (*queue)[indx1];
    (*queue)[indx1]  = (*queue)[indx2];
    (*queue)[indx2]  = temp;

}



p_queue::p_queue(){

    queue = new myarrlist<char_node*>();

}



p_queue::~p_queue(){

   delete queue;

}



void p_queue::build_heap(){

  for(int i = (queue->size() / 2); i >= 0; i--)
    heapify(i);

}



int p_queue::least(int indx1, int indx2){

  return ( *((*queue)[indx1]) < *((*queue)[indx2]) )? indx1 : indx2;

}


/*
* NOTE : this heapify follows min heap.
*        recursive call to each subroot when modified.
*/
void p_queue::heapify(int indx){

    // base case
    if(indx < 0 ||
      indx >= queue->size() ||
       (left(indx) >= queue->size() &&
       right(indx) >= queue->size() ))
      return;

    if(left(indx) >= queue->size()){ // left child is null

      if( *((*queue)[indx]) > *((*queue)[right(indx)]) ){
        swap(indx, right(indx));
        heapify(right(indx));
      }

    }else if(right(indx) >= queue->size()){ // right child is null

      if( *((*queue)[indx]) > *((*queue)[left(indx)]) ){
        swap(indx, left(indx));
        heapify(left(indx));
      }

    }else{ // full subtree

      int indx_of_child = least(left(indx), right(indx));
      if( *((*queue)[indx]) < *((*queue)[indx_of_child]) )
        return;
      swap(indx_of_child, indx);
      heapify(indx_of_child);

    }

}// end of heapify



/*NOTE : may throw exception when queue size < 1*/
char_node* p_queue::get_top(){

    if(!queue->size()) throw "Empty queue";

      char_node* temp = (*queue)[0];
      (*queue)[0] =(*queue)[queue->size() - 1];
      queue->remove(queue->size() - 1);
      heapify(0);

      return temp;

}// end of get_top



void p_queue::add(char_node* t){

    queue->add(t);

}// add



bool p_queue::is_empty(){

    return queue->size() == 0;

}// is_empty
