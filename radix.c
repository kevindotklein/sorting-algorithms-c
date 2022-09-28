#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utils.h"

#define SIZE 5

void radix_sort(int *arr, int size);

int main(void){
  srand(time(NULL));
  
  return 0;
}

void radix_sort(int *arr, int size){
  int max = getMax(array, size);
  for (int place = 1; max / place > 0; place *= 10)
    countingSort(array, size, place);
}
