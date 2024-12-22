#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//exo swap var pg 79
/*void swap_var(int *ptr_a, int *ptr_b,int a,int b){
    *ptr_a= b;
    *ptr_b= a;
    printf("swap : a=%d, b=%d \n",a,b);
}
void order(int *ptr_a, int *ptr_b,int a,int b){
    if(a>b){
        swap_var(ptr_a, ptr_b, a, b);
    }
}
int main(){
    int a=3;
    int b=5;
    int* ptr_a = &a ;
    int* ptr_b = &b ;
    //swap_var(ptr_a,ptr_b,a,b);
    //printf("main : a=%d, b=%d \n",a,b);
    order(ptr_a,ptr_b,a,b);
    printf("order : a=%d, b=%d \n",a,b);
    return 0;
}*/


//reprendre de c2_tab.c et afficher l'addresse de chaque case memoire pg91
/*int parcours(int len,int *tab){
    for(int i=0;i<len;i++){
        printf("adresse de %d = % \n",i,&tab[i]);
    }
    return 0;
}
//main
int main(){
    int tab[5]={2,3,15,-3,3};
    int len = 5;
    parcours(len,tab);
    //display tab elements
    int i=0;
    while(i<len){
        printf("Case %d : %d \n",i,tab[i]);
        i=i+1;
        
    }
    return 0;
}*/
//tableau pointeur (valeur min/max)

/*void min_max(int l, int t[], int* min, int* max){
    
    if(l > 0){
        if (min != NULL) *min = t[0];
        if (max != NULL) *max = t[0];
        for(int i=0; i<l; i++){
            if(*max<t[i])
                *max = t[i];
            if(*min>t[i])
                *min = t[i];
        }
    }
    printf("min: %d, max: %d\n", *min,*max );
}

void affichage(int l, int tab[]){
    for(int i=0; i<l; i++){
        printf("%d ",tab[i]);
    }
    printf("\n");
}

int main(){
    int min;
    int max;
    int* ptr_min = &min ;
    int* ptr_max = &max ;

    int tab[] = {50,20,30,99,70};
    affichage(5, tab);

    min_max(5, tab, ptr_min, ptr_max);

    return 0;
}*/

//tableau pointeurs(la somme de deux tableu)
/*void somme(int l, int t1[], int t2[], int t3[]){
    for(int i=0; i<l; i++){
        t3[i] = t1[i] + t2[i];
    }
}
void affichage(int l, int tab[]){
    for(int i=0; i<l; i++){
        printf("%d ",tab[i]);
    }
    printf("\n");
}
int main(){
    int tab1[] = {1, 4, 0, 55, 5};
    int tab2[] = {60, 2, 3, 4, 1};
    int tab3[] = {};

    somme(5, tab1, tab2, tab3);

    affichage(5, tab3);

    return 0;
}*/

//chaines caracteres / pointeurs pg92

// Function to copy src into dst and return pointer to null terminator of dst
/*char* my_stpcpy(char* dst, const char* src) {
    while (*src) {
        *dst++ = *src++;    //here we need the pointer of dst increase in the same time of src (increament le pointer & récuper le valeur)
        //*src := '\n';
        //*dst=*src;
        //dst++;
        //src++;
    }
    *dst = '\0'; // we know here is stop the pointer when it equal to \0
    return dst;
}

// Function to concatenate src to the end of dst and return dst
char* my_strcat(char* dst, const char* src) {
    char* original_dst = dst; // we declare first the new pointer named original_dst

    // Move dst to the end of its current content
    while (*dst) {
        dst++; // that pointer of dst increase
    }
    // Copy src to the end of dst
    while (*src) {
        *dst++ = *src++;
    }
    *dst = '\0'; // Null-terminate the result
    return original_dst;
}

// Function to compare s1 and s2 lexicographically
int my_strcmp(const char* s1, const char* s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(unsigned char*)s1 - *(unsigned char*)s2;
}

// Function to compute the length of a string
int my_strlen(const char* str) {
    const char* start = str;
    while (*str) {
        str++;
    }
    return str - start;
}

int main() {
    // Test my_stpcpy
    char src1[] = "Hello";
    char dst1[20];
    printf("Testing my_stpcpy:\n");
    my_stpcpy(dst1, src1);
    printf("Source: %s\n", src1);
    printf("Destination after my_stpcpy: %s\n\n", dst1);

    // Test my_strcat
    char src2[] = " World";
    char dst2[20] = "Hello";
    printf("Testing my_strcat:\n");
    my_strcat(dst2, src2);
    printf("Source: %s\n", src2);
    printf("Destination after my_strcat: %s\n\n", dst2);

    // Test my_strcmp
    char s1[] = "abc";
    char s2[] = "abd";
    printf("Testing my_strcmp:\n");
    printf("Comparing %s and %s: %d\n", s1, s2, my_strcmp(s1, s2));
    printf("Comparing %s and %s: %d\n", s1, s1, my_strcmp(s1, s1));
    printf("Comparing %s and %s: %d\n\n", s2, s1, my_strcmp(s2, s1));

    // Test my_strlen
    char str[] = "Hello, world!";
    printf("Testing my_strlen:\n");
    printf("Length of %s: %d\n", str, my_strlen(str));

    return 0;
}*/
//reponse de prof
/*
 char *my_strcpy(char dst[], const char *src)
 */

//fonction pointeurs génériques pg 97
void* my_memcpy(void* dst, const void* src,size_t len){
    char* dst_new= (char*) dst;
    char* src_new= (char*) src;
    while(len>0){
        *dst_new++ = *src_new++;
        len--;
    }
    dst='\0';
    return dst;
}
void* my_memset(void* src, int c, size_t len){
    unsigned char c_new=c;
    char* src_new= (char*) src;
    while (len>0){
        *src_new++=c_new;
        len--;
    }
    return src;
}
int my_memcmp(void* src, void* dst, size_t len){
    char* src_new = (char*) src;
    char* dst_new = (char*) dst;
    while ((*src_new==*dst_new) && (len>0)){
        if(*src_new==0){
            return -1;
        }
        if(*src_new!=*dst_new){
            return *src_new-*dst_new;
        }
        src++;
        dst++;
        len--;
    }
}
int main(){
    // Test my_memcpy
    
    char src1[] = "hello";
    char dst1[50];
    
    printf("Source: 0x%hhx\n", src1);
    printf("Destination before my_memcpy: 0x%hhx\n\n", dst1);
    size_t nb_bytes=(strlen(src1)+1 * sizeof(char));
    
    printf("\n");
    
    printf("Testing my_memcpy:");
    
    my_memcpy(&dst1, &src1,sizeof(src1));
    printf("\n");
    printf("Source: 0x%hhx\n", src1);
    printf("Destination after my_memcpy: 0x%hhx\n\n", dst1);
    
    return 0;
}
/*void swab (const void* src,void* dest,size_t nbytes){
    char* src=src;
    char* dest=dest;
    while(nbytes>0){
        
    }
}*/
// test
//void toto(void *)
