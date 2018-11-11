/* @author:  Michael Gilbert
*  Simple implementation of arraylist
*  NOTE : <class> type must be specified in the
*/

#include <cstdlib>
#include <iostream>
#include "characters.h"

template <class type>

class myarrlist {


private:

  const int _INIT_CAP = 256;

  int _capacity;
  int _size;
  type * _list;


public:

  myarrlist();

  ~myarrlist();

  void add(type t);

  //void add(type * t);

  void remove(int indx);

  void increase_cap();

  type & operator[](const int indx);

  type at(int indx);

  void shrink(int new_size);

  int size();

  int capacity();



};
