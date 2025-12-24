// write a program to check file present in directory

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<limits.h>
#include<stdlib.h>

#define MAX_PATH_SIZE 100
#define FULL_PATH_SIZE 250

//get directory and file name
void GetDirectoryAndFileName(char *dir_name, char *file_name)
{
    //set null bytes into file path buffer
    memset(dir_name, '\0', MAX_PATH_SIZE);
    memset(file_name, '\0', MAX_PATH_SIZE);

    printf("Enter name of directory: ");
    scanf("%s", dir_name);

    printf("Enter name of file: ");
    scanf("%s", file_name);
}

int main()
{
    char dir_name[MAX_PATH_SIZE];
    char file_name[MAX_PATH_SIZE];
    char full_path[FULL_PATH_SIZE];
    char abs_path[FULL_PATH_SIZE];
    DIR *dp = NULL;
    struct dirent *ptr = NULL;

    //get directory and file name from user
    GetDirectoryAndFileName(dir_name, file_name);

    //open directory
    dp = opendir(dir_name);

    //check for error
    if(dp == NULL)
    {
        perror("Directory not opened");
        return -1;
    }

    //read directory files
    while((ptr = readdir(dp)) != NULL)
    {
        //check if the is found
        if(strcmp(ptr->d_name, file_name) == 0)
        {
            //set null butes to full_path buffer
            memset(full_path, '\0', FULL_PATH_SIZE);

            //create relative path
            strcpy(full_path, dir_name);
            strcat(full_path, "/");
            strcat(full_path, file_name);

            //create absolute path
            if(realpath(full_path, abs_path) != NULL)
            {
                printf("File found at: %s\n", abs_path);
            }
            else 
            {
                perror("absolute path failed\n");
            }

            //close directory
            closedir(dp);
            return 0;
        }
    }

    closedir(dp);
    printf("File not found in directory.\n");
    
    return -1;
}