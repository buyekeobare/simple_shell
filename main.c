// main.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "shell_functions.h"

int main(void)
{
    run_shell();
    return (0);
}