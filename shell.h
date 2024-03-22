#ifndef _SHELL_
#define _SHELL_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <limits.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

/* It points to an array of pointers to strings called the "environment" */
extern char **environ;

/**
 * struct data - a struct that contains all data relevant on runtime
 * @argv: The argument vector
 * @n: The command line written by the user
 * @args: tokens of the command line
 * @stat: last status of the shell
 * @result: lines counter
 * @env_var: environment variable
 * @pid: process ID of the shell
 */
typedef struct data
{
	char **argv;
	char *n;
	char **args;
	int stat;
	int result;
	char **envir_var;
	char *pid;
} data_shell;

/**
 * struct separ_list_s - single linked list
 * @m_separator: ; | &
 * @nextNode: next node
 * Description: single linked list to store separators
 */
typedef struct separ_list_s
{
	char m_separator;
	struct separ_list_s *nextNode;
} separ_list;

/**
 * struct line_lst_s - single linked list
 * @line_cmd: command line
 * @nextNode: next node
 * Description: single linked list to store command lines
 */
typedef struct line_lst_s
{
	char *line_cmd;
	struct line_lst_s *nextNode;
} line_lst;

/**
 * struct mili_variables - single linked list
 * @len_var: length of the variable
 * @val: value of the variable
 * @len_val: length of the value
 * @next: next node
 * Description: single linked list to store variables
 */
typedef struct mili_variables
{
	int var_length;
	char *var_value;
	int val_length;
	struct mili_variables *nextNode;
} mili_variables;

/**
 * struct builtin_s - Builtin struct for command args.
 * @cmd_name: The name of the command builtin i.e cd, exit, env
 * @f: data type pointer function.
 */
typedef struct builtin_s
{
	char *cmd_name;
	int (*mili_function)(data_shell *data_sh);
} builtin_t;

/* mili-get_help.c */
int _gethelp(data_shell *data_sh);

/* mili-cd_shell.c */
int change_dir_shell(data_shell *data_sh);

/* mili-get_builtin.c */
int (*_getbuiltin(char *parm))(data_shell *);

/* mili-shell_exit.c */
int _exitshell(data_shell *data_sh);

/* mili-error.c */
char *strgcat_cd(data_shell *data_sh, char *msg, char *error_msg, char *counter_str);
char *gen_cd_error(data_shell *data_sh);
char *gen_not_found_error(data_shell *data_sh);
char *gen_exit_shell_error(data_shell *data_sh);

/* mili-error1.c */
char *gen_env_error(data_shell *data_sh);
char *gen_path126_error(data_shell *data_sh);
char *error_syntax(char **args);
char *error_permission(char **args);

/* mili-get_error.c */
int _geterror(data_shell *data_sh, int error_val);

/* mili-cd.c */
void change_par_dir(data_shell *data_sh);
void change_dir(data_shell *data_sh);
void change_to_prev_dir(data_shell *data_sh);
void change_to_home_dir(data_shell *data_sh);

/* mili-cmd_exec.c */
int is_colon_cdir(char *curr_path, int *curr_index);
char *locates_command(char *cmd, char **envir);
int is_exec(data_shell *data_sh);
int check_cmd_error(char *ddir, data_shell *data_sh);
int exec_cmd(data_shell *data_sh);

/* mili-stdlib.c */
int brings_length(int num);
char *mili_itoa(int num);
int mili_atoi(char *str_input);

/* mili-check_syntax_error.c */
int counts_repetition_of_char(char *s, int index);
int finds_syntax_error(char *s, int index, char prev_char);
int finds_index_first_char(char *s, int *index);
void prints_found_syntax_error(data_shell *data_sh, char *s, int index, int error_msg_ctrl);
int finds_prints_syntax_error(data_shell *data_sh, char *s);

/* mili-get_sigint.c */
void handleCrtl_c(int sig_num);

/* mili-shell_Loop.c */
char *comment_remove(char *n);
void _shellloop(data_shell *data_sh);

/* mili-envir1.c */
int compare_envir_var_name(const char *envir_var_name, const char *nm);
char *get_envir_var(const char *envir_var_name, char **envir_var);
int prints_envir_var(data_shell *data_sh);

/* mili-envir2.c */
char *cp_information(char *nm, char *val);
void setEnv(char *nm, char *val, data_shell *data_sh);
int _setEnv(data_shell *data_sh);
int _unsetEnv(data_shell *data_sh);

/* mili-mem.c */
void mili_memcpy(void *dest_ptr, const void *src_ptr, unsigned int n);
void *mili_realloc(void *org_ptr, unsigned int ol_size, unsigned int nw_size);
char **mili_realloc_dp(char **org_ptr, unsigned int ol_size, unsigned int nw_size);

/* mili-strglen.c */
int _strglen(const char *strg);

/* mili-strgcat.c*/
char *_strgcat(char *dest, const char *src);

/* mili-strgcpy.c*/
char *_strgcpy(char *dest, char *src);

/* mili-strgdup.c*/
char *_strgdup(const char *strg);

/* mili-strgchr.c */
char *_strgchr(char *s, char c);

/* mili-strgspn.c */
int _strgspn(char *s, char *accept);

/* mili-strgcmp.c */
int _strgcmp(char *s1, char *s2);

/* mili-revstrg.c */
void revStrg(char *strg);

/* mili-string.c */
int _cmpChars(char strg[], const char *delim);
char *_strgtok(char strg[], const char *delim);

/* mili-is_digit.c */
int is_digit(const char *strg);

/* mili-help2.c */
void help_cmd (void);
void alias_help(void);
void cd_help(void);

/* mili-help1.c */
void helpEnv(void);
void helpSetenv(void);
void helpUnsetenv(void);
void genHelp(void);
void exitHelp(void);

/* milli-linked_lists.c */
separ_list *add_separ_list_end(separ_list **head_list, char separ);
void free_separ_list(separ_list **head_list);
line_lst *add_line_list_end(line_lst **head_list, char *line_cmd);
void free_line_lst(line_lst **head_list);

/* mili-linked_lists2.c */
mili_variables *add_var_end(mili_variables **head_list, int varlen, char *varval, int vallen);
void free_var_list(mili_variables **head_list);

/* mili-get_line.c */
void assigns_line(char **line_ptr, size_t *size_ptr, char *input_s, size_t s_size);
ssize_t getline_fn(char **line_ptr, size_t *size_ptr, FILE *input_strm);

/* mili-read_input.c */
char *read_input(int *result);

/* mili-rep_var.c */
void check_envir_var(mili_variables **hd, char *n, data_shell *data_sh);
int check_variables(mili_variables **hd, char *n, char *stat, data_shell *data_sh);
char *rep_input(mili_variables **hd, char *n, char *new_inp, int new_len);
char *rep_variables(char *n, data_shell *data_sh);

/* mili-split.c */
char *swap_characters(char *n, int shld_swap);
void add_sep_commands(separ_list **head_s, line_lst **head_l, char *n);
void next_cmd_line(separ_list **head_s, line_lst **head_l, data_shell *data_sh);
char **split_string(char *n);
int split_cmds(data_shell *data_sh, char *n);

/* mili-exec_line */
int _execline(data_shell *data_sh);

#endif

