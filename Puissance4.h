#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h> //pour faire de emoticon dans le jeu
#include <locale.h>

#define taille 30 //decription de la taille du chaîne charactere
#define NB_COL 7 //decription de la nombre de colonne de tableau
#define NB_LIGNE 6 //decription de la nombre de ligne de tableau

char Joueur2Virtuel; //description pour l'utilisisation dans la méthode aléatoire 
char NomJoueur1[taille];
char NomJoueur2[taille]; 
char GrilleDeJeu[NB_COL*NB_LIGNE]; 
clock_t start_time,end_time;
double time_total=0.0;
int total_tours =0; //calcul le temps moyen

/*ici première fonction pour ecrire le nom des deux joeurs*/
void init(){
    printf("les nom de joueur NomJoueur1 : ");
    scanf("%s",NomJoueur1);
    printf("les nom de joueur NomJoueur2 (ou 'COMPUTER' pour jouer contre le programme ): ");
    scanf("%s",NomJoueur2);
    
    Joueur2Virtuel=(strcmp(NomJoueur2,"COMPUTER")==0) ? 1:0;
    /*if(Joueur2Virtuel != 0){
        fgets(&Joueur2Virtuel,sizeof(Joueur2Virtuel),stdin);
    }*/
    
    /*ici on initialise GrilleDeJeu pour qu'elle contienne que des 0*/
    for (int i=0; i<(NB_COL*NB_LIGNE);i++){
        GrilleDeJeu[i]=0;
    }
    start_time=clock();
}

/*fonction pour calculer l'indice dans le tableau*/
int indice(int r,int c){
    return r*NB_COL+c;
}

/*fonction pour que le jeu contre le programme*/
int CalculeColonneAleatoire(){
    //int colonne=rand()%6;
    //GrilleDeJeu[indice(r,colonne+3)];
    /*for(int r=0; r<NB_LIGNE ; r++){
        if(GrilleDeJeu[indice(r,colonne)]){
            printf("%d \n",colonne);
            return colonne;
        }
        else {
            colonne=(colonne+3)%6;
            printf("%d \n",colonne);
        }
    }*/
    int colonne,essais =0;
    while(essais<NB_COL){
        colonne=rand()% NB_COL;
        if(GrilleDeJeu[indice(NB_LIGNE-1,colonne)]==0){
            return colonne; 
        }
        essais++;
    }
    return -1;
}

/*on affichage la grille de jeu*/
void display(){
    printf("\x1B[96m   1   2   3   4   5   6   7 \x1B[0m\n");
    for(int r=NB_LIGNE-1;r>=0;r--){
        printf("\x1B[96m |\x1B[0m");
        for(int c=0;c<NB_COL;c++){
            //char symbole;
            //int i=r*NB_COL+c;
            /*if(GrilleDeJeu[i]=1){
                printf("%c",symbole='X');
            } 
            else if(GrilleDeJeu[i]=2){
                printf("%c",symbole='O');
            }
            else{
                printf("%c",symbole='.');//affichage le tableu avec le dot de la colonne 7 et ligne 6
            }*/
            //printf("%c",symbole='.');
            //printf("%c",symbole='.');
            switch(GrilleDeJeu[indice(r,c)]){
                case 1:
                    printf("\x1B[91m X \x1B[0m");
                    //symbole = 'X';
                    break;
                case 2:
                    printf("\x1B[93m O \x1B[0m");
                    //symbole = 'O';
                    break;
                default:
                    //symbole= '.'; //vide
                    printf(" . ");
            }
            //printf("%c ",symbole);
            printf("\x1B[96m|\x1B[0m");
        }
        printf("\n");
    }
    //printf("1 2 3 4 5 6 7\n");
    printf("\x1B[96m -----------------------------\x1B[0m\n");
}

/*Fonction pour demander le joueur quelle colonne pour le jeton*/
int colonne_de_joueur(int joueur){
    int colonne;
    char buffer[100];

    if(joueur==2 && Joueur2Virtuel){
        colonne=CalculeColonneAleatoire();
        if(colonne==-1){
            printf("Toutes les colonnes sont pleines.\n");
            return -1;
        }
        printf("COMPUTER VA JOUER À LA PLACE JOUEUR 2 dans la colonne %d. \n",colonne +1);
    }
    else{
        while(1){
        /*Je voulais faire une test de verification pour que le joueur rentre le bon valeur*/
        printf("Quelle colonne vous pouvez mettre le jeton (1-7):");

            if(!fgets(buffer,100,stdin)){
                printf("FAUX ! METTEZ LE BON VALEUR. \n");
                continue;
            }

            if(sscanf(buffer,"%d",&colonne)!=1 || colonne <1 || colonne >7){
                printf("Entrée invalide. Mettre le valeur entre [1-7]!. \n");
                continue;
            }
            if(colonne>=1 && colonne<=7){
                colonne=colonne-1; //convert en index de colonne (0-6)
                break;    
            }
            else{
                printf("Valeur faux. Mettre le numéro [1-7]! \n");
            } 

        }
    }
    for (int r =0;r<NB_LIGNE;r++){
        if(GrilleDeJeu[indice(r,colonne)]==0){
            GrilleDeJeu[indice(r,colonne)]=joueur;
            total_tours++;//incremente le nombre de tours
            return 1;
        }
        
    }
    printf("colonne est pleine. Choisir une autre colonne. \n");
    return -1;;
}

/*la fonction pour verifier le gagnant*/
int test_vainqueur(int joueur){
    /*verification des lignes horizontales*/
    for(int r=0 ; r<NB_LIGNE ; r++){
        for(int c=0 ; c<NB_COL-3 ; c++){
            if (GrilleDeJeu[indice(r,c)]==joueur && 
                GrilleDeJeu[indice(r,c+1)]==joueur && 
                GrilleDeJeu[indice(r,c+2)]==joueur && 
                GrilleDeJeu[indice(r,c+3)]==joueur){
                return 1;
            }
        }
    }

    /*verification des colonnes verticales*/
    for(int c=0 ; c<NB_COL ; c++){
        for(int r=0 ; r<NB_LIGNE-3 ; r++){
            if (GrilleDeJeu[indice(r,c)]==joueur && 
                GrilleDeJeu[indice(r+1,c)]==joueur && 
                GrilleDeJeu[indice(r+2,c)]==joueur && 
                GrilleDeJeu[indice(r+3,c)]==joueur){
                return 1;
            }
        }
    }
    /*verification des diagonales montantes*/
    for(int r=0 ; r<NB_LIGNE-3 ; r++){
        for(int c=0 ; c<NB_COL-3 ; c++){
            if (GrilleDeJeu[indice(r,c)]==joueur && 
                GrilleDeJeu[indice(r+1,c+1)]==joueur && 
                GrilleDeJeu[indice(r+2,c+2)]==joueur && 
                GrilleDeJeu[indice(r+3,c+3)]==joueur){
                return 1;
            }
        }
    }
    /*verification des diagnoles descendantes*/
    for(int r=3 ; r<NB_LIGNE ; r++){
        for(int c=0 ; c<NB_COL-3 ; c++){
            if (GrilleDeJeu[indice(r,c)]==joueur && 
                GrilleDeJeu[indice(r-1,c+1)]==joueur && 
                GrilleDeJeu[indice(r-2,c+2)]==joueur && 
                GrilleDeJeu[indice(r-3,c+3)]==joueur){
                return 1;
            }
        }
    }
    return 0;
}

/*Fonction pour détecter la fin du jeu*/
int detecte_plein(){
    for(int c=0;c<NB_COL;c++){
        if(GrilleDeJeu[indice(NB_LIGNE-1,c)]==0){
            return 0; //cases vides
        }
    }
    return 1; //ici, la grille est pleine
}

/*fonction pour savoir le temps moyenne de jeu*/
void afficher_temps_vainqueur(){
    end_time=clock();
    time_total =((double)(end_time-start_time))*1000 /CLOCKS_PER_SEC;
    double temps_moyen = time_total/total_tours;
    printf("temps total de : %.2lf secondes \n",temps_moyen);
}

/*fonction pour afficher le local time*/
int waktu(){
    // Set the locale to the user's default locale
    setlocale(LC_TIME, "");

    // Get the current locale for LC_TIME
    //char *currentLocale = setlocale(LC_TIME, NULL);
    //printf("Current LC_TIME locale: %s\n", currentLocale);

    // Display the current date and time
    time_t currentTime;
    struct tm *timeInfo;

    time(&currentTime);
    timeInfo = localtime(&currentTime);

    char formattedTime[100];
    strftime(formattedTime, sizeof(formattedTime), "%c", timeInfo);
    printf("Formatted date and time: %s\n", formattedTime);

    return 0;
}

/*fonction main*/
int main(){
    srand(time(NULL)); // Initiate génerateur aléatoire
    init();
    display();
    int joueurEnCours = 1; // 1 pour joueur 1, 2 pour joueur 2
    
    while(1){
        printf("C'est de tour de %s(%c).\n",joueurEnCours==1? NomJoueur1: NomJoueur2, joueurEnCours == 1?'X':'O');

        if(colonne_de_joueur(joueurEnCours)==-1){
            break;
        }
        
        display();

        /*je fais la verification le gagnant du jeu*/
        if(test_vainqueur(joueurEnCours)){
            printf("CONGRATULATIONS %s, YOU WON THIS GAME ! %s \n", joueurEnCours == 1 ? NomJoueur1 : NomJoueur2,"\U0001F600");
            afficher_temps_vainqueur();
            waktu();
            break;
        }

        /*je fais la verification si la grille est pleine*/
        if(detecte_plein()){
            printf("la grille est pleine. GAME END!!! \n");
            afficher_temps_vainqueur();
            break;
        }
        /*alterner les joueurs*/
        joueurEnCours=(joueurEnCours==1) ? 2 : 1;

    }
    return 0;
}