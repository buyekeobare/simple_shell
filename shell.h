#ifndef _SHELL_
#define _SHELL_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#include <erroh.h>
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
	char **env_var;
	char *pid;
} data_shell;

/**
 * struct sepLst - a single linked list
 * @separ: ; | &
 * @nxtNode: next node
 * Description: Single linked list to store separators
 */
typedef struct sepLst
{
	char separ;
	struct sepLst_s *nxtNode;
} sepLst;

/**
 * struct lineLst - a single linked list
 * @ln: The command line
 * @nxtNode: The next node
 * Description: Single linked list to store command lines
 */
typedef struct lineLst
{
	char *ln;
	struct lineLst_s *nxtNode;
} lineLst;

/**
 * struct rVar_list - a single linked list
 * @var_length: The length of the variable
 * @var_value: value of the variable
 * @val_length: length of the value
 * @nxtNode: next node
 * Description: The single linked list to store variables
 */
typedef struct rVar_list
{
	int var_length;
	char *var_value;
	int val_length;
	struct rVar_list *nxtNode;
} rVar;

/**
 * struct builtin - The builtin struct for command args.
 * @cmd_name: The name of the command builtin i.e cd, exit, env
 * @dpf: type data pointer function.
 */
typedef struct builtin
{
	char *cmd_name;
	int (*dpf)(data_shell *data_sh);
} builtin_t;

/* milli-linked_lists.c */
sepLst *addSep_ndEnd(sepLst **hd, char sep);
void free_sepLst(sepLst **hd);
lineLst *addLine_ndEnd(lineLst **hd, char *ln);
void free_lineLst(lineLst **hd);

/* mili-linked_lists2.c */
rVar *add_rVar_node(rVar **hd, int varlen, char *varval, int vallen);
void free_rVar_list(rVar **hd);

/* mili-mem.c */
void mem_cpy(void *nwptr, const void *ptr, unsigned int n);
void *re_allocate(void *ptr, unsigned int ol_size, unsigned int nw_size);
char **re_allocatedp(char **ptr, unsigned int ol_size, unsigned int nw_size);

/* mili-string1.c */
int _strglen(const char *strg);
char *_strgcat(char *dest, const char *src);
char *_strgcpy(char *dest, char *src);
char *_strgdup(const char *strg);

/* mili-string2.c */
char *_strgchr(char *s, char c);
int _strgspn(char *s, char *accept);
int _strgcmp(char *s1, char *s2);
void revStrg(char *strg);

/* mili-string3.c */
int _cmpChars(char strg[], const char *delim);
char *_strgtok(char strg[], const char *delim);
int is_digit(const char *strg);

/* mili-check_syntax_error.c */
int char_repeated(char *n, int i);
int err_sp_op(char *n, int i, char lst);
int frst_chr(char *n, int *i);
void prt_syntax_err(data_shell *data_sh, char *n, int i, int bool);
int chck_syntax_err(data_shell *data_sh, char *n);

/* mili-shell_Loop.c */
char *witht_comment(char *n);
void _shellloop(data_shell *data_sh);

/* mili-read_input.c */
char *read_input(int *result);

/* mili-split.c */
char *swap_characters(char *n, int bool);
void add_sep_commands(sepLst **sep_head, lineLst **cmd_hed, char *n);
void nxt_cmd_line(sepLst **sep_list, lineLst **cmd_list, data_shell *data_sh);
char **split_string(char *n);
int split_cmds(data_shell *data_sh, char *n);

/* mili-rep_var.c */
void check_environ(rVar **hd, char *n, data_shell *data_sh);
int check_variables(rVar **hd, char *n, char *stat, data_shell *data_sh);
char *rep_input(rVar **hd, char *n, char *new_inp, int new_len);
char *rep_variables(char *n, data_shell *data_sh);

/* mili-get_line.c */
void bringLine(char **lineptr, size_t *n, char *buffer, size_t j);
ssize_t getLine(char **lineptr, size_t *n, FILE *stream);

/* mili-exec_line */
int _execline(data_shell *data_sh);

/* mili-cmd_exec.c */
int is_cd(char *path, int *i);
char *which(char *cmd, char **envir);
int is_exec(data_shell *data_sh);
int check_err_cmd(char *ddir, data_shell *data_sh);
int cmd_executable(data_shell *data_sh)

/* mili-envir1.c */
int cmp_envir_nm(const char *nenvir, const char *nm);
char *get_envir(const char *nenvir, char **env_var);
int envir(data_shell *data_sh);

/* mili-envir2.c */
char *cpy_info(char *nm, char *val);
void setEnv(char *nm, char *val, data_shell *data_sh);
int _setEnv(data_shell *data_sh);
int _unsetEnv(data_shell *data_sh);

/* mili-cd.c */
void cdDot(data_shell *data_sh);
void cdTo(data_shell *data_sh);
void cdPrev(data_shell *data_sh);
void cdToHome(data_shell *data_sh)

/* mili-cd_shell.c */
int cdir_shell(data_shell *data_sh);

/* mili-get_builtin.c */
int (*_getbuiltin(char *cmd))(data_shell *)

/* mili-exit_shell.c */
int _exitshell(data_shell *data_sh)

/* mili-stdlib.c */
int getLength(int num);
char *mili_itoa(int num);
int mili_atoi(char *s);

/* mili-error.c */
char *strgcat_cd(data_shell *data_sh, char *msg, char *err_msg, char *vrs_str);
char *errGet_cd(data_shell *data_sh);
char *errNot_found(data_shell *data_sh);
char *errExit_shell(data_shell *data_sh);

/* mili-error1.c */
char *errEnv(data_shell *data_sh);
char *errPath_126(data_shell *data_sh);
char *error_syntax(char **args);
char *error_permission(char **args);

/* mili-get_error.c */
int get_err(data_shell *data_sh, int err_val);

/* mili-get_signal.c */
void handleCrtl_c(int sig_num);

/* mili-help1.c */
void helpEnv(void);
void helpSetenv(void);
void helpUnsetenv(void);
void genHelp(void);
void exitHelp(void);

/* mili-help2.c */
void help_cmd (void);
void alias_help(void);
void cd_help(void);

/* mili-get_help.c */
int _gethelp(data_shell *data_sh);

#endif
