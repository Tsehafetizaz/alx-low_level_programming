#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/*
* Displays the information contained in ELF header of the provided ELF file.
* Parameters:
* - elf_filename: Name of the ELF file.
* Return:
* - Displays the ELF header information and exits with status 0 if successful.
* - Exits with status code 98 and prints an error message if unsuccessful.
*/
int main(int argc, char *argv[])
{
int fd;
ssize_t read_size;
Elf64_Ehdr header;

if (argc != 2)
{
dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
exit(98);
}

fd = open(argv[1], O_RDONLY);
if (fd == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
exit(98);
}

read_size = read(fd, &header, sizeof(header));
if (read_size != sizeof(header)
|| header.e_ident[EI_MAG0] != ELFMAG0
|| header.e_ident[EI_MAG1] != ELFMAG1
|| header.e_ident[EI_MAG2] != ELFMAG2
|| header.e_ident[EI_MAG3] != ELFMAG3)
{
dprintf(STDERR_FILENO, "%s is not an ELF file\n", argv[1]);
close(fd);
exit(98);
}

printf("ELF Header:\n");
printf("  Magic:   %.2x %.2x %.2x %.2x %.2x %.2x %.2x %.2x "
"%.2x %.2x %.2x %.2x %.2x %.2x %.2x %.2x\n",
header.e_ident[EI_MAG0], header.e_ident[EI_MAG1],
header.e_ident[EI_MAG2], header.e_ident[EI_MAG3],
header.e_ident[EI_CLASS], header.e_ident[EI_DATA],
header.e_ident[EI_VERSION], header.e_ident[EI_OS...)
}
