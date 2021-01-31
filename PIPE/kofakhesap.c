#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <math.h>

int main()
{
	puts("kofakhesap girildi.");
	char tempmatrix[2][2];
	read(3,&tempmatrix, sizeof(char)*4);
	int kfc;
	kfc = tempmatrix[0][0]*tempmatrix[1][1] - tempmatrix[0][1]*tempmatrix[1][0];
	write(4,&kfc, sizeof(int));
	return 0;
}