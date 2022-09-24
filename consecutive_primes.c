/* "Sieve of Eratosthenes" algorithm for finding consecutive primes not exceeding n*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print_array(int * array, int array_size)
{
    printf("[");
    for(int i = 0; i < array_size-1; ++i) {
       printf("%d,",array[i]); 
    }
    printf("%d]\n",array[array_size-1]);
}

/* consecutive_primes: returns a list of consecutive primes not exceeding n */
void consecutive_primes(int n, int * * output_array, int * output_array_size) 
{
    if(n < 2) {
        *output_array = (int*) malloc(sizeof(int));
        *output_array_size = 0;
        return;
    }
    /* p^2 cannot exceed n, that is p < sqrt(n) */
    int upper_bound = (int)sqrt((double)n);
    /* Non-primes eliminated */
    int omissions = 0;
    /* output array index */ 
    int k = 0;
    /* m - n + 1 */
    int integer_array_size = n - 1;
    int integer_array[integer_array_size];
    for(int i = 0; i < integer_array_size; ++i) {
        integer_array[i] = i + 2;
    }
    for(int i = 0; integer_array[i] <= upper_bound; ++i) {
        if (integer_array[i] != 0) {
            /* We start from p^2 as all other multiples 2p ... (p-1)p will have been eliminated */
            int j = integer_array[i] * integer_array[i];
            while(j <= n) {
                /* mark element as eliminated */
                if(integer_array[j-2] != 0) {
                    integer_array[j-2] = 0;
                    /* Record the omissions to calculate output array length without re-iterating over the array */
                    ++omissions;
                }
                /* Increment j to its next multiple */
                j = j + integer_array[i];
            }
        }
    }
    *output_array_size = integer_array_size - omissions;
    *output_array = (int *) malloc(sizeof(int) * (*output_array_size));
    for(int i = 0; i < integer_array_size; ++i) {
        if(integer_array[i] != 0) {
            (*output_array)[k++] = integer_array[i];
        }
    }
}

int main(int argc, char * * argv)
{
    int * output;
    int output_size;
    consecutive_primes(atoi(argv[1]), &output, &output_size);
    print_array(output, output_size);
    free(output);
    return 0;
}
