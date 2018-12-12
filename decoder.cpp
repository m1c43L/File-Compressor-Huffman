#include "headerfiles/decoder.h"


decoder::decoder(string _filename, int capacity){

   filename = _filename;
   bits     = new myarrlist<bool>(capacity);

}

decoder::~decoder(){

  delete bits;

}



/* read the data necessary to build the huhffman tree*/
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

  int char_count = stoi(buffer, NULL);

  // clear buffer
  buffer = "";

  bool is_char = true;

  // get characters with frequency. (MAIN DATA to rebuild huffman_tree)
  while (input.get(c)) {

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

  // get extra_bits_count
  while(input.get(c)){
    if(c == '|') break;
    buffer.push_back(c);
  }

  extra_bits_count = stoi(buffer, NULL);
  buffer = "";

  // get extension
  while(input.get(c)){
    if(c == '|') break;
    buffer.push_back(c);
  }

  extension = buffer;

  // convert each chars back to bits
  while(input.get(c))
    append_char_to_bits(c);


  // remove the the extra bits added to the end to make
  bits->shrink(bits->size() - extra_bits_count);

  input.close();
}


/*
* Appends bits representation of char to arrlist bits.
*/
void decoder::append_char_to_bits(char c){

  char init_value = -128;

  // convert char to bits sequnce
  for(int i = 0; i < NUM_OF_BITS; i++){
    bits->add(c & init_value);
    c = c << 1;
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

  if(extension.compare("") != 0)
    outfile.push_back('.');

  outfile += extension;

  return outfile;
}


/* NOTE : will replace files with the same name (see trunc).
*        rewrites bits back to char and write it to the original file.
*/
void decoder::decode(huffman_tree * tree){

  string original_file_name = make_file_out_name();
  tree->decode_write(bits, original_file_name);

}
