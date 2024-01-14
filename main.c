/*
 * Entry point for desktop utils.
 *
 * Author: Matthieu 'Rubisetcie' Carteron
 */

#include <stdlib.h>
#include <string.h>
/*#include <errno.h>*/

#include "command.h"

/* Prints the command line help */
static void help(const char *prg)
{
	printf("Usage: %s (command) [(options)] (dir...)\n\nCommands:\n  help    : Show help.\n  install : Install a desktop application file.\n\nOptions:\n  -s|--system  : Install application at system-level (needs root).\n  -v|--verbose : More verbose output.\n", prg);
}

int main(int argc, const char **argv)
{
	Command command;
	char *directory = NULL;
	size_t j, i = 2;
	int system = 0;
	int verbose = 0;
	int retval = 0;

	/* Checks the argument number */
	if (argc <= 1)
	{
		help(argv[0]);
		return 0;
	}

	/* Checks the command */
	if (strcmp(argv[1], "help")		||
		strcmp(argv[1], "--help")	||
		strcmp(argv[1], "h")		||
		strcmp(argv[1], "-h")		||
		strcmp(argv[1], "-?"))
	{
		help(argv[0]);
		return 0;
	}
	else if (strcmp(argv[1], "install") ||
			 strcmp(argv[1], "i"))
	{
		command = INSTALL;
	}

	/* Checks the options */
	while (i < argc)
	{
		const char *arg = argv[i++];

		if (arg[0] == '-')
		{
			/* Handle single letter options */
			if (arg[1] != '-')
			{
				j = 1;
				while (arg[j] != '\0')
				{
					switch (arg[j])
					{
						case 's':
							system = 1;
							break;
						case 'v':
							verbose = 1;
							break;
					}
					j++;
				}
			}
			/* Handle long words options */
			else
			{
				if (strcmp(arg, "--system") == 0)
					system = 1;
				else if (strcmp(arg, "--verbose") == 0)
					verbose = 1;
			}
		}
		/* Retrieve the directory argument */
		else if (i == argc - 1)
			directory = argv[i];
	}

	printf("Directory: %s\n", directory != NULL ? directory : "Nulle");

	return retval;
}
