#include "main.h"

/**
* open_files - Open source and dest files.
* @source: Name of the source file.
* @dest: Name of the destination file.
* Return: Tuple with the file descriptors of source and destination.
*/
int *open_files(char *source, char *dest)
{
static int fd[2];

fd[0] = open(source, O_RDONLY);
if (fd[0] == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from %s\n", source);
exit(98);
}

fd[1] = open(dest, O_CREAT | O_WRONLY | O_TRUNC, 0664);
if (fd[1] == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", dest);
exit(99);
}

return (fd);
}

/**
* copy_contents - Handles reading and writing between files.
* @file_from: File descriptor for source file.
* @file_to: File descriptor for destination file.
*/
void copy_contents(int file_from, int file_to)
{
ssize_t read_count, write_count;
char buffer[1024];

do {
read_count = read(file_from, buffer, 1024);
if (read_count > 0)
{
write_count = write(file_to, buffer, read_count);
if (write_count != read_count)
break;
}
} while (read_count > 0);

if (read_count == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read\n");
exit(98);
}

if (write_count != read_count)
{
dprintf(STDERR_FILENO, "Error: Can't write\n");
exit(99);
}
}

/**
* close_files - Closes files after operation.
* @file_from: File descriptor for source file.
* @file_to: File descriptor for destination file.
*/
void close_files(int file_from, int file_to)
{
if (close(file_from) == -1 || close(file_to) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n",
file_from == -1 ? file_from : file_to);
exit(100);
}
}

/**
* main - Entry point for file copy program.
* @argc: Argument count.
* @argv: Argument vector.
* Return: 0 on success, error code otherwise.
*/
int main(int argc, char *argv[])
{
int *fd;

if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}

fd = open_files(argv[1], argv[2]);
copy_contents(fd[0], fd[1]);
close_files(fd[0], fd[1]);

return (0);
}
