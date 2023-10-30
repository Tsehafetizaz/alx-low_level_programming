#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

/**
 * close_file - Close a file descriptor
 * @fd: File descriptor to close
 */
void close_file(int fd)
{
	if (close(fd) < 0)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd), exit(100);
}

/**
 * copy_content - Copy content from one file to another
 * @from_fd: File descriptor for the source file
 * @to_fd: File descriptor for the destination file
 */
void copy_content(int from_fd, int to_fd)
{
	char buffer[BUFFER_SIZE];
	ssize_t rd, wr;

	while (1)
	{
		rd = read(from_fd, buffer, BUFFER_SIZE);
		if (rd == -1)
			dprintf(STDERR_FILENO, "Error: Can't read from file\n"), exit(98);
		if (rd == 0)
			break;
		wr = write(to_fd, buffer, rd);
		if (wr == -1)
			dprintf(STDERR_FILENO, "Error: Can't write to file\n"), exit(99);
	}
}

/**
 * main - Entry point, the program starts executing here
 * @argc: The number of command line arguments
 * @argv: Array of pointers to the command line arguments
 * Return: 0 on success, exit code on failure
 */
int main(int argc, char *argv[])
{
	int from_fd, to_fd;
	mode_t file_perm;

	if (argc != 3)
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97);
	from_fd = open(argv[1], O_RDONLY);
	if (from_fd < 0)
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]), exit(98);
	file_perm = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	to_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, file_perm);
	if (to_fd < 0)
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]),
close_file(from_fd), exit(99);
	copy_content(from_fd, to_fd);
	close_file(from_fd);
	close_file(to_fd);
	return (0);
}
