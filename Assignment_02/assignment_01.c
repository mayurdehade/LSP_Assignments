// Read whole file bytes

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>

#define BUFFER_SIZE 1024

int main()
{
    int fd = 0;
    char fileName[100];
    char Buffer[BUFFER_SIZE];
    int bytesRead = 0;
    int totalBytes = 0;

    //get file name from user
    printf("Enter file name to open the file: \n");
    scanf("%s", fileName);

    //open file in read mode
    fd = open(fileName, O_RDONLY);

    //handle error
    if(fd == -1)
    {
        printf("Unable to open file: %s\n", strerror(errno));
        return -1;
    }

    memset(Buffer, '\0', BUFFER_SIZE);

    //read file until read() return 0
    while((bytesRead = read(fd, Buffer, BUFFER_SIZE-1)) > 0)
    {
        Buffer[BUFFER_SIZE] = '\0';
        printf("%s", Buffer);
        totalBytes += bytesRead;
        
        //clear buffer
        memset(Buffer, '\0', BUFFER_SIZE);
    }

    //handle error during reading file
    if(bytesRead == -1) 
    {
        printf("\nError while reading file: %s\n", strerror(errno));
        close(fd);
        return -1;
    }

    //print total bytes read from file
    printf("\nTotal bytes read from file: %d\n", totalBytes);

    //close file
    close(fd);

    return 0;
}