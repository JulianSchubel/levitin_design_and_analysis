/* 
    Write an algorithm for sorting integer numbers in ascending order using any sorthing technique.
*/

#include <stdio.h>

void sort(int * array, int size) 
{
    int swap_occurred = 1;
    while(swap_occurred) {
        swap_occurred = 0;
        for( int i = 0; i < size-1; ++i ) {
            if( array[i] > array[i + 1] ) {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swap_occurred = 1;
            }
        }
    }
}

int main(int argc, char * argv[])
{
        int array[] = {23,45,12,37,11,56}; 
        const int array_size = 6;
        sort(array, array_size);
        for(int i = 0; i < array_size; ++i) {
            printf("%d ", array[i]);
        } 
        printf("\n");
        return 0;
}
