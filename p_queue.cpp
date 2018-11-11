#include "headerfiles/huffman_utils.h"


/* types class declared here*/
template class p_queue<char_node>;
template class p_queue<char_node*>;
template class p_queue<int>;



template <class type>
  int p_queue<type>::left(int indx){

    return 2 * indx;

  }



template <class type>
  int p_queue<type>::right(int indx){

    return 2 * indx + 1;

  }



template <class type>
  void p_queue<type>::swap(int indx1, int indx2){

    type temp = (*queue)[indx1];
    (*queue)[indx1] = (*queue)[indx2];
    (*queue)[indx2] = temp;

  }



template <class type>
  p_queue<type>::p_queue(){

    queue = new myarrlist<type>();

  }



template <class type>
 p_queue<type>::~p_queue(){

   delete queue;

 }



template <class type>
  void p_queue<type>::build_heap(){

    for(int i = (queue->size() / 2); i >= 0; i--)
      heapify(i);

  }



template <class type>
  int p_queue<type>::least(int indx1, int indx2){

    return ((*queue)[indx1] < (*queue)[indx2])? indx1 : indx2;

  }


/*
* NOTE : this heapify follows min heap.
*        recursive call to each subroot when modified.
*/
template <class type>
  void p_queue<type>::heapify(int indx){

    // base case
    if(indx < 0 ||
      indx >= queue->size() ||
       (left(indx) >= queue->size() &&
       right(indx) >= queue->size() ))
      return;

    if(left(indx) >= queue->size()){ // left child is null

      if((*queue)[indx] > (*queue)[right(indx)]){
        swap(indx, right(indx));
        heapify(right(indx));
      }

    }else if(right(indx) >= queue->size()){ // right child is null

      if((*queue)[indx] > (*queue)[left(indx)]){
        swap(indx, left(indx));
        heapify(left(indx));
      }

    }else{ // full subtree

      int indx_of_child = least(left(indx), right(indx));
      if( (*queue)[indx] < (*queue)[indx_of_child] )
        return;
      swap(indx_of_child, indx);
      heapify(indx_of_child);

    }

  }// end of heapify



/*NOTE : may throw exception when queue size < 1*/
template <class type>
  type p_queue<type>::get_top(){

    if(!queue->size()) throw "Empty queue";

      type temp = (*queue)[0];
      (*queue)[0] =(*queue)[queue->size() - 1];
      queue->remove(queue->size() - 1);
      heapify(0);

      return temp;

  }// end of get_top



template <class type>
  void p_queue<type>::add(type t){

    queue->add(t);

  }// add



template <class type>
  bool p_queue<type>::is_empty(){

    return queue->size() == 0;

  }// is_empty
