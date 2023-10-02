#include "main.h"
#include <fcntl.h>
#include <unistd.h>

/**
 * Check if the specified file is an ELF file.
 * This function determines if the file has the ELF
 * (Executable and Linkable Format) signature.
 * @param filename Name of the file to check.
 * @return 1 if ELF, otherwise 0.
 */
int is_elf(const char *filename)
{
int fd;
char buffer[4];

fd = open(filename, O_RDONLY);
if (fd == -1)
return (0);

if (read(fd, buffer, 4) != 4)
{
close(fd);
return (0);
}

close(fd);

if (buffer[0] == 0x7f && buffer[1] == 'E' && buffer[2] == 'L' && buffer[3] == 'F')
return (1);

return (0);
}
