#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

int main() {
    puts("satsutsec girildi.");
    srand(time(NULL));
    char dizi[2];
    int sira = rand()%3;
    int ss = rand()%2;//sat=0 veya sut=1
    dizi[0]=ss;
    dizi[1]=sira;
    write(4, &dizi, sizeof(char)*2);

}
