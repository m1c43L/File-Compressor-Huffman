


/*
* Appends bits representation of char to arrlist bits.
*/
void dencoder::append_char_to_bits(char c){

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
