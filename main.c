#include "main.h"

/**
 * main - main function, simple shell
 *
 * @ac: args count
 * @av: args vector
 *
 * Return: status
 */
int main(int ac, char *av[])
{
	char *line = NULL, **cmd = NULL;
	char exit[] = "exit\n", env[] = "env\n";
	int status = 0, indice = 0;
	(void)ac;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "$ ", 2);
		line = read_input();
		if ((line == NULL) || (_strcmp(line, exit) == 0))
		{
			free_line(line);
			if (isatty(STDIN_FILENO) == 1)
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		if (_strcmp(line, env) == 0)
		{
			_getfullenv();
			free_line(line);
			continue;
		}

		indice++;
		cmd = tokenize(line, " \t\n");
		if (cmd == NULL)
		{
			free_line(line);
			continue;
		}

		status = execution(cmd, av, indice, line);
		free_line(line);
		free_ressources(cmd);
	}
	return (status);
}
