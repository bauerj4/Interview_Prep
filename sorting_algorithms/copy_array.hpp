#ifndef __COPY_ARRAY_HPP__
#define __COPY_ARRAY_HPP__

#include <cstdint>

/*
  Helper function that copies an array.
  Needed for not-in-place sorting.
*/
template <typename T>
void copy_array(T * a, T * b, uint32_t begin, uint32_t end){
  for (uint32_t i = begin; i < end; i++){
    b[i] = a[i];
  }
}

template void copy_array(int * a, int * b, uint32_t begin, uint32_t end);
#endif
