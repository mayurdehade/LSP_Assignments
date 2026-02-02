int MyStrlen(char *str)
{
    int length = 0;
    while(str[length] != '\0')
    {
        length++;
    }
    return length;
}

void MyStrcpy(char *dest, char *src)
{
    while(*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

void MyStrncpy(char *dest, char *src, int n)
{
    int i;
    for(i = 0; i < n && src[i] != '\0'; i++)
    {
        dest[i] = src[i];
    }

    if(i < n)
    {
        dest[i] = '\0';
    }
}

void MyStrcat(char *dest, char *src)
{
    while(*dest != '\0')
    {
        dest++;
    }

    while(*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

int MyStrcmp(char *s1, char *s2)
{
    while(*s1 && *s2)
    {
        if(*s1 != *s2)
        {
            return *s1 - *s2;
        }
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

int MyStrncmp(char *s1, char *s2, int n)
{
    int i;
    for(i = 0; i<n; i++)
    {
        if(s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
        {
            return s1[i] - s2[i];
        }
    }
    return 0;
}

void Mystrrev(char *str)
{
    int len = MyStrlen(str);
    int i = 0; 
    int j = len - 1;

    while(i < j)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;

        i++;
        j--;
    }
}

char * MyStrchr(char *str, char ch)
{
    while(*str != '\0')
    {
        if(*str == ch)
        {
            return str;
        }
        str++;
    }
    return 0;
}