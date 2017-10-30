/* deb2.c  */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv []) 
{
    double d;
    d = strtod(argv[1],NULL);

    printf("The square root of %lf is %lf\n", d, sqrt(d));

	return 0;
}
