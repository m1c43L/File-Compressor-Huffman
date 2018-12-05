#include "headerfiles/decoder.h"


decoder::decoder(string _filename, int capacity){

   filename = _filename;
   bits     = new myarrlist<bool>(capacity);

}

decoder::~decoder(){

  delete bits;

}


void decoder::load_bits(){

  std::ifstream inputfile(filename, std::ifstream::in);

  if(!inputfile.is_open()) {
    std::cout << "ERROR OPENING file : " << filename << " !" << std::endl;
  }

  char c;

  // read through the file.
  while(inputfile.get(c)){

    append_char_to_bits(c);

  }

  inputfile.close();

}



void decoder::read_heading(myarrlist <char_node*> * characters){

  ifstream input(filename, std::ifstream::in);
  string buffer("");
  char c;
  while (input.get(c)) { // get char_count
    if(c != '|')
      buffer.push_back(c);
    else
      break;
  }

  int char_count = stoi(buffer,NULL);
  buffer = "";
  bool is_char = true;
  while (input.get(c)) { // get characters with frequency. (MAIN DATA)
     if(is_char){
       characters->add(new char_node(c));
       char_count --;
       is_char = false;
     }else{
       if(c ==  ';'){
         (*characters)[characters->size() - 1]->frequency = stoi(buffer, NULL);
         buffer  = "";
         is_char = true;
         if(char_count <= 0) break;
       }else{
         buffer.push_back(c);
       }
     }
  }

  while(input.get(c)){ // get extra_bits_count
    if(c == '|') break;
    buffer.push_back(c);
  }

  extra_bits_count = stoi(buffer, NULL);
  buffer = "";

  while(input.get(c)){ // get extension
    if(c == '|') break;
    buffer.push_back(c);
  }

  extension = buffer;

  while(input.get(c)){

    append_char_to_bits(c);

  }

  bits->shrink(bits->size() - extra_bits_count);

  input.close();
}


/*
* Appends bits representation of char to arrlist bits.
*/
void decoder::append_char_to_bits(int c){

  int bit_value =  VALUE_OF_MSB * -1;

  bits->add((c < 0) ? 1 : 0);    // if c is negative then MSB must be 1.
  c += (c < 0) ?  bit_value : 0; // subtract MSB if c is negatives
  bit_value /= 2;               // set value of bit to next below.

  for(int i = 0; i < NUM_OF_BITS - 1 ;i++){

    if(c >= bit_value){
      bits->add(1);
      c -= bit_value;
    }else{
      bits->add(0);
    }

    bit_value /= 2;

  }

  if(c != 0 ) {
    std::cout << "ERROR: char to bits conversion unsucessful. " << c << std::endl;
    exit(-1);
  }

}// append_char_to_bits



/* generate the original file name*/
string decoder::make_file_out_name(){

  string outfile("");
  for(int i = 0; i < filename.size(); i++){

    if(filename[i] == '.') break; // remove .
      outfile += filename[i];

  }

  outfile.push_back('.');
  outfile += extension;

  return outfile;
}


/* NOTE : will replace files with the same name (see trunc).
*
*/
void decoder::decode(huffman_tree * tree){

  string original_file_name = make_file_out_name();
  tree->decode_write(bits, original_file_name);

}
