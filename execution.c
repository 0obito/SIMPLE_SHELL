#include "main.h"

/**
 * execution - handle the whole execution
 *
 * @command: pointer to array of pointers
 * @argv: arguments vector
 *
 * Return: status of last execution done
 */
int execution(char *command[], char *argv[], char *line)
{
	int status;
	pid_t pid;
	int exe;

	pid = fork();

	if (pid == 0)
	{
		exe = execve(command[0], command, environ);
		if (exe == -1)
		{
			perror(argv[0]);
			free_line(line);
			free_ressources(command);
			exit(0);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		/*free_ressources(command);*/
	}

	return (WEXITSTATUS(status));
}
