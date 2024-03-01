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
	if (!(ptr)) /*Test for mem alloc success*/
		return;
	return (ptr);
}
/**
 * free_vars - Nullify variable address and free the pointer variable
 * @p: The pointer address pointing to a pointer variable to be freed
 *
 * Return: 1 if vars were successfully freed, else 0 on failure
 */

int free_vars(void **p)
{
	if (p != NULL && *p != NULL)
	{
		free(*p);
		*p = NULL;
		return (1);
	}
	return (0);
}
/**
 * set_mem - fills a block of memory with a given byte value
 * @str: The pointer to the memory block to be filled
 * @my_byte: The byte value to fill the memory block with
 * @fill_amount: The number of bytes to fill
 *
 * Return: Pointer to the filled memory block
 */

char *set_mem(char *str, char my_byte, unsigned int fill_amount)
{
	unsigned int i;

	if (str == NULL || fill_amount == 0)
		return (NULL);

	for (i = 0; i < fill_amount; i++)
	{
		str[i] = my_byte;
	}
	return (str);
}
