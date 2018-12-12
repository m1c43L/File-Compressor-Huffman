#include "headerfiles/huffman_utils.h"
using namespace std;

/* Writes the bit sequence into string representation.
*
*/
void huffman_tree::encode(char_node * node, string sym){

  if(node == NULL){
    return;
  }else if(node->is_internal_node){
    string temp(sym);
    encode(node->left, (temp += "0"));
    string temp1(sym);
    encode(node->right, (temp1 += "1"));
  }else{
    node->code = sym;
  }

}


/*
*  Accepts min-heap queue
*  builds the huffman tree from the smallest
*  to largest char frequency
*/
huffman_tree::huffman_tree(p_queue * queue){

  int n = queue->size() - 1;

  // huffman coding
  for(int i = 0; i < n; i++){
    root = new char_node();
    root->left  = queue->get_top();
    root->right = queue->get_top();
    root->frequency = root->right->frequency + root->left->frequency;
    queue->add(root);
  }

  if(n == 0){ // 1 item.
    root =  queue->get_top();
  }

  encode(root, ""); // writes the bit sequnce using string.

}// end of constructor


huffman_tree::~huffman_tree(){

}


void huffman_tree::print_huffman_tree(){

  char_node * temp = root;
  tree_print_traverse(temp);

}


void huffman_tree::tree_print_traverse(char_node * node){

  if(node == NULL) return;
  if(node->is_internal_node){
    tree_print_traverse(node->left);
    tree_print_traverse(node->right);
  }else{
    cout << "( "<< node->unique_char << " - " << node->code <<" )" << endl;
  }

}


/*
* 
*/
void huffman_tree::decode_write(myarrlist <bool> *bits, string original_file_name){

  std::ofstream outputfile(original_file_name, std::ofstream::out | std::ofstream::trunc);
  char_node * node = root;

  for(int i = 0; i < bits->size(); i++){

    if( (*bits)[i] )
      node = node->right;
    else
      node = node->left;

    if(!node->is_internal_node){
      outputfile << node->unique_char;
      node = root;
    }

  }


  outputfile.close();
}
