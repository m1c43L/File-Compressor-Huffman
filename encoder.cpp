#include "headerfiles/encoder.h"




encoder::encoder(string filename, int capacity){

  file.open(filename);
  bits = new myarrlist<bool>();

}



encoder::~encoder(){

  delete bits;
  file.close();

}



void encoder::load_bits(char_map & map){

  char c;
  string buffer;

  while(file.get(c)){

    buffer = map.get_code(c);
    for(int i = 0; i < buffer.size(); i++){

      bits->add( buffer[i] == '1' );

    }

  }

}

/*
* Appends bits representation of char to arrlist bits.
*/
void encoder::append_char_to_bits(char c){

  char bit_value = (VALUE_OF_MSB * VALUE_OF_MSB) / VALUE_OF_MSB;

  bit->add((c < 0) ? 1 : 0);    // if c is negative then MSB must be 1.
  c += c < 0) ?  bit_value : 0; // subtract MSB if c is negative
  bit_value /= 2;               // set value of bit to next below.

  for(int i = 0; i < NUM_OF_BITS - 1 ;i++){

    if(c >= bit_value){
      bit->add(1);
      c -= bit_value;
    }else{
      bit->add(0);
    }

    bit_value /= 2;

  }

  if(c != 0 ) {
    std::cout << "ERROR: char to bits conversion unsucessful." << std::endl;
    exit(-1);
  }

}// append_char_to_bits

/*
* converts segments of bits back to char
*/
char encoder::bits_to_char(int begin_indx, const int length){

  char c = 0;
  int value = VALUE_OF_MSB;

  if(bits[begin_indx]){
    c += value;
  }// if

  value = (value * value) / value; // remove the sign of msb
  value /= 2;

  for(int i = begin_indx + 1;  i < (begin_indx + length); i++){

    if(bits[i]){
      c += value;
    }// if

    value /= 2;
  }// for

  return c;

}// bits_to_char


string encoder::make_file_out_name(){

  string outfile("");
  for(int i = 0; i < filename.size(); i++){

    if(filename[i] == '.') break;
    outfile += filename[i];

  }

  outfile +=


}


string encoder::encode(){


  ofstream out();


  int last_indx = bits.size() - (bits.size() % NUM_OF_BITS);
  int indx = 0;

  while(indx < last_indx) {

  }

}
