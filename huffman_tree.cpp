#include "headerfiles/huffman_utils.h"
using namespace std;


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



/* TODO REWORK logic.
*  Accepts min-heap queue
*  builds the huffman tree from the smallest
*  to largest char frequency
*/
huffman_tree::huffman_tree(p_queue * queue){

   //assert ( !queue.is_empty() );

    // generate base tree
    root             = new char_node();
    root->right      = queue->get_top();
    root->frequency += root->right->frequency;

  // iteratively build tree by making the
  // current root the right subtree.
  while(!queue->is_empty()){

    root->left       = queue->get_top();
    root->frequency += root->left->frequency;

    if(!queue->is_empty()){
      char_node * temp = new char_node();
      temp->right      = root;
      temp->frequency += root->right->frequency;
      root             = temp;

    }// if

  }// while

  //encode(root, "");

}// end of constructor



huffman_tree::~huffman_tree(){

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

void huffman_tree::print_huffman_tree(){

  char_node * temp = root;

  tree_print_traverse(temp);

}
