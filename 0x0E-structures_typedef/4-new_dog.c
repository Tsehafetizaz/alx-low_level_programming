#include "dog.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* new_dog - creates a new dog structure
* @name: name of the dog
* @age: age of the dog
* @owner: owner of the dog
* Return: pointer to the new dog, or NULL if fails
*/
dog_t *new_dog(char *name, float age, char *owner)
{
dog_t *newDog;
char *newName, *newOwner;
int lenName, lenOwner, i;

newDog = malloc(sizeof(dog_t));
if (!newDog)
return (NULL);

lenName = strlen(name);
lenOwner = strlen(owner);

newName = malloc(lenName + 1);
if (!newName)
{
free(newDog);
return (NULL);
}

newOwner = malloc(lenOwner + 1);
if (!newOwner)
{
free(newName);
free(newDog);
return (NULL);
}

for (i = 0; i <= lenName; i++)
newName[i] = name[i];
for (i = 0; i <= lenOwner; i++)
newOwner[i] = owner[i];

newDog->name = newName;
newDog->age = age;
newDog->owner = newOwner;

return (newDog);
}

