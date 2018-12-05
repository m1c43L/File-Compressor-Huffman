#include "decoder.h"

#define EXTENSION ".huff"
#define NUM_OF_BITS 8
#define NUM_OF_BITS_DGT_COUNT 1
#define VALUE_OF_MSB -128

class encoder{

private:

  string original_extension;

  string filename;

  myarrlist <bool> * bits;

  char bits_to_char(int begin_indx, int length);


public:

  encoder(string filename, int capacity);

  ~encoder();

  void load_chars_to(char_map * map);

  void load_bits_from(char_map * map);

  void encode();

  void write_heading(char_map * map);

  string make_file_out_name();

};
