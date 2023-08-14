#include "dog.h"
#include <stdlib.h>

/**
* new_dog - creates a new dog
* @name: name of the dog
* @age: age of the dog
* @owner: owner of the dog
* Return: pointer to the new dog, or NULL if fails
*/
dog_t *new_dog(char *name, float age, char *owner)
{
dog_t *newdog;
char *name_copy, *owner_copy;

newdog = malloc(sizeof(dog_t));
if (!newdog)
return (NULL);

if (name)
{
for (name_copy = name; *name_copy; name_copy++)
;
name_copy = malloc(name_copy - name + 1);
if (!name_copy)
{
free(newdog);
return (NULL);
}
for (name_copy = name; *name_copy; name_copy++, name++)
*name_copy = *name;
}
else
name_copy = NULL;

if (owner)
{
for (owner_copy = owner; *owner_copy; owner_copy++)
;
owner_copy = malloc(owner_copy - owner + 1);
if (!owner_copy)
{
free(name_copy);
free(newdog);
return (NULL);
}
for (owner_copy = owner; *owner_copy; owner_copy++, owner++)
*owner_copy = *owner;
}
else
owner_copy = NULL;

newdog->name = name_copy;
newdog->age = age;
newdog->owner = owner_copy;

return (newdog);
}
