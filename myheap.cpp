#include <iostream>
#include <cstdlib>


#define INIT_CAP 256

using namespace std;
template <typename T>

class myheap{

private:

  T * data;
  unsigned int size;

public:
/*
  myheap(unsigned int _size) : size(_size) {
    data = new T[size];
    for(int i = 0; i < size; i++){
      *(data+i) = 'B';
    }
  }
*/
  myheap(){
   data = new T[INIT_CAP];
    for(int i = 0; i < size; i++){
      *(data+i) = 'B' ;
    }
  }

  ~myheap(){
    for(int i = 0; i < size; i++){
      delete data;
    }
  }

  void print_content(){
    char t = (char)(*(data+1));
    cout << () << "Value" << size << endl;
  }






};


int main(){

  myheap <char> * t = new myheap<char>();

  t->print_content();


  return 0;
}
