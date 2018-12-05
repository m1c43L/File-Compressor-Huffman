#include "headerfiles/huffman_utils.h"


char_map::char_map(int encoding_size){
  map = new myarrlist<char_node*>(encoding_size);
  for(int i = 0; i < encoding_size; i++){
    map->add(NULL);
  }
  char_node_count = 0;
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

  if(character < 0){ // handles negative chars
   character += 256;
  }

  if((*map)[character] == NULL){
    (*map)[character] = new char_node(character, 1, false);
    char_node_count ++;
  }else{
    (*map)[character]->frequency++;
  }

}


string char_map::get_code(int character){


    if(character < 0){ // handles negative chars
     character += 256;
    }

  return (*map)[character]->code;

}

int char_map::get_frequency(char character){

  return (*map)[character]->frequency;

}

/* return string representation of map to format charfrequency; */
string char_map::to_string(){
  string buffer("");
  for(int i = 0; i < map->size(); i++){
    if((*map)[i] != NULL){
      buffer.push_back((*map)[i]->unique_char);
      buffer.append(std::to_string((*map)[i]->frequency));
      buffer.push_back(';');
    }
  }

  return buffer;
}


int char_map::get_char_node_count(){
  return char_node_count;
}
