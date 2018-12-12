#include "headerfiles/encoder.h"
#define _INIT_CAP 10000
#define MAX_CHAR_MAP_SIZE 256
using namespace std;



void compress(string filename){

  char_map * map     = new char_map(MAX_CHAR_MAP_SIZE);
  encoder  *_encoder = new encoder(filename, _INIT_CAP);

  _encoder->load_chars_to(map);

  myarrlist<char_node*> * arr = map->get_map();

  p_queue * char_queue = new p_queue();

  // add to queue
  for(int i = 0; i < arr->size(); i++)
      char_queue ->add((*arr)[i]);

  char_queue->build_heap();

  // build a huffman tree of char_queue
  huffman_tree * tree = new huffman_tree(char_queue);

  tree->print_huffman_tree();

  _encoder->load_bits_from(map);
  _encoder->write_heading(map);
  _encoder->encode();

 cout << "Compression Sucessful!!" << endl;
 cout << "File : " << filename << " is compressed to " << _encoder->make_file_out_name() << endl;

  delete _encoder;
  delete map;
  delete arr;
  delete char_queue;
  delete tree;
}




void decompress(string filename){

  char_map * map              = new char_map(MAX_CHAR_MAP_SIZE);
  decoder * _decoder          = new decoder(filename, _INIT_CAP);
  myarrlist<char_node*> * arr = new myarrlist<char_node*>();
  p_queue * char_queue        = new p_queue();

  _decoder->read_heading(arr);

  // iterateratively add char to queue
  for(int i = 0; i < arr->size(); i++)
      char_queue->add((*arr)[i]);

  char_queue->build_heap();

  huffman_tree * tree = new huffman_tree(char_queue);

  tree->print_huffman_tree();

  _decoder->decode(tree);

  cout << "Decompression Successful!" << endl;
  cout << "File : " << filename << " decompressed to " << _decoder->make_file_out_name() << endl;

  delete _decoder;
  delete map;
  delete arr;
  delete char_queue;
  delete tree;
}




/*
*
**************MAIN********************
*
*/
int main(int argc, char * argv[]){

  bool is_compress = true; // default
  string filename;

  if(argc < 1){

    cout << "Arguments required! Enter file to compress and mode(optional)." << endl;
    return -1;

  }else if(argc == 3){

    string d("-d"); // decompress mode
    string c("-c"); // compress mode

    if(d.compare(argv[1]) == 0){
      is_compress = false;
    }else if(c.compare(argv[1]) == 0){
      is_compress = true;
    }else{
      cout << "Invalid mode: -c to compress, -d to decompress." << endl;
      return -1;
    }

    filename = (argv[2]);

  }else{ // default compress mode

    filename = (argv[1]);

  }



  if(is_compress){
    compress(filename);
  }else{
    decompress(filename);
  }





  return 0;
}
