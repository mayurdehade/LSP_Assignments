//write a program for merge multiple input file into a single output file

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{   
    int srcFd, destFd;
    char Buffer[BUFFER_SIZE];
    int iRet, bytesRead;

    //incorrect argument error
    if(argc < 3)
    {
        printf("Incorrect number of argument is passed\n");
        return -1;
    }

    //open output file
    destFd = open(argv[1], O_WRONLY | O_CREAT, 0777);
    if(destFd == -1)
    {
        printf("Error occured: %s\n", strerror(errno));
        return -1;
    }

    for(int i=2; i<argc; i++)
    {
        //open source file
        srcFd = open(argv[i], O_RDONLY); //open in read mode only

        memset(Buffer, '\0', BUFFER_SIZE);

        while((bytesRead = read(srcFd, Buffer, BUFFER_SIZE-1)) != 0)
        {
            Buffer[BUFFER_SIZE] = '\0';
            iRet = write(destFd, Buffer, bytesRead);
            if(iRet == -1)
            {
                printf("Error during write: %s\n", strerror(errno));
                close(srcFd);
                close(destFd);
                return -1;
            }
            memset(Buffer, '\0', BUFFER_SIZE);
        }
        close(srcFd);
    }

    printf("Files data copied to destination file\n");
    close(destFd);

    return 0;
}