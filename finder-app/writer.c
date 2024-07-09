//Author : Labeeb Ahmed 
//Description:     Accepts the following arguments: 
    //the first argument is a full path to a file (including filename) on the filesystem, referred to below as writefile; 
    //the second argument is a text string which will be written within this file, referred to below as writestr

    //Exits with value 1 error and print statements if any of the arguments above were not specified

    //Creates a new file with name and path writefile with content writestr, overwriting any existing file. 
    //Exits with value 1 and error print statement if the file could not be created.

#include <stdio.h>
#include <stdint.h>
#include <syslog.h>

#define ARG_COUNT_FIXED 3
int main (int argc, char **argv){ 
    FILE *file_handle;
    openlog("writer sys Log",0,LOG_USER);
    if (ARG_COUNT_FIXED > argc){    
        printf("Argument count does not match") ;
        return 1;
    }
    file_handle = fopen(argv[1],"w");
    fprintf (file_handle, "%s\n",argv[2]);
    syslog (LOG_DEBUG, "writing %s to %s", argv[2],argv[1]);
    fclose (file_handle);   

}