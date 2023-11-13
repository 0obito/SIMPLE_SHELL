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
	char *line = NULL;
	int status = 0;
	char **command = NULL;
	(void)ac;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "$ ", 2);
		line = read_input();
		if (line == NULL)
		{
			free(line);
			line = NULL;
			if (isatty(STDIN_FILENO) == 1)
				write(STDOUT_FILENO, "\n", 1);

			return (status);
		}

		command = tokenize(line);
		if (command == NULL)
		{
			write(STDOUT_FILENO, "\n", 1);
			free_line(line);
			continue;
		}

		status = execution(command, av, line);

		if (line != NULL)
		{
			free(line);
			line = NULL;
		}
		if (command != NULL)
			free_ressources(command);
	}

	return (status);
}
