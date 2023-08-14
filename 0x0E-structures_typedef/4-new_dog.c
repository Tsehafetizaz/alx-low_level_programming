#include "dog.h"
#include <stdlib.h>
#include <string.h>

/**
* new_dog - creates a new dog
* @name: name of the dog
* @age: age of the dog
* @owner: owner of the dog
* Return: pointer to the new dog
*/
dog_t *new_dog(char *name, float age, char *owner)
{
dog_t *dog;
char *copy_name, *copy_owner;

dog = malloc(sizeof(dog_t));
if (!dog)
return (NULL);

copy_name = name ? strdup(name) : NULL;
if (name && !copy_name)
{
free(dog);
return (NULL);
}

copy_owner = owner ? strdup(owner) : NULL;
if (owner && !copy_owner)
{
free(copy_name);
free(dog);
return (NULL);
}

dog->name = copy_name;
dog->age = age;
dog->owner = copy_owner;

return (dog);
}
