#include <fstream>
#include <string>

using namespace std;

int fib(int n){
  if(n <= 1){
    return 1;
  }else{
    return fib(n -1) + fib(n - 2);
  }
}



int main(int argc, char * argv[]){

  string fname(argv[1]);

  ofstream out(fname, ofstream::out | ofstream::trunc);

  int size = stoi(argv[2]);
  char c = '0';
  int value;
  for(int i = 0; i < size; i++){
    value = fib(i);
    while(value > 0){
      out << c;
      value --;
    }
    c ++;
  }

  out.close();

return 0;
}
