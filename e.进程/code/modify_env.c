#define _GNU_SOURCE
#include <stdlib.h>
#include "tlpi_hdr.h"

extern char **environ;

int main(int argc, char *argv[])
{
	int j;
	char **ep;
	clearenv();
	for(j = 1; j < argc; j++){
		if(putenv(argv[j]) != 0)
			errExit("putenv: %s", argv[j]);
	}

	if(setenv("GREET", "Hello world", 0) == -1)
		errExit("setenv");

	unsetenv("BYE");

	for(ep = environ; *ep != NULL; ep++)
		puts(*ep);

	exit(EXIT_SUCCESS);
}