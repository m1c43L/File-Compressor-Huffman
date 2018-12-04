


class encoder{

private:

  string filename;

  myarrlist <bool> * bits;


  void append_char_to_bits(char );

  string make_file_out_name();


public:

  dencoder(string filename, int capacity);

  ~dencoder();

  void load_chars_to(char_map * map);

  void load_bits_from(char_map * map);

  void encode();

  void write_heading(int orig_extension, string header, int extra_bits_count);


};
