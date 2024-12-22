#include <stdio.h>
#include <stdlib.h>
int* alloc_vec(int len,int val){
    int* tab =(int*)malloc(len*sizeof(int)){
        for(int i=0; i<len;i++){
            tab[i]=val;
        }
    }
}
int main(){
    int len=4;
    int val=3;
    int* tab=alloc_vec(len,val);
    for(int i=0;i<len;i++){
        printf("%x\n"tab[i]);
    }
    return 0;
}
