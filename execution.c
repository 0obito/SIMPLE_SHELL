#include "main.h"

/**
 * execution - handle the whole execution
 *
 * @cmd: pointer to array of pointers
 * @av: arguments vector
 * @line: char pointer
 * @envp: environnement variable
 * @indice: aka index
 *
 * Return: status of last execution done
 */
int execution(char *cmd[], char *av[], char *envp[], int indice)
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
	if (S_ISDIR(saint.st_mode))
	{
		_perror(av[0], cmd[0], indice, " Permission denied\n");
		return (126);
	}

	pid = fork();

	if (pid == 0)
	{
		exe = execve(neww, cmd, envp);
		if (exe == -1)
		{
			free_line(neww);
			/*free_line(line);
			free_ressources(cmd);*/
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
