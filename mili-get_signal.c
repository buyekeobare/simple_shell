#include "shell.h"

/**
 * handleCrtl_c - a function that handles 
 * the crtl + c call in prompt
 * @sig_num: The signal handler
 */
void handleCrtl_c(int sig_num)
{
	(void)sig_num;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}