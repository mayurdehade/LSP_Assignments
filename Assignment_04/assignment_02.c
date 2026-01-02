// Write a program to copy the file data from given offset to another file

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int srcFd, destFd;
    char Buffer[BUFFER_SIZE];
    int iRet = 0;
    int bytesRead = 0;
    int offset = 0;

    if(argc != 4)
    {
        printf("Incorrect number of argument is passed\n");
        return -1;
    }

    //open src file
    srcFd = open(argv[1], O_RDONLY);
    if(srcFd == -1)
    {
        printf("Error while opening source file: %s\n", strerror(errno));
        return -1;
    }

    //open destination file
    destFd = open(argv[2], O_WRONLY | O_CREAT, 0777);
    if(destFd == -1)
    {
        printf("Error while opening destination file: %s\n", strerror(errno));
        return -1;
    }

    offset = atoi(argv[3]); //convert char to int

    //changing the offset for read (set new offset)
    iRet = lseek(srcFd, offset, SEEK_SET);
    if(iRet == -1)
    {
        printf("%s\n", strerror(errno));
        return -1;
    }

    memset(Buffer, '\0', BUFFER_SIZE);

    while((bytesRead = read(srcFd, Buffer, BUFFER_SIZE-1)) != 0)
    {
        Buffer[BUFFER_SIZE] = '\0';
        //write data to dest file
        iRet = write(destFd, Buffer, bytesRead);
        if(iRet == -1)
        {
            printf("%s\n", strerror(errno));
            close(srcFd);
            close(destFd);
            return -1;
        }
        //clear buffer
        memset(Buffer, '\0', BUFFER_SIZE);
    }
    printf("File data copied to antoher file successfully from given offset\n");

    close(srcFd);
    close(destFd);

    return 0;
}