#include "main.h"
#define BUF_SIZE 1024

/**
 * check_argc - Checks for correct argument count.
 * @argc: Argument count.
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
 * error_check - Checks and handles errors.
 * @chk: Error check condition.
 * @file: File related to the error.
 * @fd: File descriptor.
 */
void error_check(int chk, char *file, int fd)
{
if (chk)
{
if (!file)
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
else if (fd == -1)
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
else
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
exit(fd == -1 ? 98 : 99);
}
}

/**
 * main - Main function, copies a file.
 * @argc: Argument count.
 * @argv: Argument values.
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
int from, to, r, w;
char buffer[BUF_SIZE];
check_argc(argc);
from = open(argv[1], O_RDONLY);
error_check(from == -1, argv[1], from);
to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
error_check(to == -1, argv[2], to);
while ((r = read(from, buffer, BUF_SIZE)) > 0)
{
w = write(to, buffer, r);
error_check(w != r, argv[2], to);
}
error_check(r == -1, argv[1], from);
error_check(close(from) == -1, NULL, from);
error_check(close(to) == -1, NULL, to);
return (0);
}
