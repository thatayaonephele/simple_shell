#include "shell.h"

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS
 */

int main(void)
{
	char command[BUFFER_SIZE];
	pid_t child_pid;
	int status;

	while (1)
	{
		write(STDOUT_FILENO, "simple_shell$", 14);/*Displays prompt*/

		if (read(STDIN_FILENO, command, BUFFER_SIZE) == -1)
		{
			write(STDOUT_FILE, "\n", 1);
			break; /*handle "end of file" condition*/
		}
		command[strcspn(command, "\n")] = '\0'; /*remove trailing newline character*/

		child_pid = fork(); /*create a child processs*/

		if (child_pid < 0)
		{
			perreor("fork");
			_exit(EXIT_failure);
		}
		else if
			(child_pid == 0)
			{
				/*child process*/
				if (execlp(command, command, NULL) == -1)
				{
					write(STDOUT_FILENO, "command not found: ", 19);
					write(STDOUT_FILENO, command, strlen(command));
					write(STDOUT_FILENO, "\n", 1);
					_exit(EXIT_FAILURE);
				}
			}
		else
		{/*parent processs*/
			waitpid(child_pid, &status, 0); /*wait for the child process to complete*/
		}
	}
	return (EXIT_SUCCESS);
}
