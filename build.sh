#!/bin/bash

set -xe

gcc -Wall -std=c99 bubblesort.c utils.c -o bubblesort.bin
gcc -Wall -std=c99 selectionsort.c utils.c -o selectionsort.bin
gcc -Wall -std=c99 insertionsort.c utils.c -o insertionsort.bin
gcc -Wall -std=c99 mergesort.c utils.c -o mergesort.bin
gcc -Wall -std=c99 quicksort.c utils.c -o quicksort.bin
gcc -Wall -std=c99 heapsort.c utils.c -o heapsort.bin
gcc -Wall -std=c99 coutingsort.c utils.c -o coutingsort.bin
gcc -Wall -std=c99 radix.c utils.c -o radix.bin
