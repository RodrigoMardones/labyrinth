#include "stdio.h"
#include "stdlib.h"
#include "headers.h"




int main(){
    char **p1;
    //char **p2;
    p1 = piso("piso1.txt");
    //p2 = piso("piso2.txt");
    free(p1);
    //free(p2);
    return 0;
}