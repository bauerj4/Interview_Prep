#include <iostream>
#include <cstdint>
#include "merge_sort.hpp"

/*
  Simple driver program to test merge sort on ints
*/

int main(int argc, char ** argv){
  uint32_t size      = 9;
  int arr[]          = {5, 6, -1, 32, -20, 30, 19, -64, 1};
  int arr_srt[9];
  std::cout << "Initializing..." << std::endl;

  merge_sort<int>(arr, arr_srt, size);
  std::cout << "Unorted array: " << std::endl;
  for (unsigned int i = 0; i < size; i++){
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
  
  
  std::cout << "Sorted array: " << std::endl;
  for (unsigned int i = 0; i < size; i++){
    std::cout << arr_srt[i] << " ";
  }
  std::cout << std::endl;
}
