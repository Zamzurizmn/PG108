#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define BUF_SIZE 5

struct point{
    int x;
    int y;
};

float norme(struct point p1, struct point p2){
    float diff = sqrt(pow((p1.x-p2.x),2)+pow((p1.y-p2.y),2));
    return diff;
}
float xbar(struct point tabx[BUF_SIZE]){
    float somme=0;
    for(int i=1;i<=BUF_SIZE;i++){
        somme +=tabx[i].x;
    }
    somme =(somme/(float)BUF_SIZE);
    return somme;
}
float ybar(struct point taby[BUF_SIZE]){
    float somme=0;
    for(int i=1;i<BUF_SIZE;i++){
        somme +=taby[i].y;
    }
    somme=(somme/(float)BUF_SIZE);
    return somme;
}
float Var(struct point tabx[BUF_SIZE]){
    int somme=0;
    for(int i=1;i<BUF_SIZE;i++){
        somme +=pow((tabx[i].x-xbar(tabx)),2);
    }
    somme=(somme/(float)BUF_SIZE);
    return somme;

}
float Cov(struct point tabx[BUF_SIZE], struct point taby[BUF_SIZE]){
    int somme=0;
    for(int i=1;i<BUF_SIZE;i++){
        somme += (tabx[i].x-xbar(tabx))*(taby[i].y-ybar(taby));
    }
    somme=(somme/(float)BUF_SIZE);
    return somme;
}
int main(){
    struct point tab[BUF_SIZE];
    for (int i=0;i<BUF_SIZE;i++){
        char X[BUF_SIZE];
        printf("le valuer du point de x%d: ",i+1);
        fgets(X,BUF_SIZE,stdin);
        char Y[BUF_SIZE];
        printf("le valuer du point de y%d: ",i+1);
        fgets(Y,BUF_SIZE,stdin);
        tab[i].x = atoi(X);
        tab[i].y = atoi(Y);
    }
    float a,b;
    a=(Cov(tab,tab)/Var(tab));
    b=ybar(tab)-a*xbar(tab);
    printf("%f \n", a);
    printf("%f \n", b);
    printf("xbar=%f & ybar=%f \n",xbar(tab),ybar(tab));
    /*struct point p1 = {5,1};
    struct point p2 = {2,1};
    printf("norme de p1 & p2 = %f \n", norme(p1,p2));*/
    return 0;
}