/*************************************************************************
 > File Name: t_open.c
 > Author: M.K
 > Mail: 
 > Created Time: 日  6/25 11:34:17 2017
 ************************************************************************/
#include "t_file.h"

// open()函数例子
int t_open(char *filename)
{
    int fd = -1;        //声明一个文件描述符
    fd = open(filename, O_RDWR);
    if(-1 == fd){
       printf("Open file %s failure!, fd : %d\n", filename, fd);
    }
    else{

       printf("Open file %s success!, fd : %d\n", filename, fd);
    }

    return fd;
}


// create 例子
int create_file(char *filename)
{
    int fd = -1;
    //O_CREAT   可以创建文件  结合 O_EXCL可以编写容错程序
    //打开文件  如果文件不存在就报错
    fd = open(filename, O_RDWR|O_CREAT|O_EXCL|S_IRWXU);
    if(-1 == fd)
    {
        printf("File %s exist! reoprn it ", filename);
        fd = open(filename, O_RDWR);  //重新打开
        printf("fd:%d\n", fd);
    }
    else
    {   
        printf("Open file %s success, fd: %d\n", filename, fd);
    }   
    return fd;
}


// close 函数例子，系统打开文件上限
void close_file(int fd)
{
    close(fd);
}


// t_read 函数例子，读文件
int t_read(char *filename)
{
    ssize_t size = -1;
    int fd = -1;
    int i = 0;
    char buf[40];
    fd = open(filename, O_RDONLY);
    if(-1 == fd)
    {
        printf("Open file %s failure, fd: %d\n", filename, fd);
    }
    else
    {
        printf("Open file %s success, fd: %d\n", filename, fd);
    }
    while(size)
    {
        size = read(fd, buf, 40);
        if(-1 == size)
        {
            close(fd);
            printf("read file error occurs\n");
            return -1;
        }
        else
        {
            if(size > 0)
            {
                printf("read %zd bytes:", size);
                printf("\"");
                for(i = 0; i < size; i ++)
                    printf("%c", *(buf+i));
                printf("\"\n");
            }
            else
            {
                printf("reach the end of file\n");
            }   
        }
    }
    return 0;
}


// write 函数例子， 写文件
int t_copy(const char *src_filename, const char *dst_filename)
{
    int RW_size = 50;
    int fd_r = -1;
    int fd_w = -1;
    ssize_t size = -1;
    char buf[50] = {0};
    fd_r = open(src_filename, O_RDONLY);
    fd_w = open(dst_filename, O_RDWR|O_CREAT, S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);
    if(-1 == fd_r || -1 == fd_w)
    {
        printf("Open file failure, fd_r: %d, fd_w: %d", fd_r, fd_w);
        return -1;
    }
    else
    {
        printf("Open file success, fd_r: %d, fd_w: %d", fd_r, fd_w);
    }
    while(size)
    {
        size = read(fd_r, buf, RW_size);
        if(-1 == size)
        {
            close(fd_r);
            close(fd_w);
            printf("read file error occurs\n");
            return -1;
        }
        else
        {
            if(size > 0)
            {
                write(fd_w, buf, size);
            }
            else
                printf("\ncopy file end\n");
        }
    }
    return 0;
}


// lseek() 函数例子， 设置文件偏移量
int t_lseek(char *filename)
{   
    int fd = -1;
    off_t offset = -1;
    fd = create_file(filename);
    offset = lseek(fd, 0, SEEK_SET); //设置文件偏移量为文件开头
    printf("The file seek is %lld\n", offset);
    offset = lseek(fd, 0, SEEK_END); //设置文件偏移量为文件末尾
    printf("The file seek is %lld\n", offset);
    offset = lseek(fd, -1, SEEK_CUR); //设置文件偏移量为当前值
    printf("The file seek is %lld\n", offset);
    return 0;
}
