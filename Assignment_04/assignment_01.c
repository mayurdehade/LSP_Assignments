// Write a program that copies the contents of one file into another.

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int srcFd, destFd;
    ssize_t bytesRead;
    char Buffer[BUFFER_SIZE];
    int iRet = 0;

    //check argument array size
    if(argc != 3)
    {
        printf("Incorrect number of argument is passed\n");
        return -1;
    }

    //open source file
    srcFd = open(argv[1], O_RDONLY);
    if(srcFd == -1)
    {
        switch (errno)
        {
        case EACCES:
            printf("You do not have permission\n");
            break;
        
        case ENOENT:
            printf("File not found\n");
            break;
        
        default:
            printf("%s\n", strerror(errno));
        }
        return -1;
    }

    //open destination file or create if not exits
    destFd = open(argv[2], O_WRONLY | O_CREAT, 0777);
    if(destFd == -1)
    {
        perror("Error occured during open destination file\n");
        return -1;
    }

    //clear buffer
    memset(Buffer, '\0', BUFFER_SIZE);

    //reading file content and writting it in other file
    while((bytesRead = read(srcFd, Buffer, BUFFER_SIZE-1)) != 0)
    {
        Buffer[BUFFER_SIZE] = '\0';
        iRet = write(destFd, Buffer, bytesRead);
        if(iRet == -1)
        {
            perror("Error while writting data into file\n");
            close(srcFd);
            close(destFd);
            return -1;
        }
        //clear buffer
        memset(Buffer, '\0', BUFFER_SIZE);
    }

    printf("File content copied successfully...!\n");

    //close file
    close(srcFd);
    close(destFd);
    return 0;
}