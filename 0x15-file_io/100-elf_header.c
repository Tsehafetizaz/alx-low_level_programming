nclude <stdio.h>
#include <stdlib.h>
#include <elf.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * print_magic - Prints the magic numbers of an ELF header.
 * @e_ident: The ELF header identifier.
 */
void print_magic(unsigned char *e_ident)
{
	printf("Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", e_ident[i]);
	}
	printf("\n");
}

/**
 * print_class - Prints the class of an ELF file.
 * @e_ident: The ELF header identifier.
 */
void print_class(unsigned char *e_ident)
{
	printf("Class:                             ");
	switch (e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_data - Prints the data encoding of an ELF file.
 * @e_ident: The ELF header identifier.
 */
void print_data(unsigned char *e_ident)
{
	printf("Data:                              ");
	switch (e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_DATA]);
	}
}

/**
 * print_version - Prints the version of an ELF file.
 * @e_ident: The ELF header identifier.
 */
void print_version(unsigned char *e_ident)
{
	printf("Version:                           ");
	switch (e_ident[EI_VERSION])
	{
		case EV_NONE:
			printf("0 (invalid)\n");
			break;
		case EV_CURRENT:
			printf("1 (current)\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_VERSION]);
	}
}

/**
 * print_os_abi - Prints the OS/ABI of an ELF file.
 * @e_ident: The ELF header identifier.
 */
void print_os_abi(unsigned char *e_ident)
{
	printf("OS/ABI:                            ");
	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * print_abi_version - Prints the ABI version of an ELF file.
 * @e_ident: The ELF header identifier.
 */
void print_abi_version(unsigned char *e_ident)
{
	printf("ABI Version:                       %d\n", e_ident[EI_ABIVERSION]);
}

/**
 * print_type - Prints the type of an ELF file.
 * @e_type: The ELF header type.
 * @e_ident: The ELF header identifier.
 */
void print_type(uint16_t e_type, unsigned char *e_ident)
{
	printf("Type:                              ");
	switch (e_type)
	{
		case ET_NONE:
			printf("NONE (None)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		default:
			printf("<unknown: %x>\n", e_type);
	}
}

/**
 * print_entry - Prints the entry point address of an ELF file.
 * @e_entry: The ELF header entry point address.
 * @e_ident: The ELF header identifier.
 */
void print_entry(uint64_t e_entry, unsigned char *e_ident)
{
	printf("Entry point address:               ");
	if (e_ident[EI_CLASS] == ELFCLASS32)
	{
		printf("0x%x\n", (uint32_t)e_entry);
	}
	else if (e_ident[EI_CLASS] == ELFCLASS64)
	{
		printf("0x%lx\n", e_entry);
	}
	else
	{
		printf("Invalid class\n");
	}
}

/**
 * main - Entry point of the program.
 * @argc: Argument count.
 * @argv: Argument vector.
 * Return: Exit status.
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		return (98);
	}

	int fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (98);
	}

	Elf64_Ehdr header;
	if (read(fd, &header, sizeof(header)) != sizeof(header))
	{
		fprintf(stderr, "Error reading ELF header\n");
		close(fd);
		return (98);
	}

	if (header.e_ident[EI_MAG0] != ELFMAG0 ||
			header.e_ident[EI_MAG1] != ELFMAG1 ||
			header.e_ident[EI_MAG2] != ELFMAG2 ||
			header.e_ident[EI_MAG3] != ELFMAG3)
	{
		fprintf(stderr, "Error: Not an ELF file\n");
		close(fd);
		return (98);
	}

	print_magic(header.e_ident);
	print_class(header.e_ident);
	print_data(header.e_ident);
	print_version(header.e_ident);
	print_os_abi(header.e_ident);
	print_abi_version(header.e_ident);
	print_type(header.e_type, header.e_ident);
	print_entry(header.e_entry, header.e_ident);

	close(fd);
	return (0);
}
