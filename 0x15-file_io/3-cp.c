#include "main.h"

/**
 * close_file - closes a file descriptor
 * @fd: file descriptor to be closed
 */
void close_file(int fd)
{
	if (close(fd) < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * copy_file - copies the content of a file to another file
 * @file_from: file descriptor of the source file
 * @file_to: file descriptor of the destination file
 * @argv: argument vector
 */
void copy_file(int file_from, int file_to, char *argv[])
{
	int r, w;
	char buffer[1024];

	while ((r = read(file_from, buffer, 1024)) > 0)
	{
		w = write(file_to, buffer, r);
		if (w != r || w == -1)
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
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int file_from, file_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
		exit(97);
	}

	file_from = open(argv[1], O_RDONLY);
	if (file_from < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (file_to < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close_file(file_from);
		exit(99);
	}

	copy_file(file_from, file_to, argv);
	close_file(file_from);
	close_file(file_to);
	return (0);
}
