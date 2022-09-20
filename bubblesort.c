#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"

#define SIZE 5

void bubblesort(int *arr, int size);

int main(void){
  srand(time(NULL));
  int arr[SIZE];
  fill_with_random_numbers(arr, 0, SIZE, 101);
  fprintf(stdout, "before bubble sort: ");
  print_array(arr, SIZE);
  bubblesort(arr, SIZE);
  fprintf(stdout, "after bubble sort: ");
  print_array(arr, SIZE);
  return 0;
}

void bubblesort(int *arr, int size){
  for(int i=0; i<size; i++){
    for(int j=0; j<size-i-1; j++){
      if(arr[j] > arr[j+1]){
	swap(arr, j, j+1);
      }
    }
  }
}
