#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
    int matrix[3][3];
    char matrix2[17];
    puts("matrix giriniz:");
    gets(matrix2);
    int counter = 0;
    char *ptr= strtok(matrix2," ");

    for (int i = 0; i < 3; i++) {
         for (int j = 0; j < 3; j++) {
             if (counter == 9) {
                 break;
             }
            matrix[i][j] = atoi(ptr);
            ptr=strtok(NULL," ");
            counter++;
        }
    }
    int pipefd[2];
    if (pipe(pipefd)<0){
        perror("pipe");
        exit(1);
    }
    int exec;
    int fv = fork();
    if (fv == 0){
        exec = execv("satsutsec", NULL);
        perror("");

    }else {
         wait(&fv);
         //sleep(0.5);
         char sonuc[2];
         read(pipefd[0], &sonuc, sizeof(char)*2);		 
         printf("0 ise sutun 1 ise satir = %d\n",sonuc[0]); 
         printf("sirasi = %d\n",sonuc[1]);
        }
	char tempmatrix[2][2];
	int counter2=0;
	int counter3=-1;
	int temp=0;
    
    for (int k = 1; k < 4; k++) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if(i!=pipefd[0] && j!=counter2){
                tempmatrix[counter3][counter2]=matrix[i][j];
                counter2++;
                }
            }
        counter2=0;
        counter3++;
        }

		 int pipefd2[2];
    if (pipe(pipefd2)<0){
        perror("pipe");
        exit(1);
    }
    
    int exec2;
    int fv2 = fork();
    if (fv2 == 0){
        write(4, &tempmatrix, sizeof(char)*4);
        
        exec2 = execv("kofakhesap", NULL);
        perror("");

    }else {
        wait(&fv2);
        int kfc;
        
        read(3, &kfc, sizeof(int));
        
        printf("%d\n",kfc); 
        }
    }

        
}