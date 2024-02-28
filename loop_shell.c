#include "shell.h"
/**
 * cmd_fork - A function that executes a command by forking a running thread
 * @d: The variable address of the data structure parameter
 *
 * Return: Nothing (Void function)
 */
void cmd_fork(data_t *d)
{
	pid_t child_pid;
	int status;

	child_pid = fork();

	if (child_pid < 0)
	{
		perror("fork");
		_exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		if (d->cmd_path != NULL)
		{
			execvp(d->cmd_path, d->argv);
			perror("execvp");
		}
		else
		{
			write(STDOUT_FILENO, "command not found: ", 19);
			write(STDOUT_FILENO, d->argv[0], str_len(d->argv[0]));
			write(STDOUT_FILENO, "\n", 1);
			_exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
	}
}
/**
 * get_built_in - Search and retrieve a built-in command
 *@d: The parameter of the struct
 * Return: (-2) matches exit(), (-1) cmd not found,
 * (0) on success, (1) cmd found & no success
 */
int get_built_in(data_t *d)
{
	int ret_built_in = -1;
	int x = 0;
	table_builtin tbl_built_in[] = {
		{"exit", _exit_shell},
		{"env", my_his_list},
		{"help", _myhelp},
		{"history", my_his_list},
		{"setenv", set_my_env},
		{"unsetenv", unset_my_env},
		{"cd", _change_dir},
		{"alias", mimic_alias},
		{NULL, NULL}
	};
	for (; tbl_built_in[x].cmd_flag; x++)
		if (lexi_cmp(d->argv[0], tbl_built_in[x].cmd_flag) == 0)
		{
			d->line_cnt++;
			ret_built_in = tbl_built_in[x].func(d);
			break;
		}
	return (ret_built_in);
}
/**
 * hsh - A function that loops the main function of the shell
 * @d: The variable address of the data structure parameter
 * @av: The vector argument vector parameter
 * Return: 0 on success, 1 on error,else an approrpiate error code
 */

int hsh(data_t *d, char **av)
{
	int ret_built_in = 0;
	ssize_t x = 0;

	while (x != -1 && ret_built_in != -2)
	{
		data_clear(d);
		if (int_sh(d))
			my_puts("$ ");
		_error_putchar(BUF_FLUSH);
		x = get_input(d);
		if (x != -1)
		{
			data_set(d, av);
			ret_built_in = get_built_in(d);
			if (ret_built_in == -1)
				get_cmd(d);
		}
		else if (((!int_sh(d)) == false))
			_putchar('\n');
		free_data(d, 0);
	}
	w_his(d);
	free_data(d, 1);
	if (((int_sh(d) == false)) && ((!d->exec_cmd_status) == false))
		exit(d->exec_cmd_status);
	if (ret_built_in == -2)
	{
		if (d->number_error == -1)
			exit(d->exec_cmd_status);
		exit(d->number_error);
	}
	return (ret_built_in);
}
/**
 * get_cmd - A function that gets a command that's inside the PATH
 * @d: The variable address of the data structure parameter
 * Return: Nothing (Void Function)
 */

void get_cmd(data_t *d)
{
	int x = 0;
	int z;
	char *cmd_path = NULL;

	d->cmd_path  = d->argv[0];
	if (d->flag_line_cnt == 1)
	{
		d->line_cnt++;
		d->flag_line_cnt = 0;
	}
	for (x = 0, z = 0; d->arg[x]; x++)
	for (z = 0, x = 0; d->arg[x]; x++)
		if (!delim_check(d->arg[x], " \t\n"))
			z++;
	if ((z) == false)
		return;
	cmd_path  = cmd_path_find(d, est_env_val(d, "PATH="), d->argv[0]);
	if ((!cmd_path) == false)
	{
		d->cmd_path  = cmd_path;
		cmd_fork(d);
	}
	else
	{
		if (*(d->arg) != '\n')
		{
			d->exec_cmd_status = 127;
			display_err(d, "not found\n");
		}
		else if ((est_env_val(d, "PATH=") || d->argv[0][0] == '/'
					|| int_sh(d)) && is_file_cmd_exe(d, d->argv[0]))
			cmd_fork(d);
	}
}

/**
 *buf_input - A function that verifies if the commands are chained
 *@d:The variable address of the data structure parameter
 *@chr_buffer: The ptr pointing to the char buffer address
 *@size_length: The length of the pointer address
 *Return: The command's read bytes data
 */
ssize_t buf_input(data_t *d, char **chr_buffer, size_t *size_length)
{
	size_t ptr_length = 0;
	ssize_t x = 0;

	if (!*size_length)
	{
		free(*chr_buffer);
		*chr_buffer = NULL;
		signal(SIGINT, block_ctrl_c);
		x = getline(chr_buffer, &ptr_length, stdin);
		x = getLine(d, chr_buffer, &ptr_length);
		if (x > 0)
		{
			if ((*chr_buffer)[x - 1] == '\n')
			{
				(*chr_buffer)[x - 1] = '\0';
				x--;
			}
			d->flag_line_cnt = 1;
			comment_remover(*chr_buffer);
			list_his(d, *chr_buffer, d->h_counter++);
			{
			*size_length = x;
			d->chain_buff_cmd = chr_buffer;
			}
		}
	}
	return (x);
}
