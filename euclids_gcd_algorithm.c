/* Euclids algorithm for finding the GCD */

#include <stdio.h>

int gcd(int m, int n) 
{
    while(n != 0) {
        int temp = m;
        m = n;
        n = temp % n;
    }
    return m;
}

int main(int argc, char * argv[])
{
        printf("%d\n", gcd(3,2));
        return 0;
}
