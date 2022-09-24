/*  
    Design an algorithm to find the sorted list from two sorted lists of numbers.
    What is the maximum number of comparisons your algorithm makes if the lengths of the two given lists are m and n respectively? m * n
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void merge_sorted_lists(int * array1, int array1_size, int * array2, int array2_size, int * output_array)
{
    int i, j, k;
    i = j = k = 0;

    for(i, j; i < array1_size && j < array2_size; i,j) {
        if(array1[i] < array2[j]) {
            output_array[k++] = array1[i];
            ++i;
        }
        else if(array1[i] > array2[j]) {
            output_array[k++] = array2[j];
            ++j;
        }
        else {
            output_array[k++] = array1[i];
            ++i;
            output_array[k++] = array2[j];
            ++j;
        }
    }
    if(i != array1_size && j == array2_size) {
       for(i; i < array1_size; ++i) {
           output_array[k++] = array1[i];
       } 
    }
    else if(i == array1_size && j != array2_size) {
        for(j; j < array2_size; ++j) {
            output_array[k++] = array2[j];
        }
    }
}

int main(int argc, char * argv[])
{
        int array1_size = 6; 
        int array2_size = 5;
        int array1[] = {2,5,7,12,13,24};        
        int array2[] = {1,6,15,17,35};
        int output_array_size = array1_size + array2_size;
        int * output_array = (int*)malloc(sizeof(int)*output_array_size);
        merge_sorted_lists(array1, array1_size, array2, array2_size, output_array);
        for(int i = 0; i < output_array_size; ++i) {
            printf("%d ", output_array[i]);
        }
        return 0;
}
