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
    char *filename = "E:/Linux_study_notebook/POJ_test/data1002.txt";
    FILE *file;
    int file_length;
    char *file_data;
    int lines;

    // open file
    file = open_file(filename);
    if(file == NULL)    return 0;

    // get file len
    file_length = get_file_size(file);
    printf("length = %d\n", file_length);

    // read from file and format them
    file_data = (char *)malloc(file_length);
    memset(file_data, 0, file_length);
    lines = read_from_file(&file_data, file, file_length);
    printf("\n\nfinal is : %s", file_data);

    // sub the short and the long numbers and count the same numbers have
    count_tel_nums(file_data, lines);

    // close file and make the point NULL
    free(file_data);
    file_data = NULL;
    close_file(&file);
    return 0;
}


int main(void)
{
    mission_workflow_1002();
    return 0;
}
