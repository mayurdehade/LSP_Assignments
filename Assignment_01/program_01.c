// Write a program to open file, acept name from user and print fd.

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd = 0;
    char fileName[50];

    printf("Enter name of file: \n");
    scanf("%s", fileName);

    // open file in read mode
    fd = open(fileName, O_RDONLY);

    if (fd == -1)
    {
        perror("Unable to open file");
        return -1;
    }

    // if success printf fd
    printf("File opened successfully with fd: %d\n", fd);

    // close file
    close(fd);

    return 0;
}