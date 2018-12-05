#include "huffman_utils.h"

#define EXTENSION ".huff"
#define NUM_OF_BITS 8
#define NUM_OF_BITS_DGT_COUNT 1
#define VALUE_OF_MSB -128


class decoder{

private:

  int extra_bits_count;

  string extension;

  string filename;

  myarrlist <bool> * bits;


  void append_char_to_bits(int );

  string make_file_out_name();


public:

  decoder(string _filename, int capacity);

  ~decoder();

  void load_bits();

  void decode(huffman_tree * tree);

  void read_heading(myarrlist <char_node*> *characters);


};
