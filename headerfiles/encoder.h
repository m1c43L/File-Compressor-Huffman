#include "huffman_utils.h"
#include <fstream>

#define EXTENSION ".huff"
#define NUM_OF_BITS 8
#define VALUE_OF_MSB -256

class encoder{

private:

  ifstream inputfile;

  ofstream outputfile;

  string filename;

  myarrlist <bool> * bits;



  char bits_to_char(int begin_indx, int length);

  void append_char_to_bits(char );

  string make_file_out_name();


public:

  encoder(string filename, int capacity);

  ~encoder();

  void load_bits();

  string encode();

  bool is_open(string filename);


};
