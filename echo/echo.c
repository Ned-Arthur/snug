#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int noNewline = 0;

	for (int i = 1; i < argc; i++)
	{
		// strcmp returns 0 if the args match
		if (strcmp(argv[i],"-n") == 0)
		{
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

