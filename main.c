#include <stdio.h>
#include <stdlib.h>

#include "bencode.h"


int main(int argc, char **argv) {
	char test[] = "look at these hands";
	char *ret = NULL;
	char **arr = malloc(2 * sizeof(char *));
	arr[0] = "wow"; 
	arr[1] = "cool";
	benc_string(&ret, test);
	puts("PRINTING");
	printf("%s\n", ret);
	puts("PRINT2");
	free(ret);
	benc_list(&ret, arr, 2);
	
	puts("BLANK");
	
	printf("%s\nTHISISTHENED", ret);
	return 0;
}