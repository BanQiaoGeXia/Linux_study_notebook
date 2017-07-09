/*************************************************************************
 > File Name: t_file.h
 > Author: M.K
 > Mail: 
 > Created Time: 日  6/25 11:37:49 2017
 ************************************************************************/

#ifndef __T_FILE_H_
#define __T_FILE_H_


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

// open()函数例子
int t_open(char *filename);

// create 例子 安全打开文件
int create_file(char *filename);

// close 函数例子，系统打开文件上限
void close_file(int fd);

// t_read 函数例子，读文件
int t_read(char *filename);

// write 函数例子， 写文件
int t_copy(const char *src_filename, const char *dst_filename);

// lseek() 函数例子， 设置文件偏移量
int t_lseek(char *filename);

// fstat() 函数例子， 获取文件状态
#endif
