#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int _putchar(char c);
int open_files(char **argv);
void copy_content(int from_fd, int to_fd);
void error_check(int chk, char *file, int fd);
int main(int argc, char *argv[]);
int read_and_write(int from_fd, int to_fd);
void check_argc(int argc);
int open_file_from(char *file);
int open_file_to(char *file);
void close_files(int fd_from, int fd_to);
#endif /* MAIN_H */

