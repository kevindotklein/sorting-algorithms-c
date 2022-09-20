#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"

#define SIZE 5

void insertionsort(int *arr, int size);

int main(void){
  srand(time(NULL));
  int arr[SIZE];
  fill_with_random_numbers(arr, 0, SIZE, 101);
  fprintf(stdout, "before insertion sort: ");
  print_array(arr, SIZE);
  fprintf(stdout, "after insertion sort: ");
  insertionsort(arr, SIZE);
  print_array(arr, SIZE);
  return 0;
}

void insertionsort(int *arr, int size){
  for(int i=1; i<size; i++){
    int key = arr[i];
    int j = i-1;
    while(j>=0 && key<arr[j]){
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = key;
  }
}
