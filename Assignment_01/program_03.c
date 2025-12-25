// Write a program to check file access permission

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

// convert mode to flag
int ConvertModeToFlag(char *mode)
{
    if (strcmp(mode, "R") == 0)
    {
        return R_OK;
    }
    else if (strcmp(mode, "W") == 0)
    {
        return W_OK;
    }
    else if (strcmp(mode, "X") == 0)
    {
        return X_OK;
    }
    else
    {
        return -1;
    }
}

int main()
{
    char fileName[50];
    char mode[2];
    int flag;
    int iRet = 0;

    // get file name
    printf("Enter file name to open: ");
    scanf("%s", fileName);

    // get mode
    printf("Enter mode (R/W/X): ");
    scanf("%s", mode);

    // conver mode to flag
    flag = ConvertModeToFlag(mode);

    // check if the mode is invalid
    if (flag == -1)
    {
        printf("Mode is invalid\n");
        return -1;
    }

    // check the access permission
    iRet = access(fileName, flag);

    // check if file is not accessible
    if (iRet == -1)
    {
        printf("File is Not Accessible: %s\n", strerror(errno));
        return -1;
    }

    printf("File is Accessible\n");

    return 0;
}