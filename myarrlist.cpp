#include "headerfiles/myarrlist.h"



/* types class must be declared here*/
template class myarrlist<char_node>;
template class myarrlist<char_node*>;
template class myarrlist<int>;


template <class type>
  myarrlist<type>::myarrlist(int init_size){
    _size      = 0;
    _capacity  = init_size;
    _list      = new type[_capacity];
  }


/* myarrlist implementation*/
template <class type>
  myarrlist<type>::myarrlist(){
    _size      = 0;
    _capacity  = _INIT_CAP;
    _list      = new type[_capacity];
  }


template <class type>
  myarrlist<type>::~myarrlist(){

      delete [] _list;

    _list     = NULL;
    _size     = 0;
    _capacity = 0;

  }


template <class type>
  void myarrlist<type>::add(type t){

    _size ++;

    if(_size >= _capacity)
      increase_cap();
    // add type t to list
    *(_list + _size - 1) = t;

  }// add


template <class type>
  void myarrlist<type>::remove(int indx){

    if(indx < 0 || indx >= _size) {
      throw "index out of bound";
      return;
    }

    _size --;

    //delete (_list + indx);

    for(int i = indx; i < _size; i++)
      *(_list + indx) = *(_list + indx + 1);

  }// remove


template <class type>
  void  myarrlist<type>::increase_cap(){

    _capacity *= 2;
    type * new_list = new type[_capacity];

    for(int i = 0; i < _size; i++){
      *(new_list + i) = *(_list + i);
    }

    delete [] _list;
    _list = new_list;

  }// increase_cap

template <class type>
  type & myarrlist<type>::operator[](const int indx){

    if(indx  < 0 || indx >= _size)
      throw "out of range";
    else
      return *(_list + indx);

  }// access []


template <class type>
  type myarrlist<type>::at(int indx){

     if(indx  < 0 || indx >= _size)
      throw "out of range";
    else
      return *(_list + indx);

  }//get indx


template <class type>
  void myarrlist<type>::shrink(int new_size){

    if(new_size < 0 || new_size >= _size){
      throw "index out of bound";
      return;
    }

     _size = new_size;

  }// shrink


template <class type>
  int myarrlist<type>::size() {
     return _size;
   }// size

template <class type>
  int myarrlist<type>::capacity(){
     return _capacity;
   }// capacity
