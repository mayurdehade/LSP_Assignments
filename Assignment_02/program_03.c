// write a program to list all files from directory

#include<stdio.h>
#include<string.h>
#include<errno.h>
#include <sys/types.h>
#include <dirent.h>

#define MAX_PATH 100

//get directory name from user
void GetDirectoryName(char *dirName)
{
    memset(dirName, '\0', MAX_PATH);

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
    char dirName[MAX_PATH];
    DIR *dp = NULL;
    struct dirent *ptr = NULL;

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
        //print file names
        printf("File name: %s\n", ptr->d_name);
    }

    closedir(dp);

    return 0;
}