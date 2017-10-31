/* storage_class.c  */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int n = 100; //global scope, static storage class (data segment)
const int const_arr[] = { 1,2,3,4,5,6,6,9,100,300 };

int main(int argc, char *argv []) 
{
    int arr[100]; //local scope, automatic storage class (stack)

    int *nptr = malloc(100 *sizeof(int)); //dynamic storage, (heap)

    printf("pid = %d, &n = %p, arr = %p,  nptr = %p const_arr = %p\n", getpid(), &n, arr, nptr, const_arr);

    fgetc(stdin);


	return 0;
}
