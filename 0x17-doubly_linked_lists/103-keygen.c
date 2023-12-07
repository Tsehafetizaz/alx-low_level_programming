#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * generate_key - Generates a valid key for a given username
 * @username: The username for which to generate the key
 * 
 * Return: The generated key
 */
char* generate_key(const char* username)
{

	char* key = malloc(strlen(username) + 1);
	if (key == NULL)
       	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	strcpy(key, username);
	return (key);
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <username>\n", argv[0]);
		return (EXIT_FAILURE);
	}

	char* username = argv[1];
	char* key = generate_key(username);

	printf("Key for %s: %s\n", username, key);

	free(key);
	return (EXIT_SUCCESS);
}
