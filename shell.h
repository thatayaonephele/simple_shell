#ifndef _SHELL_H_
#define _SHELL_H_

#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024
#define BUF_FLUSH -1
#define NORM_CMD 0
#define OR_CMD 1
#define AND_CMD 2
#define CHAIN_CMD 3
#define FILE_HIST ".siple_shell_history"
#define DATA_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL,\
0, 0, 0}

extern char **environ;
int hshloop(char **);
/**
 * struct str_link - Structure to represent a linked list
 * @s: Pointer to a character string
 * @n: Integer value associated with the string
 *
 * @next: Pointer to the next node in the linked list
 */
typedef struct str_link
{
	char *s;
	int n;
	struct str_link *next;
} stringnode_t;

/**
 *struct data_parse - A structure storing permitted constant prototype
 *pseudo args for function pointer structure to be parsed into a function
 *@arg: A Getline function housing args that creates a string
 *@argc: A counter index for the arguments
 *@argv: Args containining an array of strings
 *@r_fd: The read line input file description
 *@cmd_path: A string path for the current command
 *@exec_cmd_status: The last return status of executed command
 *@buff_cmd_type: ||, CMD_type, &&, ;
 *@node_his: The node history of the singly linked list
 *@h_counter: The number count for the history line
 *@file_name: The filename of the program
 *@line_cnt: A function that counts the number of errors
 *@flag_line_cnt: Counts the number of lines based on a bool outcome
 *@number_error: The exit()s error code
 *@_env: A local duplicate of environ linked list
 *@environ: The env linked list custom-made duplicate of environ
 *@changed_env: Handles the environ changes
 *@my_alias: The node of the linked list representing the alias
 *@chain_buff_cmd: A pointer to the cmd buffer address if chaining exits
 */

typedef struct data_parse
{
	char *arg;
	char **argv;
	char *cmd_path;
	int argc;
	unsigned int line_cnt;
	int number_error;
	int flag_line_cnt;
	char *file_name;
	stringnode_t *_env;
	stringnode_t *node_his;
	stringnode_t *my_alias;
	char **environ;
	int changed_env;
	int exec_cmd_status;
	char **chain_buff_cmd;
	int buff_cmd_type;
	int r_fd;
	int h_counter;
} data_t;
/**
 *struct built_in - Struct storing builtin string together with related funcs
 *@cmd_flag: The command flag that forms part of the builtin attributes
 *@func: The function
 */
typedef struct built_in
{
	char *cmd_flag;
	int (*func)(data_t *);
} table_builtin;
/**print_errors.c*/
int fd_put(char, int);
int fd_puts(char *, int);
int _error_putchar(char);
void _error_puts(char *);
void display_err(data_t *, char *);
/**interactive.c*/
int int_sh(data_t *);
int delim_check(char, char *);
int my_atoi(char *);
/*node.c*/
ssize_t find_index_node(stringnode_t *, stringnode_t *);
stringnode_t *node_starts_with(stringnode_t *, char *, char);
stringnode_t *add_node(stringnode_t **node_h, char *s, int n);
stringnode_t *app_node_end(stringnode_t **, const char *, int);
int delete_node_at_index(stringnode_t **, unsigned int);
/**string_handling.c*/
int lexi_cmp(char *, char *);
char *cpy_str(char *, char *);
char *cat_str(char *, char *);
char *hay_start(const char *, const char *);
/**print_strings.c*/
int _putchar(char);
void my_puts(char *);
char *dup_str(const char *);
/**error_handling.c*/
char *num_converter(long int, int, int);
int _myhelp(data_t *);
int atoi_err(char *);
void comment_remover(char *);
int print_decimal(int, int);

/**list_handling.c*/
size_t get_list_len(const stringnode_t *);
char **list_to_str(stringnode_t *);
size_t display_str_element(const stringnode_t *);
void free_mem(stringnode_t **);
size_t display_list(const stringnode_t *);

/**memory_handling.c*/
void *mem_realloc(void *, unsigned int, unsigned int);
int free_vars(void **);
char *set_mem(char *, char, unsigned int);
void str_free(char **);

/**token_handling.c*/
char **str_token(char *, char *);

/**shell_line_handling.c*/
ssize_t buff_read(data_t *, char *, size_t *);
void block_ctrl_c(__attribute__((unused))int);
int getLine(data_t *, char **, size_t *);

/**list_handling.c*/
size_t get_list_len(const stringnode_t *);
char **list_to_str(stringnode_t *);
void print_str_array(char **);
size_t display_list(const stringnode_t *);

/**list_handling_helper.c*/
void free_str_array(char **);

/**data.c*/
void data_clear(data_t *);
void free_data(data_t *, int);
void data_set(data_t *, char **);

/**environ_handling.c*/
int current_env(data_t *);
char *est_env_val(data_t *, const char *);
int unset_my_env(data_t *);
int append_env_list(data_t *);
int set_my_env(data_t *);

/**parse_shell.c*/
int is_file_cmd_exe(data_t *, char *);
char *char_dup(char *, int, int);
char *cmd_path_find(data_t *, char *, char *);
ssize_t get_input(data_t *);

/**simpleshell.c*/
void process_command(const char *);
ssize_t read_command(char *, size_t);
void display_prompt(void);

/**exit_shell.c*/
char *_str_chr(char *, char);
char *_str_ncat(char *, char *, int);
char *_str_ncpy(char *, char *, int);

/**built1_in.c*/
int _change_dir(data_t *);
int current_cd(data_t *);
int my_his_list(data_t *);
int _exit_shell(data_t *);
int mimic_alias(data_t *);

/**var_handling.c*/
int curr_char_buff(data_t *, char *, size_t *);
void check_chain(data_t *, char *, size_t *, size_t, size_t);
int str_sub(char **, char *);
int var_sub(data_t *);
int alias_sub(data_t *);

/**shell_history.c*/
int index_his(data_t *);
int w_his(data_t *);
int list_his(data_t *d, char *, int);
char *get_history_file(data_t *);
int r_his(data_t *);

/**env.c*/
char **find_env(data_t *);
int del_env(data_t *, char *);
char **find_env(data_t *);
int add_env(data_t *, char *, char *);

/**alias.c*/
int display_alias(stringnode_t *);
int add_alias(data_t *, char *);
int del_alias(data_t *, char *);

/**loop_shell.c*/
void get_cmd(data_t *);
void cmd_fork(data_t *);
int get_built_in(data_t *);
ssize_t buf_input(data_t *, char **, size_t *);

/*strings.c*/
int alph_check(int);
/*strings2.c*/
int str_len(char *);

int hsh(data_t *, char **);
#endif
