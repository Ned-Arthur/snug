/* echo.c
 * A recreation of the echo bash command, with a few improvements:
 * -n can now be used anywhere
 * The binary is now less than half the size
 *
 * And some missing features:
 * Escape sequences etc.
 *
 * Created by Ned Murry 18/11/2024
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	// Flag status holders
	int noNewline = 0;

	for (int i = 1; i < argc; i++)
	{
		// strcmp returns 0 if the args match
		if (strcmp(argv[i],"-n") == 0)
		{
			// If the argument is "-n" then set the flag and go to the next arg
			noNewline = 1;
			continue;
		}
		if (i != 1)
		{
			// Put a space before each argument which isn't the first
			printf(" ");
		}

		printf("%s", argv[i]);
	}

	if (!noNewline) {
		// Only put a new line if we haven't set that flag
		printf("\n");
	}

	return 0;
}

