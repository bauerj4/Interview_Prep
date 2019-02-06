#ifndef __MERGE_SORT_HPP__
#define __MERGE_SORT_HPP__

#include <iostream>
#include <thread>
#include <cstdint>
#include "copy_array.hpp"

/*
  Implementation of top-down merge sort
*/

/*
template <typename T>
void merge_sort(T * arr, T * arr_cpy, uint32_t size){
  copy_array(arr,arr_cpy,0,size);
  merge_sort_split(arr,arr_cpy,0,size);
  }*/
template <typename T>
void merge_sort_merge(T * arr, T * arr_cpy, uint32_t begin, uint32_t end){
  uint32_t mid, left_runner, right_runner;

  mid          = (begin + end)/2;

  left_runner  = begin;
  right_runner = mid;

  std::cout << mid << std::endl;

  for (uint32_t i = begin; i < end; i++){
    //std::cout << i << " " << left_runner << " " << right_runner << std::endl;
    if (right_runner == end){
      arr_cpy[i] = arr[left_runner];
      left_runner++;
    }

    else if (left_runner == mid){
      arr_cpy[i] = arr[right_runner];
      right_runner++;
    }

    else if (arr[left_runner] <= arr[right_runner]){
      arr_cpy[i] = arr[left_runner];
      left_runner++;
    }

    else if (arr[left_runner] > arr[right_runner]){
      arr_cpy[i] = arr[right_runner];
      right_runner++;
    }
  }
}

template <typename T>
void merge_sort_split(T * arr, T * arr_cpy, uint32_t begin, uint32_t end){
  uint32_t mid;

  /*
    Should check that input is sane
  */
  
  mid = (begin + end)/2; //begin + (end - begin) / 2 is the midpoint


  /*
    Base case that array can't be split
  */
  
  if (end - begin < 2){
    return;
  }

  /*
    Split arrray in half
  */
  
  merge_sort_split(arr,arr_cpy,begin,mid);
  merge_sort_split(arr,arr_cpy,mid,end);

  /*
    Merge the two halves.
  */

  merge_sort_merge(arr,arr_cpy,begin,end);
}


template <typename T>
void merge_sort(T * arr, T * arr_cpy, uint32_t size){
  copy_array(arr,arr_cpy,0,size);
  merge_sort_split(arr,arr_cpy,0,size);
}


template void merge_sort(int * arr, int * arr_cpy, uint32_t size);
template void merge_sort_split(int * arr, int * arr_cpy, uint32_t begin, uint32_t end);
template void merge_sort_merge(int * arr, int * arr_cpy, uint32_t begin, uint32_t end);
#endif
