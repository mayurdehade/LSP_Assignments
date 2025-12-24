// write a program to find largest file in directory

#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<sys/types.h>
#include<dirent.h>
#include <sys/stat.h>

#define MAX_PATH_SIZE 100
#define FULL_PATH_SIZE 200

//get directory name from user
void GetDirectoryName(char *dirName)
{
    memset(dirName, '\0', MAX_PATH_SIZE);

    printf("Enter directory name to open: ");
    scanf("%s", dirName);
}

//check the special entries of . and ..
int SkipSpecialEntries(const char *name)
{
    if(strcmp(name, ".") == 0 || strcmp(name, "..") == 0)
    {
        return 1; //skip
    }
    return 0; //do not skip
}

int main()
{
    char dirName[MAX_PATH_SIZE];
    char fullPath[FULL_PATH_SIZE];
    char largestFile[MAX_PATH_SIZE];
    struct dirent *ptr = NULL;
    DIR *dp = NULL;
    struct stat sb;
    int iRet = 0;

    off_t maxSize = 0;

    //get directory name from user
    GetDirectoryName(dirName);

    //open directory
    dp = opendir(dirName);

    //check for error
    if(dp == NULL)
    {
        printf("%s\n", strerror(errno));
        return -1;
    }
    
    printf("Directory opened successfully...!\n");

    //read directory one by one for all files
    while((ptr = readdir(dp)) != NULL)
    {
        //skip special entires
        if(SkipSpecialEntries(ptr->d_name))
        {
            continue;
        }

        strcpy(fullPath, dirName);
        strcat(fullPath, "/");
        strcat(fullPath, ptr->d_name);

        iRet = lstat(fullPath, &sb);

        if(iRet == -1)
        {
            printf("Error occured: %s\n", strerror(errno));
            return -1;
        }

        //consider only regular file
        if(S_ISREG(sb.st_mode))
        {
            if(sb.st_size > maxSize)
            {
                maxSize = sb.st_size;
                strcpy(largestFile, ptr->d_name);
            }
        }
    }

    if(maxSize > 0)
    {
        printf("Largets File: %s\n", largestFile);
        printf("Size: %ld\n", (long)maxSize);
    }
    else{
        printf("No regular files found.\n");
    }

    closedir(dp);

    return 0;
}