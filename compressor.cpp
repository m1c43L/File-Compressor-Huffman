#include "headerfiles/encoder.h"
#define _INIT_CAP 10000
using namespace std;


int main(int argc, char * argv[]){

bool is_compress = true;
string filename;
char asc = 129;
cout << asc << endl;
if(argc < 1){
  cout << "Arguments required! Enter file to compress and mode(optional)." << endl;
  return -1;
}else if(argc == 3){
  string d("-d");
  string c("-c");
  if(d.compare(argv[1]) == 0){
    is_compress = false;
  }else if(c.compare(argv[1]) == 0){
    is_compress = true;
  }else{
    cout << "Invalid mode: -c to compress, -d to decompress." << endl;
    return -1;
  }
  filename = (argv[2]);
}else{
  filename = (argv[1]);
}

char_map * map     = new char_map(270);

if(is_compress){
  encoder * compress = new encoder(filename, _INIT_CAP);
  compress->load_chars_to(map);
  myarrlist<char_node*> * arr = map->get_map();
  p_queue * q = new p_queue();
  for(int i = 0; i < arr->size(); i++){
      q->add((*arr)[i]);
  }
  q->build_heap();
  huffman_tree * t = new huffman_tree(q);
  t->print_huffman_tree();
  compress->load_bits_from(map);
  compress->write_heading(map);
  compress->encode();

 cout << "Compression Sucessful!!" << endl;
 cout << "File : " << filename << " is compressed to " << compress->make_file_out_name() << endl;

  delete compress;
  delete map;
  delete arr;
  delete q;
  delete t;

}else{

  decoder * decode = new decoder(filename, _INIT_CAP);
  myarrlist<char_node*> * arr = new myarrlist<char_node*>();
  decode->read_heading(arr);
  p_queue * q = new p_queue();
  for(int i = 0; i < arr->size(); i++){
      q->add((*arr)[i]);
  }
  q->build_heap();
  huffman_tree * t = new huffman_tree(q);
  t->print_huffman_tree();
  decode->decode(t);
  cout << "Decoding Successful!" << endl;

}





  return 0;
}
