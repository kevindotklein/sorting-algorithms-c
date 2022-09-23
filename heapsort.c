#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"

#define SIZE 5

void heap(int *arr, int size, int i);
void heapsort(int *arr, int size);

int main(void){
  srand(time(NULL));
  int arr[SIZE];
  fill_with_random_numbers(arr, 0, SIZE, 101);
  fprintf(stdout, "before heap sort: ");
  print_array(arr, SIZE);
  fprintf(stdout, "after heap sort: ");
  heapsort(arr, SIZE);
  print_array(arr, SIZE);
  return 0;
}

void heapsort(int *arr, int size){
  for(int i=size/2-1; i>=0; i--){
    heap(arr, size, i);
  }

  for(int i=size-1; i>=0; i--){
    swap(arr, 0, i);
    heap(arr, i, 0);
  }
}

void heap(int *arr, int size, int i){
  int root=i;
  int left = 2*i+1;
  int right = 2*i+2;

  if(left < size && arr[left] > arr[root]) root = left;
  if(right < size && arr[right] > arr[root]) root = right;

  if(root != i){
    swap(arr, i, root);
    heap(arr, size, root);
  }
}
