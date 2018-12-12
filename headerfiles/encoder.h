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

  /* Reads each characters of file: filename.
  *  each time it reads a char it increments its frequency in
  *  the char_map. for more information on char_map , refer to the char_map class.
  */
  void load_chars_to(char_map * map);

  void load_bits_from(char_map * map);

  /* repackages bits into sets of 8, converts to char and writes it to compressed file.*/
  void encode();

  /*Prepends important data for decompression*/
  void write_heading(char_map * map);

  /* generate output file of the compressed file, normally ends with .huff*/
  string make_file_out_name();

};
