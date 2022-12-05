#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 500

void processFile(char *filename)
{
	FILE *fptr = fopen(filename,"r");
	if(NULL==fptr) exit(-1);
	
	int sum=0, count=0;
	double tbc;
	int digit;
	
	while(fscanf(fptr,"%d",&digit)>0)
	{
		count++;
		sum+=digit;
	}
	
	fclose(fptr);
	if(count==0){
		printf("File khong co so nao!\n");
	}
	else
	{
		printf("So luong so: %d\n",count);
		printf("Tong: %d\n",sum);
		printf("TBC: %.2f\n",sum*1.0/count);
	}
}
int main(int argc, char *argv[])
{
	if(argc<2){
		printf("Khong du tham so");
		return -1;
	}
	processFile(argv[1]);
	return 0;
}
