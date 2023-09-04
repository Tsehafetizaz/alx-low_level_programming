#include "main.h"

#define BUFFER_SIZE 1024

/**
 * read_and_write - Reads content from a source file descriptor
 * and writes it to a destination file descriptor.
 * @from_fd: File descriptor to read from.
 * @to_fd: File descriptor to write to.
 * Return: 0 on success, -1 on failure.
 */
int read_and_write(int from_fd, int to_fd)
{
int r, w;
char buffer[BUFFER_SIZE];
while ((r = read(from_fd, buffer, BUFFER_SIZE)) > 0)
{
w = write(to_fd, buffer, r);
if (w != r)
{
dprintf(STDERR_FILENO, "Error: Can't write to fd %d\n", to_fd);
return (-1);
}
}
if (r == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from fd %d\n", from_fd);
return (-1);
}
return (0);
}

/**
 * main - Copies the content of a file to another file.
 * @argc: The number of arguments passed to the program.
 * @argv: The argument vector.
 * Return: 0 if successful, or one of the error codes if an error occurs.
 */
int main(int argc, char *argv[])
{
int from_fd, to_fd;

/* Check for the correct number of arguments */
if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}

/* Open the source file */
from_fd = open(argv[1], O_RDONLY);
if (from_fd == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
exit(98);
}

/* Open the destination file with appropriate flags and permissions. */
to_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
if (to_fd == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
exit(99);
}

/* Call helper function */
if (read_and_write(from_fd, to_fd) == -1)
exit(98);
/* Close file descriptors and handle any errors. */
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
return (0);
}
