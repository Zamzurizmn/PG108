#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*int main(int argc,char* argv[]){
    int a;
    float f;
    char s[50];
    
    printf("parametre à entrer : ");
    scanf("%d %f %s",&a,&f,&s);
    //r=scanf("%d %f %s",&a,&f,&s);
    printf("parametre lus : a=%d, f=%f, s=%s \n",a,f,s); //ajoute valeur r aussi
    return 0;

}
int main(int argc,char* argv[]){
    int len;
    int tab[len];
    printf("\n");
    printf("Quelle taille fait le tableau? :");
    scanf("%d",&len);
    for(int i=0;i<len;i++){
        int val;
        printf("valeur %d ? : ",i);
        scanf("%d",&val);
        tab[i]=val;
    }
    printf("\n");
    for(int i =0;i<len;i++){
        printf("tab[%d]=%d\n",i,tab[i]);
    }
    printf("\n");
    return 0;
}*/

#define BUF_SIZE 5
int main(){
    char buffer[BUF_SIZE];
    printf("\n");
    printf("Quelle taille fait le tableau ? :");
    fgets(buffer,BUF_SIZE,stdin);
    //printf("la chaine est = %s \n",buffer);
    int tab_size=atoi(buffer);
    int* tab=(int*) malloc(sizeof(int)*tab_size);
    //int* tab = alloc_vec(tab_size,0);
    for(int i=0;i<tab_size;i++){
        printf("Valeur %d ? : ",i+1);
        char char_buf[BUF_SIZE];
        fgets(char_buf,BUF_SIZE,stdin);
        int val =atoi(char_buf);
        tab[i]=val;
    }
    for(int i=0;i<tab_size;i++){
        printf("tab[%d] : %d \n",i,tab[i]);
    }
    printf("\n");
    return 0;

}
