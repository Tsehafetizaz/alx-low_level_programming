#include "main.h"

#define BUFFER_SIZE 1024

int open_files(char **argv);
void close_files(int from_fd, int to_fd);
void copy_content(int from_fd, int to_fd);

/**
 * main - Entry point.
 * @argc: Number of arguments.
 * @argv: Argument values.
 * Return: 0 on success, other values on failure.
 */
int main(int argc, char **argv)
{
int from_fd, to_fd;

if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}

from_fd = open_files(argv);
to_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

if (to_fd == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
exit(99);
}

copy_content(from_fd, to_fd);
close_files(from_fd, to_fd);

return (0);
}

/**
 * open_files - Opens the source file.
 * @argv: Argument values.
 * Return: File descriptor of the source file.
 */
int open_files(char **argv)
{
int from_fd = open(argv[1], O_RDONLY);

if (from_fd == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
exit(98);
}

return (from_fd);
}

/**
 * copy_content - Copies content from source to destination file.
 * @from_fd: Source file descriptor.
 * @to_fd: Destination file descriptor.
 */
void copy_content(int from_fd, int to_fd)
{
int r, w;
char buffer[BUFFER_SIZE];

while ((r = read(from_fd, buffer, BUFFER_SIZE)) > 0)
{
w = write(to_fd, buffer, r);
if (w != r)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
exit(99);
}
}

if (r == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
exit(98);
}
}

/**
 * close_files - Closes the source and destination files.
 * @from_fd: Source file descriptor.
 * @to_fd: Destination file descriptor.
 */
void close_files(int from_fd, int to_fd)
{
if (close(from_fd) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", from_fd);
exit(100);
}

if (close(to_fd) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", to_fd);
exit(100);
}
}
