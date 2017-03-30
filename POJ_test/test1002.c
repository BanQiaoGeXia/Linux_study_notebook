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

int read_from_file(char **buff, FILE *file, int file_length)
{
    int lines = 0;
    char *data = (char *)malloc(file_length);
    memset(data, 0, file_length);
    char *buf = (char *)malloc(20);
    memset(buf, 0, 20);
    char *sub_str = (char *)malloc(10);
    memset(sub_str, 0, 10);
    fseek(file, 0, SEEK_SET);
    while(!feof(file))
    {
        fgets(buf, 20, file);
        printf("%s", buf);
        if (trans2num(buf, &sub_str) != 0)
        {
            printf("error in trans2num");
            return 1;
        }
        strcat(data, sub_str);
        lines++;
    }
    free(sub_str);
    free(*buff);
    *buff = data;
    free(buf);
    return lines;
}

int trans2num(char *buff, char **sub_str)
{
    char *m_buff = buff;
    char *p, *q;
    for(p = m_buff, q = m_buff; *p != '\0'; p++)
    {
        if(*p >= '0' && *p <= '9')
            *q++ = *p;
        else if(*p >= 'A' && *p < 'Q')
        {
            *q++ = ((*p - 59) / 3) + 48;
        }
        else if(*p > 'Q' && *p < 'Z')
        {
            *q++ = ((*p - 60) / 3) + 48;
        }
    }
    *q++ = '\n';
    *q = *p;
    *sub_str = m_buff;
    return 0;
}

int count_tel_nums(char *buff, int lines)
{
    printf(">>>>>>>>  %d\n", lines);
    char tel_num[lines][8];
    int count[lines];






    return 0;
}
