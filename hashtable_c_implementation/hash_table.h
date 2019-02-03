#include <stdint.h>

typedef struct jsb_hash_table_str_str jsb_hash_table_str_str;

/*
  Hash table header for <char*,char*> hash table.
*/

struct jsb_hash_table_str_str{
  uint64_t   size;
  uint64_t   count;
  
  char ** keys;
  char ** values;
  
};


/*
  The prototypes for the
  operations allowed to be performed on the
  <char*,char*> hash table.
*/

jsb_hash_table_str_str * new_ht(uint64_t max_size);
uint16_t free_ht(jsb_hash_table_str_str * ht);
uint16_t insert(jsb_hash_table_str_str * t, char * key, char * value);
uint16_t delete(jsb_hash_table_str_str * t, char * key, char * value);
