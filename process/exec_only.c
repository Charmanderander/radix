/* exec_only.c  */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv []) 
{

    execl("/bin/ls", "/bin/ls", "-l", NULL);
    printf("this won't print\n");
	return 0;
}
