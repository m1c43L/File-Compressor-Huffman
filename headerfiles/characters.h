#define TYPE_CHAR char
#define TYPE_INT  unsigned int


struct char_node{

public:

  TYPE_CHAR unique_char;

  TYPE_INT frequency;

  bool is_internal_node;

  char_node * left;

  char_node * right;


  char_node(){
    unique_char      = '\0';
    frequency        = 0;
    is_internal_node = true;
    left             = NULL;
    right            = NULL;
  }

  // struct constructor
  // creates a char_node instance with altributes
  char_node( TYPE_CHAR character, TYPE_INT freq,  bool is_internal)
  : unique_char(character), frequency(freq),
    is_internal_node(is_internal)
    {
      left  = NULL;
      right = NULL;
    }


  // struct destructor
  // destroys struct and free memory.
  ~char_node(){  }

  bool operator==(const char_node & node){
    return this->frequency == node.frequency;
  }

  bool operator>(const char_node & node){
    return this->frequency > node.frequency;
  }

  bool operator<(const char_node & node){
    return this->frequency < node.frequency;
  }

};
