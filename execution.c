#include "main.h"

/**
 * execution - handle the whole execution
 *
 * @cmd: pointer to array of pointers
 * @av: arguments vector
 * @indice: aka index
 * @line: char pointer
 *
 * Return: status of last execution done
 */
int execution(char **cmd, char **av, int indice, char *line)
{
	int status;
	pid_t pid;
	int exe;
	char *neww;

	neww = path_search(cmd[0]);
	if (neww == NULL)
	{
		_perror(av[0], cmd[0], indice, " not found\n");
		return (127);
	}

	pid = fork();

	if (pid == 0)
	{
		exe = execve(neww, cmd, environ);
		if (exe == -1)
		{
			_perror(av[0], neww, indice, " Permission denied\n");
			free_line(neww);
			free_line(line);
			free_ressources(cmd);
			exit(126);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		free_line(neww);
	}
	return (WEXITSTATUS(status));
}


/**
 * _perror - prints an error immitating the og shell
 *
 * @nom: program name
 * @cmd: command to execute
 * @n: index aka indice
 * @sms: message to preview
 */
void _perror(char *nom, char *cmd, int n, char *sms)
{
	int i = 0, m;
	int num[50];

	write(STDERR_FILENO, nom, _strlen(nom));
	write(STDERR_FILENO, ": ", 2);

	if (n >= 10)
	{
		while (n > 0)
		{
			m = n % 10;
			num[i] = m;
			n = n / 10;
			i++;
		}
		i--;
		while (i >= 0)
		{
			_putchar('0' + num[i]);
			i--;
		}
	}
	else
		_putchar('0' + n);

	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, ":", 1);
	write(STDERR_FILENO, sms, _strlen(sms));
}
