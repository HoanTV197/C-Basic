#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 500
enum {SUCCESS, FAIL};

// ham dem so dong
int lineCount(char* filename)
{
	FILE *fptr = fopen(filename,"r");
	
	if(NULL==fptr) exit(-1);
	
	int count = 0;
	char buff[MAX_LEN];
	while(fgets(buff,MAX_LEN,fptr)!=NULL)
		count++;
	
	fclose(fptr);
	return count;
}
int main(int argc, char *argv[])
{
	if(argc<2){
		printf("Khong du tham so");
		return -1;
	}
	printf("File dau vao co %d dong!\n",lineCount(argv[1]));
	return 0;
}
