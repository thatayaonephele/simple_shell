#include "shell.h"

/**
 * buff_read - A function that reads the buffer data
 * @my_buffer: The pointer address pointing to the buffer in character format
 * @object_size: The object size of the buffer
 *
 * Return: Data read from the buffer
 */

ssize_t buff_read(char *my_buffer, size_t *object_size)
{
	ssize_t bytes_read;

	bytes_read = 0;

	if (my_buffer != NULL && object_size != NULL)
	{
		bytes_read = write(STDOUT_FILENO, my_buffer, *object_size);
	}
	return (bytes_read);
}
