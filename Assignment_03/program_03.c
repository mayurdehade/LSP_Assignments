// write a program to move all files from one directory to another

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
#define MAX_PATH 256

int CopyAndDeleteFiles(const char *src, const char *dest)
{
    int src_fd, dest_fd;
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead, bytesWritten;
    struct stat sb;

    //open file
    src_fd = open(src, O_RDONLY);
    if (src_fd == -1)
    {
        perror("open source");
        return -1;
    }

    //get stat of file for get permissions
    if (lstat(src, &sb) == -1)
    {
        perror("lstat");
        close(src_fd);
        return -1;
    }

    //create new file in destination directory
    dest_fd = open(dest, O_WRONLY | O_CREAT | O_TRUNC, sb.st_mode);
    if (dest_fd == -1)
    {
        perror("open destination");
        close(src_fd);
        return -1;
    }

    //read and write all bytes of files from source to destination file
    while ((bytesRead = read(src_fd, buffer, BUFFER_SIZE)) > 0)
    {
        //write bytes to destination file
        bytesWritten = write(dest_fd, buffer, bytesRead);
        if (bytesWritten != bytesRead)
        {
            perror("write");
            close(src_fd);
            close(dest_fd);
            return -1;
        }
    }

    //close files
    close(src_fd);
    close(dest_fd);

    //delete file from source directory
    unlink(src);
    return 0;
}

int main()
{
    char src_dir[MAX_PATH];
    char dest_dir[MAX_PATH];
    char src_path[MAX_PATH];
    char dest_path[MAX_PATH];
    DIR *dp = NULL;
    struct dirent *ptr = NULL;
    struct stat sb;
    int movedCount = 0;

    //get source directory name
    printf("Enter source directory: ");
    scanf("%s", src_dir);

    //get destination directory name
    printf("Enter destination directory: ");
    scanf("%s", dest_dir);

    //open directory
    dp = opendir(src_dir);
    if (dp == NULL)
    {
        perror("opendir");
        return -1;
    }

    while ((ptr = readdir(dp)) != NULL)
    {
        if (strcmp(ptr->d_name, ".") == 0 ||
            strcmp(ptr->d_name, "..") == 0)
            continue;

        //build source path
        strcpy(src_path, src_dir);
        strcat(src_path, "/");
        strcat(src_path, ptr->d_name);

        //build destination path
        strcpy(dest_path, dest_dir);
        strcat(dest_path, "/");
        strcat(dest_path, ptr->d_name);

        if (lstat(src_path, &sb) == -1)
            continue;

        // move only regular files
        if (S_ISREG(sb.st_mode))
        {
            if (rename(src_path, dest_path) == -1)
            {
                // copy files to destination and delete from source
                if (CopyAndDeleteFiles(src_path, dest_path) == 0)
                {
                    movedCount++;
                }
            }
            else
            {
                movedCount++;
            }
        }
    }

    //close directory
    closedir(dp);

    printf("Total files moved: %d\n", movedCount);
    return 0;
}
