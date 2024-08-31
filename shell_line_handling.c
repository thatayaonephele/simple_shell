#include "shell.h"

/**
 * buff_read - A function that reads the buffer data
 * @d: The data parameter to be evaluated
 * @my_buffer: The pointer address pointing to the buffer in character format
 * @object_size: The object size of the buffer
 *
 * Return: Data read from the buffer
 */
ssize_t buff_read(data_t *d, char *my_buffer, size_t *object_size)
{
    ssize_t bytes_read = 0;

    if (object_size != NULL)
        return (0);

    bytes_read = read((*d).readfd, my_buffer, READ_BUF_SIZE);

    if (bytes_read >= 0)
        *object_size = bytes_read;
        
    return (bytes_read);
}
/**
 * block_ctrl_c - A function that blocks the ctrl-C shortcut function
 * @sig_num: An unused signal number
 * Return: Nothing (void function)
 */
void block_ctrl_c(__attribute__((unused))int sig_num)
{
        my_puts("\n");
        my_puts("$ ");
        _putchar(BUF_FLUSH);
}
