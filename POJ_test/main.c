#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "test1002.h"

int mission_workflow_1002()
{
    /* 程序主逻辑:
     *
     * 第一步: 打开文件
     * 第二步: 循环 按行读取文件内容
     * 第三步: 对每一行读取的内容去掉固定分隔符
     * 第四步: 对去掉分隔符的内容转换成纯数字 判断位数 必须为7位
     * 第五步: 比较计数每一个号码出现的次数
     * 第六步: 整合输出结果
     */
    char *filename = "E:/Qt_study/POJ_test/data1002.txt";
    FILE *file;
    int file_length;
    char *file_data;

    // open file
    file = open_file(filename);
    if(file == NULL)    return 0;

    // get file len
    file_length = get_file_size(file);
    printf("length = %d\n", file_length);

    // read from file and format them
    file_data = (char *)malloc(file_length);
    memset(file_data, 0, file_length);
    read_from_file(&file_data, file);

    // close file and make the point NULL
    printf("%p\n", file);
    close_file(&file);
    printf("%p", file);
    return 0;
}


int main(void)
{
    mission_workflow_1002();
//    FILE *f = fopen(filename, "r");
//    if(f == NULL)
//    {
//        printf("open failed\n");
//    }
//    char line[20];
//    fseek(f, 0, SEEK_END);
//    int length = ftell(f);
//    printf("length = %d\n", length);
//    char *buff = (char *)malloc(length);
//    memset(buff, 0, length);
//    fseek(f, 0, SEEK_SET);
//    int i = 0;
//    while(!feof(f))
//    {
//        char* a = fgets(line, 20, f);
//        printf("%s", line);
//        printf("%d\n %s\n", ++i, a);
//    }
//    int n = fread(buff, length, 1, f);
//    printf("read %d bytes\n", n);
//    printf("Reading complete\n\n");
    return 0;
}
