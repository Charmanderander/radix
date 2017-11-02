/* myip.c  
   A demo program making use of pipe to 
   read output from a child program
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main(int argc, char *argv []) 
{
        char mybuf[256], *ip;
        FILE *p = popen("/sbin/ifconfig", "r");
        while ( fgets(mybuf,256,p) ) {
           if ( strstr(mybuf, "inet addr:") ) {
               strtok(mybuf, ":");
               ip = strtok(NULL, " ");
               printf("%s\n", ip);
           }
        }
	return 0;
}
