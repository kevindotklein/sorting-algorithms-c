#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"

#define SIZE 5

void mergesort(int *arr, int size);
void merge(int *arr, int *l, int left_size, int *r, int right_size);

int main(void){
  srand(time(NULL));
  int arr[SIZE];
  fill_with_random_numbers(arr, 0, SIZE, 101);
  fprintf(stdout, "before merge sort: ");
  print_array(arr, SIZE);
  fprintf(stdout, "after merge sort: ");
  mergesort(arr, SIZE);
  print_array(arr, SIZE);
  return 0;
}

void mergesort(int *arr, int size){
  if(size<2) return;
  int mid = size/2;
  int *l = (int*) malloc(mid*sizeof(int));
  int *r = (int*) malloc((size-mid)*sizeof(int));

  for(int i=0; i<mid; i++){
    l[i] = arr[i];
  }
  for(int j=mid; j<size; j++){
    r[j-mid] = arr[j];
  }

  mergesort(l, mid);
  mergesort(r, size-mid);
  merge(arr, l, mid, r, size-mid);
  free(l);
  free(r);
}

void merge(int *arr, int *l, int left_size, int *r, int right_size){
  int i=0,j=0,k=0;
  while(i<left_size && j<right_size){
    if(l[i] < r[j]){
      arr[k++] = l[i++];
    }else{
      arr[k++] = r[j++];
    }
  }

  while(i<left_size) arr[k++] = l[i++];
  while(j<right_size) arr[k++] = r[j++];
}
