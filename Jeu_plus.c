#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char* argv[]) {

    int val = rand()%200;
    printf("\n");

    int try = 0;
    while (try != val) {
      printf("Entrez une valeur : ");
      scanf("%d", &try);
      if (try > val)
        printf("C'est moins ! \n");
      if (try < val)
        printf("C'est plus ! \n");
    }
    printf("\nle nombre est %d\n", val);
    return 0;
}
