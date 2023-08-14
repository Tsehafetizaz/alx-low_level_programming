#include "dog.h"
#include <stdlib.h>

/**
* _strlen - returns the length of a string
* @s: the string to check
*
* Return: the length of the string
*/
int _strlen(char *s)
{
int len = 0;
while (*s++)
len++;
return (len);
}

/**
* new_dog - creates a new dog
* @name: name of the dog
* @age: age of the dog
* @owner: owner of the dog
*
* Return: pointer to the new dog
*/
dog_t *new_dog(char *name, float age, char *owner)
{
dog_t *dog;
char *copy_name, *copy_owner;
int len1, len2;

dog = malloc(sizeof(dog_t));
if (!dog)
return (NULL);

len1 = _strlen(name);
copy_name = malloc(len1 + 1);
if (!copy_name)
{
free(dog);
return (NULL);
}
for (int i = 0; i < len1; i++)
copy_name[i] = name[i];
copy_name[len1] = '\0';

len2 = _strlen(owner);
copy_owner = malloc(len2 + 1);
if (!copy_owner)
{
free(copy_name);
free(dog);
return (NULL);
}
for (int i = 0; i < len2; i++)
copy_owner[i] = owner[i];
copy_owner[len2] = '\0';

dog->name = copy_name;
dog->age = age;
dog->owner = copy_owner;

return (dog);
}
