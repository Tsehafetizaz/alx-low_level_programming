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
if (!chk)
return;
if (!file)
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd), exit(100);
if (fd == -1)
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file), exit(98);
else
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file), exit(99);
}

/**
 * read_and_write - reads from a file and writes to another.
 * @from: file descriptor to read from.
 * @to: file descriptor to write to.
 * @file_from: Source file name.
 * @file_to: Destination file name.
 */
void read_and_write(int from, int to, char *file_from, char *file_to)
{
int r, w;
char buffer[BUF_SIZE];
while ((r = read(from, buffer, BUF_SIZE)) > 0)
{
w = write(to, buffer, r);
if (w != r)
error_check(1, file_to, to);
}
if (r == -1)
error_check(1, file_from, from);
}

/**
 * main - Main function, copies a file.
 * @argc: Argument count.
 * @argv: Argument values.
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
int from, to;
check_argc(argc);
from = open(argv[1], O_RDONLY);
error_check(from == -1, argv[1], from);
to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
error_check(to == -1, argv[2], to);
read_and_write(from, to, argv[1], argv[2]);
error_check(close(from) == -1, NULL, from);
error_check(close(to) == -1, NULL, to);
return (0);
}

