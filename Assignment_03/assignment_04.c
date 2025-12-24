// write a program to delete the empty files

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 256

int main()
{
    char dirName[MAX_PATH];
    char fullPath[MAX_PATH];
    DIR *dp;
    struct dirent *ptr;
    struct stat sb;
    int deleteCount = 0;

    //get directory name from user
    printf("Enter directory name: ");
    scanf("%s", dirName);

    //open directory
    dp = opendir(dirName);
    if (dp == NULL)
    {
        perror("opendir failed");
        return -1;
    }

    //read directory
    while ((ptr = readdir(dp)) != NULL)
    {
        //skip the . and .. entries
        if (strcmp(ptr->d_name, ".") == 0 ||
            strcmp(ptr->d_name, "..") == 0)
            continue;
        
        //create full path
        strcpy(fullPath, dirName);
        strcat(fullPath, "/");
        strcat(fullPath, ptr->d_name);

        //get stat of file to get size
        if (lstat(fullPath, &sb) == -1)
            continue;

        //if size is 0 then unlink file
        if (S_ISREG(sb.st_mode) && sb.st_size == 0)
        {
            //unlink file
            if (unlink(fullPath) == 0)
            {
                printf("Deleted: %s\n", ptr->d_name);
                deleteCount++;
            }
        }
    }

    //close directory
    closedir(dp);

    printf("Total empty files deleted: %d\n", deleteCount);
    return 0;
}
