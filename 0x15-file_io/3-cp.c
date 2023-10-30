#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

/* Defining the buffer size for read and write operations */
#define BUFFER_SIZE 1024

/**
 *  * Function to handle errors and exit the program
 *   * @param message The error message to be printed
 *    * @param filename The file related to the error
 *     * @param exit_code The exit code for the program termination
 *      */
void error_exit(const char *message, const char *filename, int exit_code)
{
	    dprintf(STDERR_FILENO, message, filename);
	        exit(exit_code);
}

/**
 *  * Main function to copy content from one file to another
 *   * @param argc Number of command-line arguments
 *    * @param argv Array of command-line arguments
 *     * @return 0 on success, does not return on failure
 *      */
int main(int argc, char *argv[])
{
	/* Check if the number of arguments is correct */
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	/* Retrieve file names from command line arguments */
	const char *file_from = argv[1];
	const char *file_to = argv[2];

	/* Open the source file for reading */
	int fd_from = open(file_from, O_RDONLY);
	if (fd_from < 0)
	{
		error_exit("Error: Can't read from file %s\n", file_from, 98);
	}

	/* Open the destination file for writing; create it if it doesn't exist, truncate it if it does */
	int fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to < 0)
	{
		if (close(fd_from) < 0)
		{
			error_exit("Error: Can't close fd %d\n", file_from, 100);
		}
		error_exit("Error: Can't write to %s\n", file_to, 99);
	}

	/* Buffer to store the data temporarily */
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read, bytes_written;

	/* Read from the source file and write to the destination file */
	while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written < 0)
		{
			if (close(fd_from) < 0 || close(fd_to) < 0)
			{
				error_exit("Error: Can't close fd %d\n", file_from, 100);
			}
			error_exit("Error: Can't write to %s\n", file_to, 99);
		}
	}

	/* Check for read errors */
	if (bytes_read < 0)
	{
		if (close(fd_from) < 0 || close(fd_to) < 0)
		{
			error_exit("Error: Can't close fd %d\n", file_from, 100);
		}
		error_exit("Error: Can't read from file %s\n", file_from, 98);
	}

	/* Close the file descriptors */
	if (close(fd_from) < 0 || close(fd_to) < 0)
	{
		error_exit("Error: Can't close fd %d\n", file_from, 100);
	}

	/* Return success */
	return (0);
}
