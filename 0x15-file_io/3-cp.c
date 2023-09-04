#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUF_SIZE 1024

/**
 * check_argc - Check if the number of arguments is correct.
 * @argc: Number of arguments
 */
void check_argc(int argc)
{
if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}
}

/**
 * open_file_from - Open the source file and return its file descriptor.
 * @file: Name of the source file.
 * Return: file descriptor of opened file.
 */
int open_file_from(char *file)
{
int fd = open(file, O_RDONLY);
if (fd < 0)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
exit(98);
}
return (fd);
}

/**
 * open_file_to - Open/create the destination file.
 * @file: Name of the destination file.
 * Return: file descriptor of opened/created file.
 */
int open_file_to(char *file)
{
int fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0664);
if (fd < 0)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
exit(99);
}
return (fd);
}

/**
 * close_files - Close the files and handle potential errors.
 * @fd_from: file descriptor of source file.
 * @fd_to: file descriptor of destination file.
 */
void close_files(int fd_from, int fd_to)
{
if (close(fd_from) < 0)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
exit(100);
}
if (close(fd_to) < 0)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
exit(100);
}
}

/**
 * main - Entry point. Copies content of one file to another file.
 * @argc: Number of arguments
 * @argv: Arguments array
 * Return: 0 on success, error code on failure.
 */
int main(int argc, char *argv[])
{
int fd_from, fd_to, read_bytes, write_bytes;
char buffer[BUF_SIZE];

check_argc(argc);
fd_from = open_file_from(argv[1]);
fd_to = open_file_to(argv[2]);

while ((read_bytes = read(fd_from, buffer, BUF_SIZE)) > 0)
{
write_bytes = write(fd_to, buffer, read_bytes);
if (write_bytes != read_bytes)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
close_files(fd_from, fd_to);
exit(99);
}
}
if (read_bytes < 0)
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);

close_files(fd_from, fd_to);
return (0);
}
