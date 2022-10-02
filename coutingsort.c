#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utils.h"

#define SIZE 5

void coutingsort(int *arr, int size);
int get_max(int *arr, int size);

int main(void){
  srand(time(NULL));
  int arr[SIZE];
  fill_with_random_numbers(arr, 0, SIZE, 101);
  fprintf(stdout, "before couting sort: ");
  print_array(arr, SIZE);
  fprintf(stdout, "after couting sort: ");
  coutingsort(arr, SIZE);
  print_array(arr, SIZE);
  return 0;
}

void coutingsort(int *arr, int size){
  int k = get_max(arr, size);
  int *c = calloc(k+1, sizeof(int));
  int *s = malloc(size * sizeof(int));
  int t, acc=0;
  for(int i=0; i<size; i++){
    c[arr[i]]++;
  }

  for(int j=0; j<=k; j++){
    t=c[j];
    c[j]=acc;
    acc+=t;
  }

  for(int j=0; j<size; j++){
    s[c[arr[j]]] = arr[j];
    c[arr[j]]++;
  }

  memcpy(arr, s, sizeof(int)*size);
  free(s);
  free(c);
}

int get_max(int *arr, int size){
  int max = arr[0];
  for(int i=0; i<size; i++){
    if(arr[i]>max) max = arr[i];
  }
  return max;
}
