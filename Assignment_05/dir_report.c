// write a program that recursively calculates totoal number of files
// total number of directories, totoal size of regualr files (in bytes)
// largest file name + size, count a directory when you enter it

#include<stdio.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>
#include<errno.h>

#define MAX_PATH 1024

long totalFiles = 0;
long totalDirs = 0;
long long totoalSize = 0;
char largestFile[MAX_PATH];
long long largestSize = 0;

int IsSpecialEntry(const char *name)
{
    return (strcmp(name, ".") == 0 || strcmp(name, "..") == 0);
}

void TraverseDirectory(const char *path)
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat sb;
    char fullPath[MAX_PATH];
    
    totalDirs++;

    dp = opendir(path);
    if(dp == NULL)
    {
        perror("Error while open directory");
        return;
    }

    while((entry = readdir(dp)) != NULL)
    {
        if(IsSpecialEntry(entry->d_name))
        {
            continue;
        }

        snprintf(fullPath, sizeof(fullPath), "%s/%s", path, entry->d_name);

        if(lstat(fullPath, &sb) == -1)
        {
            perror("lstat failed");
            continue;
        }

        //Regular file
        if(S_ISREG(sb.st_mode))
        {
            totalFiles++;
            totoalSize += sb.st_size;

            if(sb.st_size > largestSize)
            {
                largestSize = sb.st_size;
                strncpy(largestFile, entry->d_name, MAX_PATH - 1);
                largestFile[MAX_PATH - 1] = '\0';
            }
        }
        else if(S_ISDIR(sb.st_mode))
        {
            TraverseDirectory(fullPath);
        }
    }
    closedir(dp);
    
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Incorrect number of argument is passed...!");
        return -1;
    }

    TraverseDirectory(argv[1]);

    printf("\n--------- Directory Report ----------\n");
    printf("Files: %ld\n", totalFiles);
    printf("Dirs: %ld\n", totalDirs);
    printf("Total Size: %lld bytes\n", totoalSize);

    if(largestSize > 0)
    {
        printf("Largest: %s (%lld bytes)\n", largestFile, largestSize);
    }
    else
    {
        printf("Largest: None\n");
    }

    return 0;
}