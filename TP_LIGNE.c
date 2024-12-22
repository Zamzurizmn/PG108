#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
//Ligne Commande numéro 1
/*int main(int argc, char *argv[]){
    for (int i=0;i<argc;i++){
        printf("Argument %d : %s \n",i,argv[i]);
    }
    return 0;
}*/

//try to convert interger to chaine de caractere
char itoa(int asciiCode) {
    return (char)asciiCode;
}

int main(int argc, char *argv[]) {
    char *input = argv[1];
    char res[100] = ""; // Define an array to hold the resulting string
    
    /*for (int i = 1; i < argc; i++) {
        int asciiCode = atoi(argv[i]);  // Convert argument to integer
        char character[2] = {itoa(asciiCode), '\0'};  // Convert to char and make it a string
        strcat(res, character);  // Append the character to res
    }*/
    // Process each pair of characters in the input string
    for (int i = 0; i < strlen(input); i += 2) {
        // Extract two characters and convert them to an integer
        char temp[3] = {input[i], input[i + 1], '\0'};// Create a temporary string with 2 digits
        int asciiCode = atoi(temp); // Convert to integer ASCII code
        char character[2] = {itoa(asciiCode), '\0'}; // Convert to char and make it a string
        strcat(res, character); // Append the character to result
        }

    printf("Resulting string: %s\n", res);
    return 0;
}

//other solution
/*string itoa(int number, char *argv){
    if(number<0){
        number = -number;
        argv[0]='-';
        argv+1;
    }
    if(number == 0){
        argv[0]='0';
        argv[1]='1';
        return 1;
    }
    int i=0;
    while(number !=0){
        argv[i]=number %10 + '0';
        number /=10;
        i+=1;
    }
    for (int j=0 ; j< i/2 ; j++){
        char tmp=argv[j];
        argv[j]=argv[i-1-j];
        argv[i-1-j]=tmp;
    }
    argv[i]=0;
    return i;
}*/

//Ligne Commande numéro 2
/*int main(int argc, char *argv[]){
    int sum = 0;
 
    //boucle pour parcourir tous les arguments (sauf argv[0] qui est le nom du programme
    for (int i=1;i<argc;i++){
        //Conversion de l'argument en entier avec atoi
        sum += atoi(argv[i]);
    }
    //affichage du résultat
    printf("La somme des entiers est : %d\n",sum);
    //printf("La chaine inverti : %d",itoa(53,argv)); // affichage integer 
    return 0;
}*/

/*int est_bissextile(int annee){
    if((annee %4 == 0 && annee %100 !=0) || (annee %400 == 0)){
        return 1; // l'annee est bissextile
    }
    else {
        return 0; // l'annee n'est pas bissextile
    }
}
int main(int argc, char *argv[]){
    if (argc != 2){
        printf("Usage : %s <annee> \n", argv[0]);
        return 1;
    }
    //conversion de l'argument en entier
    int annee = atoi(argv[1]);
    //call back the fonction est_bissextile
    if (est_bissextile(annee)){
        printf("L'annee %d est bissextile. \n",annee);
    }
    else{
        printf("L'annee %d n'est pas bissextile \n",annee);
    }
    return 0;
}*/

//Calculatrice
/*int is_number(char* str){
    int i = 0;
    while (str[i] != '\0'){
        if((str[i]<'0' || str[i]>'9') && !(str[i] == '-' &&  i == 0)){
            return 0;
        }
        i++;
    }
    return i;
}
int is_valid_operateur(char *str){ // FINISH THIS AT HOME
    if((str[0]=='+' || str[0])=='-' || str[0]=='x' || str[0]=='/' ){
        return 1;
    }
    return 0;
}

int main(int argc, char *argv[]){
    printf("argc : %d \n",argc);
    //verification du nombre d'arguments
    if(argc !=4){
        printf("Erreur : Utilisation : %s <Nombre1> <operateur> <Nombre2> \n",argv[0]);
        return 1;
    }
    if (!is_number(argv[1])){
        printf("-> Le premier operande \"%s\" n'est pas un nombre \n", argv[1]);
        return 1;
    }
    if (!is_number(argv[3])){
        printf("-> Le deuxieme operande \"%s\" n'est pas un nombre \n", argv[3]);
        return 1;
    }
    /*if(argc <= 1){
        printf("mets un arguments \n");
        return 0;
    }
    if(argc > 4){
        printf("Trop d'arguments \n");
        return 0;
    }
    if(argv[1]<='0' || argv[1]>'9'){
        printf("invalid \n");
        return 0;
    }
    if(argv[3]<='0' || argv[3]>'9'){
        printf("invalid \n");
        return 0;
    }
    
    //coversion des arguments en nombre réels
    double a = atof(argv[1]);
    double b = atof(argv[3]);
    char op = argv[2][0];
    
    //verification de l'operateur et exécution de l'opération
    
    switch(op){
        case '+':
            printf("Resultat : %.2f\n",a+b);
            break;
        case '-':
            printf("Resultat : %.2f\n",a-b);
            break;
        case 'x':
            printf("Resultat : %.2f\n",a*b);
            break;
        case '/':
            if(b==0){
                printf("Erreur : Division par zéro. \n");
            }
            else{
                printf("Resultat : %.2f\n",a/b);
            }
            break;
        default :
            printf("Erreur : Operateur non valide. Utilisez +,-,x ou / . \n");
            return 1;
    }
    return 0;
}

// Ligne commande numero 3

//Calculer la longeur d'une chaine de caracteres
int my_strlen(const char *str){
    int length = 0;
    while(str[length] != '\0'){
        length ++;
    }
    return length;
}

//Inverser une chaine de caracteres
void chaine_mirroir(char *str){
    int len = my_strlen(str);
    for (int i=0;i<len/2;i++){
        char temp = str[i];
        str[i]= str[len-i-1];
        str[len-i-1]=temp;
    }
}

//Convertir une chaine en un entier (atoi)

//exemple matteo
void my_atoi(int argc, char *argv[]){
    int len = my_strlen(argc,argv);
    int nb = 0;
    for (int i=0 ; i<len-1 ; i++){
        nb = nb+(argv[1][i]-48)*10pow(i);
    }
}

//reponse sir
int my_atoi(char str[]){
    int val=0;
    int len = my_strlen(str);
    
    int puissance = 1;
    
    for (int i=len-1;i>=0;i--){
        if(i== 0 && str[i]=='-'){
            return -val; //uniquement si le premier caractere est '-'
        }
        if(!my_idigit(str)){
            if (c>='0' && c<='9'){
                return 1;
            }
            else {return 0;}
 
        if(str[i]>='0' && str[i] <= '9'){
            val +=(str[i]-'0')*puissance;
            puissance *= 10;
        }
        else {return 0;}
    }
    return val;
}

//my answer
int my_atoi(const char *str){
    int result = 0;
    for (int i = 0; str[i] !='\0'; i++){
        if(str[i] >= '0' && str[i] <= '9'){
            result = result*10+(str[i]-'0');
        }
        else{
            //si on rencontre un caractere non numérique, on arrete
            break;
        }
    }
    return result;
}

//Tester si une chaine est un palindrome
int is_palindrome(const char *str){
    int len = my_strlen(str);
    int left = 0;
    int right = len-1;
    
    while(left < right){
        // ignorer les espaces et les majuscules/minuscules
        while(!isalpha(str[left]) && left < right) left++;
        while(!isalpha(str[right]) && left < right) right--;
        
        if (tolower(str[left]) != tolower(str[right])){
            return 0; //pas de palindrome
        }
        left++;
        right--;
    }
    return 1; // c'est un palindrome
}

//main
int main(int argc, char *argv[]){
    if(argc < 2 ){
        printf("Veuillez fournir une chaine de caracteres en argument. \n");
        return 1;
    }
    
    //test de la fonction my_strlen
    printf("Longeur de '%s' : %d\n",argv[1],my_strlen(argv[1]));
    
    //test de la fonction chaine_mirroir
    char str_mirroir[100];
    strcpy(str_mirroir,argv[1]);
    chaine_mirroir(str_mirroir);
    printf("Mirroir de '%s' : %s\n",argv[1],str_mirroir);
    
    //test de la fonction my_atoi
    int number = my_atoi(argv[1]);
    printf("Conversion de '%s' en entier : %d \n",argv[1],number);
    
    //test de la fonction is_palindrome
    if(is_palindrome(argv[1])){
        printf(" '%s' est un palindrome. \n",argv[1]);
    }
    else {
        printf(" '%s' n'est un palindrome. \n",argv[1]);
    }
}*/


