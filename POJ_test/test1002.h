#ifndef TEST1002_H
#define TEST1002_H

FILE *open_file(const char *filename);

int close_file(FILE **file);

int get_file_size(const FILE *file);

int read_from_file(char **buff, FILE *file);

#endif // TEST1002_H
