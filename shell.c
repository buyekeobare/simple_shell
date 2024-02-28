#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(void)
{
	char *buf = NULL;
	size_t buf_size = 0;
	char *tok;
	int i = 0;
	char **arr;
	pid_t c_pid; /* child_pid */
	int status;

	while (1)
	{
		write(1, "#shell$ ", 9);
		getline(&buf, &buf_size, stdin);
		tok = strtok(buf, " \t\n");

		arr = malloc(sizeof(char *) * 1024);
		i = 0;

		while (tok)
		{
			arr[i] = tok;
			tok = strtok(NULL, " \t\n");
			i++;
		}

		arr[i] = NULL;

		c_pid = fork();

		if (c_pid == -1)
		{
			perror("Fork error ");
			exit(EXIT_FAILURE);
		}

		if (c_pid == 0)
		{
			if (execve(arr[0], arr, NULL) == -1)
			{
				perror("Execve error ");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			waitpid(c_pid, &status, 0);
			free(arr);
		}
	}

	free(buf);
	return (0);
}
