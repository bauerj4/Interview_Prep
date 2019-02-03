#include "hash_table.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_TABLE_SIZE 256
/*
  Implementation of the new hash table "constructor"
  for the <char*, char*> hash table.
*/


jsb_hash_table_str_str * new_ht(uint64_t size){
  jsb_hash_table_str_str * ht = malloc(sizeof(jsb_hash_table_str_str));
  
  ht->size  = size;
  ht->count = 0;

  ht->keys   = (char**)malloc(size * sizeof(char*));
  ht->values = (char**)malloc(size * sizeof(char*));

  for (uint64_t i = 0; i < ht->size; i++){
    ht->keys[i]  = NULL;
    ht->values[i]= NULL;
  }
  
  return ht;
}

/*
  Implementation of the hash table "destructor" for
  the <char*, char*> hash table.
*/

uint16_t free_ht(jsb_hash_table_str_str * ht){
  for (uint64_t i = 0; i < ht->size; i++){
    if (ht->keys[i] != NULL){
      free(ht->keys[i]);
    }

    if (ht->values[i] != NULL){
      free(ht->values[i]);
    }
  }
  free(ht->keys);
  free(ht->values);
  free(ht);

  return 0;
}

/*
  Implementation of the insert function for the <char*, char*> table
*/

uint16_t insert(jsb_hash_table_str_str * t, const char * key, const char * value){

  
  return 0;
}

int main(int argc, char**argv){

  // Create a <char*, char*> table

  printf("Creating hash table...\n");

  jsb_hash_table_str_str * ht = new_ht(MAX_TABLE_SIZE);

  

  printf("Created.\nFreeing hash table from memory...\n");
  
  free_ht(ht);
  
  printf("Done.\n");
  return 0;
}
