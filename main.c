#ifndef __QU_OBJ_PARSE__
#define __QU_OBJ_PARSE__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LEX_BUF_LEN 128

int main(int argc, char ** argv) {
	FILE * source = fopen(argv[1], "r");

	if (source) {

		char * lexBuf = (char *) malloc(sizeof(char) * LEX_BUF_LEN);
		int status;

		do {
			status = fscanf(source, "%s", lexBuf);
			printf("%s : ", lexBuf);
			if (strcmp(lexBuf, "\n") == 0)
				continue;
			if (strcmp(lexBuf, "#") == 0) {
				fgets(0, 0, source);
				printf("Comment");
				continue;
			}
			if (strcmp(lexBuf, "v") == 0) {
				double x, y, z;
				status = fscanf(source, "%lf %lf %lf", &x, &y, &z);
				printf("Vertex\n");
				continue;
			}
			if (strcmp(lexBuf, "vn") == 0) {
				double nx, ny, nz;
				status = fscanf(source, "%lf %lf %lf", &nx, &ny, &nz);
				printf("Normal\n");
				continue;
			}
			if (strcmp(lexBuf, "f") == 0) {
				unsigned int v, tx, vn;
				status = fscanf(source, "%i/%i/%i %i/%i/%i %i/%i/%i",
					&v, &tx, &vn, &v, &tx, &vn, &v, &tx, &vn);
				printf("Face\n");
				continue;
			}
		} while (status != EOF);


	} else {
		printf("Bad filename\n");
		return -1;
	}

	return 0;
}

#endif  // __QU_OBJ_PARSE__
