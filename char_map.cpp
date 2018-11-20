#include "headerfiles/huffman_utils.h"


char_map::char_map(int encoding_size){
  map = new myarrlist<char_node*>(encoding_size);
  for(int i = 0; i < encoding_size; i++){
    map->add(NULL);
  }
}

char_map::~char_map(){
  //delete map;
}

myarrlist<char_node*> * char_map::get_map(){

  myarrlist <char_node*> * temp = new myarrlist<char_node*>();

  for(int i = 0; i < map->size(); i++){
    if((*map)[i] != NULL) temp->add((*map)[i]);
  }

  return temp;
}

void char_map::increment_char(int character){

  if((*map)[character] == NULL){
    (*map)[character] = new char_node(character, 1, false);
  }else{
    (*map)[character]->frequency++;
  }

}
