// write a program to read N bytes from file and display it

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main()
{
    char fileName[100];
    int iNum = 0;
    int fd = 0;
    int iRet = 0;

    // get file name
    printf("Enter file name to open: ");
    scanf("%s", fileName);

    // get number of bytes
    printf("Enter number of bytes to read: ");
    scanf("%d", &iNum);

    // open file in read mode
    fd = open(fileName, O_RDONLY);

    // check if error is occured
    if (fd == -1)
    {
        printf("Unable to open file: %s\n", strerror(errno));
        return -1;
    }

    // create buffer for store file bytes
    char Buffer[iNum + 1];

    // clean buffer
    memset(Buffer, '\0', iNum + 1);

    // read bytes from file
    iRet = read(fd, Buffer, iNum);

    // check error
    if (iRet == -1)
    {
        printf("Error during read file bytes: %s\n", strerror(errno));
        return -1;
    }

    // display the bytes
    printf("Data from file: %s\n", Buffer);

    close(fd);

    return 0;
}
