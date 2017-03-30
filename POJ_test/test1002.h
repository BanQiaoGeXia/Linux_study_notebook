#ifndef TEST1002_H
#define TEST1002_H

FILE *open_file(const char *filename);

int close_file(FILE **file);

int get_file_size(const FILE *file);

int read_from_file(char **buff, FILE *file, int file_length);

int trans2num(char *buff, char **sub_str);

int count_tel_nums(char *buff, int lines);

#endif // TEST1002_H
