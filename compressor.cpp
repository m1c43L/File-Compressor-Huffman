#include <iostream>
#include <fstream>

#define output_file_extention ".huff"

 using namespace std;

class compressor{

private:

  ifstream inputfile;
  ofstream outputfile;



public:

    compressor(const string filename, const string mode){
           inputfile.open(filename, ios::in);
   }


   ~compressor(){
     inputfile.close();
     cout << "file closed." << endl;
   }

    void print_input_file_content(){
      char c;
      while((c = inputfile.get()) != EOF){
        cout << c ;
      }
      test();
   }

private:


  void test(){
     cout << "private test" << endl;
  }



};









int main(int argc, const char **  argv){

  string s("D");

  compressor * c = new compressor(argv[1], s);
  c->print_input_file_content();
  delete c;


  return 0;
}
