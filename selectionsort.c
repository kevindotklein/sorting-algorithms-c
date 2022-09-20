#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"

#define SIZE 5

void selectionsort(int *arr, int size);

int main(void){
  srand(time(NULL));
  int arr[SIZE];
  fill_with_random_numbers(arr, 0, SIZE, 101);
  fprintf(stdout, "before selection sort: ");
  print_array(arr, SIZE);
  selectionsort(arr, SIZE);
  fprintf(stdout, "after selection sort: ");
  print_array(arr, SIZE);
  return 0;
}

void selectionsort(int *arr, int size){
  for(int i=0; i<size; i++){
    int min=i;
    for(int j=i+1; j<size; j++){
      if(arr[j] < arr[min]){
	min = j;
      }
    }
    swap(arr, i, min);
  }
}
