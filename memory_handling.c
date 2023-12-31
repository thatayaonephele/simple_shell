#include "shell.h"
/**
 * mem_realloc - a function that reallocates a memory block
 * @ptr: A pointer pointing to the old memory block
 * @old_size: Old memory block byte size
 * @new_size: New memory block byte size
 * Return: A pointer to the reallocated memory block,
 * or NULL if the reallocation fails
 */
void *mem_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	if (ptr != NULL && new_size == 0)
	{
		free(ptr); /*Deallocte the memory*/
		return (NULL);
	}
	if (ptr == NULL)
	{
		ptr = malloc(new_size);
		if (!ptr) /*Test for malloc failuire*/
			return;
	}
	if (new_size == old_size) /*Test if mem blocks are the same*/
	{
		return (ptr);
	}
	free(ptr); /*Deallocate the memory*/
	ptr = malloc(new_size);
	if !(ptr) /*Test for mem alloc success*/
		return;
	return (ptr);
}
