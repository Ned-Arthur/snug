/* touch.c
 * A recreation of touch with the following awesome features:
 * Update a file's access time by literally just opening it and closing it again
 * Use -c or --no-create to not create a file if it doesn't exist (ie. remove the
 * 	one feature people actually use)
 * ~80% binary size reduction
 *
 * And a few useless features have been omitted:
 * All the other flags
 * Who cares we can create files
 *
 *
 * Created by Ned Murry 18/11/2024
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	// Flag status holders
	int noCreate = 0;

	int fileIndexes[argc];
	// The array is of variable size (ie not known at compile-time), so we must
	// initialise its values to 0 manually
	memset(fileIndexes, 0, argc*sizeof(int));

	// Create our list of files and check arguments
	// We have to do this so the user can set flags after filenames if they so desire
	for (int i=1; i<argc; i++) {
		if (strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "--no-create") == 0) {
			noCreate = 1;
			printf("This element is the flag: %s\n", argv[i]);
			continue;
		}
		fileIndexes[i] = 1;
	}

	// Now loop through our files and touch each one
	FILE* file;
	for (int i=1; i<argc; i++) {
		if (fileIndexes[i] == 0) {
			// This arg is a flag: skip it
			continue;
		}
		if (noCreate && access(argv[i], F_OK) != 0) {
			printf("Don't create the file here\n");
			continue;
		}
		// Open and safely close this file to update the access time
		file = fopen(argv[i], "w");
		fclose(file);
	}

	return 0;
}

