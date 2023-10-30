nclude <stdio.h>
#include <stdlib.h>
#include <elf.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void print_magic(unsigned char *e_ident)
{
	size_t i;
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", e_ident[i]);
	}
	printf("\n");
}

void print_info(Elf64_Ehdr *header, unsigned char *e_ident)
{
	printf("  Class:                             ELF%d\n", e_ident[EI_CLASS] == ELFCLASS32 ? 32 : 64);
	printf("  Data:                              2's complement, %s\n", e_ident[EI_DATA] == ELFDATA2LSB ? "little endian" : "big endian");
	printf("  Version:                           %d (current)\n", e_ident[EI_VERSION]);
	printf("  OS/ABI:                            UNIX - System V\n");
	printf("  ABI Version:                       %d\n", e_ident[EI_OSABI]);
	printf("  Type:                              %s\n", header->e_type == ET_EXEC ? "EXEC (Executable file)" : "UNKNOWN");
	printf("  Entry point address:               0x%lx\n", header->e_entry);
}

int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr header;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		return (98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (98);
	}

	if (read(fd, &header, sizeof(header)) != sizeof(header))
	{
		perror("Error reading ELF header");
		close(fd);
		return (98);
	}

	if (header.e_ident[EI_MAG0] != ELFMAG0 || header.e_ident[EI_MAG1] != ELFMAG1 || header.e_ident[EI_MAG2] != ELFMAG2 || header.e_ident[EI_MAG3] != ELFMAG3)
	{
		fprintf(stderr, "Error: Not an ELF file\n");
		close(fd);
		return (98);
	}

	print_magic(header.e_ident);
	print_info(&header, header.e_ident);

	close(fd);
	return (0);
}
