#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"

#define SIZE 5

void quicksort(int *arr, int left, int right);

int main(void){
  srand(time(NULL));
  int arr[SIZE];
  fill_with_random_numbers(arr, 0, SIZE, 101);
  fprintf(stdout, "before quick sort: ");
  print_array(arr, SIZE);
  fprintf(stdout, "after quick sort: ");
  quicksort(arr, 0, SIZE-1);
  print_array(arr, SIZE);
  return 0;
}


void quicksort(int *arr, int left, int right){
  int i=left, j=right, pivot = arr[(left+right)/2];
  while(i<=j){
    while(i<right && arr[i]<pivot){
      i++;
    }
    while(j>left && arr[j]>pivot){
      j--;
    }
    if(i<=j){
      swap(arr, i, j);
      i++;
      j--;
    }
  }
  if(j>left){
    quicksort(arr, left, j);
  }
  if(i<right){
    quicksort(arr, i, right);
  }
}
