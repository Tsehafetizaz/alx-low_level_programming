#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_os_abi(unsigned char *e_ident);
void print_type(uint16_t e_type, unsigned char *e_ident);
void print_entry(uint64_t e_entry, unsigned char *e_ident);
int main(int argc, char **argv);
#endif /* MAIN_H */
