#include "huffman_utils.h"
#include <fstream>

#define EXTENSION ".huff"
#define NUM_OF_BITS 8
#define NUM_OF_BITS_DGT_COUNT 1
#define VALUE_OF_MSB -256

class encoder{

private:

  string filename;

  myarrlist <bool> * bits;

  char bits_to_char(int begin_indx, int length);

  string make_file_out_name();


public:

  encoder(string filename, int capacity);

  ~encoder();

  void load_chars_to(char_map * map);

  void load_bits_from(char_map * map);

  void encode();

  void write_heading(string orig_extension, string header, int extra_bits_count);


};
