/* now.c  */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv []) 
{
    struct tm *mytm;
    time_t now = time(NULL); //time_t is epoch time is in UTC
    printf("now = %ld\n", now);

    mytm = localtime(&now);
    printf("year = %d, month = %d, day = %d\n", 
            mytm->tm_year + 1900,
            mytm->tm_mon + 1,
            mytm->tm_mday);

    printf("ctime(&now) = %s", ctime(&now));
	return 0;
}
