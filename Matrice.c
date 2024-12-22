#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct matrix{
    int lines;
    int cols;
    double* poin;
};
int new_matrix(int lines, int cols){
    struct matrix new[lines][cols];
    new.lines=lines;
    new.cols=cols;
    new.poin=new;
    for(int i=0;i<lines*cols;i++){
        new[i]=0;
    }
    return new;
}
int get_matrix_value()