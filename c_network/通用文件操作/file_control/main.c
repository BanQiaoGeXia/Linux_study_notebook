/*************************************************************************
 > File Name: main.c
 > Author: M.K
 > Mail: 
 > Created Time: 日  6/25 11:50:16 2017
 ************************************************************************/

#include <stdio.h>

#include "t_file.h"

int main(int argc, char *argv[])
{
    //int fd = -1;
    //fd = t_open(argv[1]);
    //fd = create_file(argv[1]);
    //close_file(fd);
    //t_read(argv[1]);
    //t_copy(argv[1], argv[2]);
    t_lseek(argv[1]);
    return 0;
}
