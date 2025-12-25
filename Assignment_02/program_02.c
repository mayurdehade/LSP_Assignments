// Write a string to file

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>

#define BUFFER_SIZE 1024

int main()
{
    char fileName[100];
    char iBuffer[BUFFER_SIZE];
    int fd = 0;
    int iRet = 0;

    //get file name from user
    printf("Enter name of file: ");
    scanf("%s", fileName);

    //consume leftover line
    getchar();

    //clear buffer
    memset(iBuffer, '\0', BUFFER_SIZE);

    //get data from user
    printf("Enter string to write in file: ");
    fgets(iBuffer, BUFFER_SIZE, stdin);

    //open file in write and append mode
    fd = open(fileName, O_WRONLY | O_APPEND | O_CREAT, 0777);

    //handle error of file opening
    if(fd == -1)
    {
        printf("Unable to open file: %s\n", strerror(errno));
        return -1;
    }

    //write bytes in file
    iRet = write(fd, iBuffer, strlen(iBuffer));

    //handle error during write
    if(iRet == -1)
    {
        printf("Unable to write in file: %s\n", strerror(errno));
        return -1;
    }

    //printf the total written bytes
    printf("%d bytes written successfully into file.\n", iRet);

    //close file
    close(fd);

    return 0;
}

