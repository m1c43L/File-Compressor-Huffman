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

  /* Appends bits representation of char to arrlist bits.*/
  void append_char_to_bits(char );


public:

  decoder(string _filename, int capacity);

  ~decoder();

  /* generate the original file name*/
  string make_file_out_name();

  /* rewrites bits back to char and write it to the original file. */
  void decode(huffman_tree * tree);

  /* read the data necessary to build the huhffman tree*/
  void read_heading(myarrlist <char_node*> *characters);


};
