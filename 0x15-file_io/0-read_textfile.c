nclude "main.h"

/**
 * read_textfile - reads a text file and prints it to the standard output
 * @filename: name of the file to read
 * @letters: number of letters it should read and print
 * Return: actual number of letters it could read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t len_read, len_written;
	char *buffer;

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (!buffer)
		return (0);

	len_read = read(fd, buffer, letters);
	close(fd);
	if (len_read == -1)
	{
		free(buffer);
		return (0);
	}

	len_written = write(STDOUT_FILENO, buffer, len_read);
	free(buffer);
	if (len_written != len_read)
		return (0);

	return (len_written);
}
