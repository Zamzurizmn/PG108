#include <stdio.h>

/*int main(){
    int tab[5]={2,3,15,-3,3};
    int len = 5;
    int i=0;
    while(i<len){
        printf("Case %d : %d \n",i,tab[i]);
        i++;
    }
    return 0;
}
int main(){
    char c = 67, d= 'c';
    printf("%hhi, %c, %d\n",c,c,c==d);
    return 0;
}
int my_strlen(int argc, char *argv[]){
    int comp = 0;
    while (argv[1][comp] != 0){
        comp ++;
    }
    printf("len = %d \n",comp);
    return comp+1;
}
void chain_mirroir(int argc, char *argv[]){
    int len = my_strlen(argc,argv);
    char tab[len];
    for (int i=0;i<len;i++){
        tab[i]=argv[1][len-2-i];
    }
    tab[len-1]='\0';
    printf("%s => %s, len = %d \n",argv[1],tab,len);
}
int main(int argc, char *argv[]){
    my_strlen(argc,argv);
    chain_mirroir(argc,argv);
    return 0;
    
}*/
void print_ascii(){
    for (int i=0;i<128;i++){
        printf("%hhi -> %c \n",i,i);
    }
}
int my_isalpha(char c){
    return(c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}
char my_tolower(char c){
    if(c >= 'A' && c <= 'Z'){
        return c+32;
    }
    return c;
}
int main(){
    char c = 'G';
    if (my_isalpha(c)){
        printf("%c est une lettre de l'alphabet. \n",c);
    }
    else {
        printf("%c n'est pas une lettre de l'alphabet. \n",c);
    }
    printf("Minuscule de %c est %c \n",c, my_tolower(c));
    //print_ascii();
    return 0;
}

