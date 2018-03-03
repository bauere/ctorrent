#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bencode.h"

int
benc_string(char **restrict dest, char *restrict source)
{
	unsigned len = strlen(source);
	*dest = malloc(len+3);
	int status = sprintf(*dest, "%d:%s", len, source);
	
	return (status > 0) ? 0 : status;
}

int
benc_int(char **restrict dest, int source)
{
	char *restrict ret = NULL;
	int status = sprintf(ret, "i:%de", source);
	*dest = malloc(strlen(ret)+1);
	strcpy(*dest, ret);
	
	return (status > 0) ? 0 : status;
}

/* ['spam', 'eggs'] -> l4:spam4:eggse */
int
benc_list(char **restrict dest, char **restrict source, unsigned nitems)
{
	char *restrict ret = NULL;
	char *restrict tmp = NULL;
	char *restrict stritem = NULL;
	
	for (unsigned i = 0; i < nitems; i++) {
		benc_string((char ** restrict)&stritem, source[i]);
		if (!tmp)
			tmp = malloc(strlen(stritem) + 1);
		else
			tmp = realloc(tmp, strlen(tmp) + strlen(stritem) + 1);
	    strcat(tmp, stritem);
		free(stritem);
	}
	
	*dest = malloc(strlen(tmp) + 3);
	int status = sprintf(*dest, "l%se", tmp);
	
	return (status > 0) ? 0 : status;
}	
	