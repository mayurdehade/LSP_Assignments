//write a program to copy file content using pread & pwrite without changing the offset

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
    int iRet, bytesRead, offset;

    //open the src file
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

    //clear buffer
    memset(Buffer, '\0', BUFFER_SIZE);

    while((bytesRead = pread(srcFd, Buffer, BUFFER_SIZE-1, offset)) != 0)
    {
        Buffer[BUFFER_SIZE] = '\0';
        //write at offset
        iRet = pwrite(destFd, Buffer, bytesRead, offset);
        //update offset for read next bytes
        offset += iRet;
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

    printf("File data copied to antoher file successfully\n");

    //close file
    close(srcFd);
    close(destFd);


    return 0;
}
