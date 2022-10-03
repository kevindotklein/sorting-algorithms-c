#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utils.h"

#define SIZE 5

void radix_sort(int *arr, int size);
void counting_sort(int *arr, int size, int div, int base, int *tmp);
int get_max(int *arr, int size);

int main(void){
  srand(time(NULL));
  int arr[SIZE];
  fill_with_random_numbers(arr, 0, SIZE, 101);
  fprintf(stdout, "before radix sort: ");
  print_array(arr, SIZE);
  fprintf(stdout, "after radix sort: ");
  radix_sort(arr, SIZE);
  print_array(arr, SIZE);
  return 0;
}

void radix_sort(int *arr, int size){
  int div=1;
  int k = get_max(arr, size);
  int *tmp = malloc(sizeof(int) * size);
  while(k>0){
    counting_sort(arr, size, div, 10, tmp);
    div *= 10;
    k /= 10;
  }
  free(tmp);
}

int get_max(int *arr, int size){
  int max=arr[0];
  for(int i=0; i<size; i++){
    if(arr[i]>max) max = arr[i];
  }
  return max;
}

void counting_sort(int *arr, int size, int div, int base, int *tmp){
  int i, t, c[base], acc=0;
  memset(c, 0, base * sizeof(int));
#define DIGIT(X) (X/div)%base
  for(i=0; i<size; i++){
    c[DIGIT(arr[i])]++;
  }

  for(i=0; i<base; i++){
    t = c[i];
    c[i] = acc;
    acc += t;
  }

  for(i=0; i<size; i++){
    tmp[c[DIGIT(arr[i])]] = arr[i];
    c[DIGIT(arr[i])]++;
  }

  memcpy(arr, tmp, sizeof(int) * size);
}
