#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void swap(int *arr, int a, int b){
  int tmp = arr[a];
  arr[a] = arr[b];
  arr[b] = tmp;
}

void fill_with_random_numbers(int *arr, int start, int end, int range){
  for(int i=start; i<end; i++){
    arr[i] = rand() % range;
  }
}

void print_array(int *arr, int size){
  for(int i=0; i<size; i++){
    fprintf(stdout, "%d ", arr[i]);
  }
  fputc('\n', stdout);
}
