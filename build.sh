#!/bin/bash

set -xe

gcc -Wall -std=c99 bubblesort.c utils.c -o bubblesort.bin
gcc -Wall -std=c99 selectionsort.c utils.c -o selectionsort.bin

