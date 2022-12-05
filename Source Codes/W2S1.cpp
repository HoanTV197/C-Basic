#include <stdio.h>
#include <stdlib.h>
enum {SUCCESS, FAIL};

void CharReadWrite(FILE *fin, FILE *fout)
{
	int c;
	while ((c=fgetc(fin)) != EOF){
	    fputc(c, fout);  /* write to a file */
	    putchar(c); 
        /* display character on the screen */
	}
}

// ten file la tham so duoc truyen khi goi ham
// tham so dau  tien la ten file dich de ghi vao argv[1]
// than so thu 2 la ten file nguon de doc du lieu argv[2]
main(int argc, char *argv[]) {
	if(argc<3) {
		printf("Thieu tham so!");
		exit(-1);
	}
	FILE *fptr1, *fptr2;
	int reval = SUCCESS;

	if ((fptr2 = fopen(argv[2], "r")) == NULL){
	    printf("Cannot open %s.\n", argv[2]);
	    exit(-1);
	} 
	else if ((fptr1 = fopen(argv[1], "w")) == NULL){
		printf("Cannot open %s.\n", argv[1]);
		exit(-1);
	} else 
	{
		CharReadWrite(fptr2, fptr1);
		fclose(fptr1);
		fclose(fptr2);
	}
	return reval;
}

