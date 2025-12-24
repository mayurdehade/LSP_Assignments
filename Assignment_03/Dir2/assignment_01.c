// write a program to copy file contents from source to destination

#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>


#define MAX_PATH_SIZE 100
#define BUFFER_SIZE 1024

void GetSourceAndDestination(char *source_file, char *dest_file)
{
    //set null bytes into file path buffer
    memset(source_file, '\0', MAX_PATH_SIZE);
    memset(dest_file, '\0', MAX_PATH_SIZE);

    printf("Enter name of source file: ");
    scanf("%s", source_file);

    printf("Enter name of destination file: ");
    scanf("%s", dest_file);
}

int main()
{
    char source_file[MAX_PATH_SIZE];
    char dest_file[MAX_PATH_SIZE];
    char Buffer[BUFFER_SIZE];
    int source_fd = 0;
    int dest_fd = 0;
    int iRet = 0;
    int iWrite = 0;
    struct stat sb;    

    GetSourceAndDestination(source_file, dest_file);

    //open soruce file in read mode
    source_fd = open(source_file, O_RDONLY);

    if(source_fd == -1)
    {
        perror("Source file open failed\n");
    }

    if(stat(source_file, &sb) == -1)
    {
        perror("stat failed");
        close(source_fd);
        return -1;
    }

    //open destination file in write mode
    dest_fd = open(dest_file, O_WRONLY | O_CREAT | O_TRUNC, 0777);

    if(dest_fd == -1)
    {
        perror("Destination file open failed\n");
    }

    while((iRet = read(source_fd, Buffer, BUFFER_SIZE-1)) > 0)
    {
        Buffer[BUFFER_SIZE] = '\0';
        iWrite = write(dest_fd, Buffer, iRet);

        if(iWrite != iRet)
        {
            perror("Write failed");
            close(source_fd);
            close(dest_fd);
            return -1;
        }

    }

    printf("File contents copied successfully...!\n");

    //preserve permissions
    chmod(dest_file, sb.st_mode);

    close(source_fd);
    close(dest_fd);


    return 0;
}