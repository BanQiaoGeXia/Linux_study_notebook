#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *open_file(const char *filename)
{
    FILE *f = fopen(filename, "r");
    if(f == NULL)
    {
        printf("open file failed\n");
        return NULL;
    }
    return f;
}

int close_file(FILE **file)
{
    FILE *f = *file;
    fclose(f);
    *file = NULL;
    return 1;
}

int get_file_size(FILE *f)
{
    if(f == NULL)
    {
        printf("file is NULL");
        return 0;
    }
    int len;
    fseek(f, 0, SEEK_END);
    len = ftell(f);
    return len;
}

int read_from_file(char **buff, FILE *file)
{

}
