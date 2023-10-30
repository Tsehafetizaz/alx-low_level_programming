#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "elfheader.h"

/**
 * print_magic - Print the magic numbers of the ELF header
 * @e_ident: Pointer to an array of unsigned chars (magic numbers)
 */
void print_magic(unsigned char *e_ident)
{
	int i;  /* Loop counter */

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", e_ident[i]);
	}
	printf("\n");
}

/**
 * main - Entry point, opens an ELF file and prints its magic numbers
 * @argc: Number of command line arguments
 * @argv: Array of command line arguments
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
	int fd;  /* File descriptor for the ELF file */
	Elf64_Ehdr ehdr;  /* ELF header structure */

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <ELF file>\n", argv[0]);
		return (1);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}

	if (read(fd, &ehdr, sizeof(ehdr)) != sizeof(ehdr))
	{
		perror("Error reading ELF header");
		close(fd);
		return (1);
	}

	if (memcmp(ehdr.e_ident, ELFMAG, (size_t)SELFMAG) != 0)
	{
		fprintf(stderr, "Not an ELF file\n");
		close(fd);
		return (1);
	}

	print_magic(ehdr.e_ident);

	close(fd);
	return (0);
}
