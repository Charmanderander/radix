/* overrun.c  */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv []) 
{
    int *bptr = (int *)malloc(sizeof(int) * 100);
    int *aptr = (int *)malloc(sizeof(int) * 100);

    int n;
    for ( n = 0; n < 100; n++ ) 
        aptr[n] = 1;

    for ( n = 0; n < 110; n++ )
        bptr[n] = 2;

    for ( n = 0; n < 10; n++ ) 
        printf("aptr[%d] = %d\n", n, aptr[n]);

    free(aptr);
    free(bptr);
	return 0;
}
