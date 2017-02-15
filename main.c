#include <stdlib.h>
#include <stdio.h>

#define LINE_BUF_LEN 512

int main (int argc, char ** argv)
{
	FILE * src = fopen(argv[1], "r");
	if (src)
	{
		unsigned int succ;
		char * lineBuf = (char *) malloc(sizeof(char) * LINE_BUF_LEN);
		while (!src.EOF)
		fscanf(src, "%s", lineBuf);
		printf("%s", lineBuf);
		fclose(src); free(lineBuf);
	}
	else
	{
		printf("Unable to open %s", argv[1]);
		return 1;
	}
}
