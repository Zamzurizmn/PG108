#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define taille 30 // Taille maximale des noms des joueurs
#define NB_COL 7  // Nombre de colonnes de la grille
#define NB_LIGNE 6 // Nombre de lignes de la grille

char Joueur2Virtuel; // Indicateur pour le mode IA
char NomJoueur1[taille];
char NomJoueur2[taille];
char GrilleDeJeu[NB_COL * NB_LIGNE];
clock_t start_time, end_time;
float time_total = 0.0;

/* Fonction pour initialiser les noms des joueurs et la grille */
void init() {
    printf("Entrez le nom du joueur 1 : ");
    scanf("%s", NomJoueur1);
    printf("Entrez le nom du joueur 2 (ou 'IA' pour jouer contre le programme) : ");
    scanf("%s", NomJoueur2);

    Joueur2Virtuel = (strcmp(NomJoueur2, "IA") == 0) ? 1 : 0;

    for (int i = 0; i < (NB_COL * NB_LIGNE); i++) {
        GrilleDeJeu[i] = 0;
    }
    start_time = clock();
}

/* Fonction pour calculer l'indice dans le tableau */
int indice(int r, int c) {
    return r * NB_COL + c;
}

/* Fonction pour choisir une colonne aléatoire (IA) */
int CalculeColonneAleatoire() {
    int colonne, essais = 0;

    while (essais < NB_COL) { // Limiter les essais pour éviter des boucles infinies
        colonne = rand() % NB_COL;
        if (GrilleDeJeu[indice(NB_LIGNE - 1, colonne)] == 0) {
            return colonne; // Retourne une colonne valide
        }
        essais++;
    }
    return -1; // Toutes les colonnes sont pleines
}

/* Fonction pour afficher la grille de jeu */
void display() {
    for (int r = NB_LIGNE - 1; r >= 0; r--) {
        for (int c = 0; c < NB_COL; c++) {
            char symbole;
            switch (GrilleDeJeu[indice(r, c)]) {
                case 1:
                    symbole = 'X';
                    break;
                case 2:
                    symbole = 'O';
                    break;
                default:
                    symbole = '.'; // Vide
            }
            printf("%c ", symbole);
        }
        printf("\n");
    }
    printf("1 2 3 4 5 6 7\n");
}

/* Fonction pour demander la colonne au joueur ou à l'IA */
int colonne_de_joueur(int joueur) {
    int colonne;

    if (joueur == 2 && Joueur2Virtuel) {
        colonne = CalculeColonneAleatoire();
        if (colonne == -1) {
            printf("Toutes les colonnes sont pleines.\n");
            return -1;
        }
        printf("L'IA joue dans la colonne %d.\n", colonne + 1);
    } else {
        char buffer[100];
        while (1) {
            printf("%s, choisissez une colonne (1-7) : ", joueur == 1 ? NomJoueur1 : NomJoueur2);
            if (!fgets(buffer, sizeof(buffer), stdin)) {
                printf("Entrée invalide. Réessayez.\n");
                continue;
            }
            if (sscanf(buffer, "%d", &colonne) != 1 || colonne < 1 || colonne > 7) {
                printf("Veuillez entrer un numéro de colonne valide (1-7).\n");
                continue;
            }
            colonne--; // Convertir en index (0-6)
            if (GrilleDeJeu[indice(NB_LIGNE - 1, colonne)] == 0) {
                break; // Colonne valide
            }
            printf("Cette colonne est pleine. Choisissez une autre colonne.\n");
        }
    }

    for (int r = 0; r < NB_LIGNE; r++) {
        if (GrilleDeJeu[indice(r, colonne)] == 0) {
            GrilleDeJeu[indice(r, colonne)] = joueur;
            return 1;
        }
    }
    return -1;
}
/* Fonction pour vérifier si la grille est pleine */
int detecte_plein() {
    for (int c = 0; c < NB_COL; c++) {
        if (GrilleDeJeu[indice(NB_LIGNE - 1, c)] == 0) {
            return 0; // Au moins une colonne n'est pas pleine
        }
    }
    return 1; // Toutes les colonnes sont pleines
}
/* Fonction pour vérifier un gagnant */
int test_vainqueur(int joueur) {
    /* Vérification des lignes */
    for (int r = 0; r < NB_LIGNE; r++) {
        for (int c = 0; c < NB_COL - 3; c++) {
            if (GrilleDeJeu[indice(r, c)] == joueur &&
                GrilleDeJeu[indice(r, c + 1)] == joueur &&
                GrilleDeJeu[indice(r, c + 2)] == joueur &&
                GrilleDeJeu[indice(r, c + 3)] == joueur) {
                return 1;
            }
        }
    }
    /* Vérification des colonnes */
    for (int c = 0; c < NB_COL; c++) {
        for (int r = 0; r < NB_LIGNE - 3; r++) {
            if (GrilleDeJeu[indice(r, c)] == joueur &&
                GrilleDeJeu[indice(r + 1, c)] == joueur &&
                GrilleDeJeu[indice(r + 2, c)] == joueur &&
                GrilleDeJeu[indice(r + 3, c)] == joueur) {
                return 1;
            }
        }
    }
    /* Vérification des diagonales */
    for (int r = 0; r < NB_LIGNE - 3; r++) {
        for (int c = 0; c < NB_COL - 3; c++) {
            if (GrilleDeJeu[indice(r, c)] == joueur &&
                GrilleDeJeu[indice(r + 1, c + 1)] == joueur &&
                GrilleDeJeu[indice(r + 2, c + 2)] == joueur &&
                GrilleDeJeu[indice(r + 3, c + 3)] == joueur) {
                return 1;
            }
        }
    }
    for (int r = 3; r < NB_LIGNE; r++) {
        for (int c = 0; c < NB_COL - 3; c++) {
            if (GrilleDeJeu[indice(r, c)] == joueur &&
                GrilleDeJeu[indice(r - 1, c + 1)] == joueur &&
                GrilleDeJeu[indice(r - 2, c + 2)] == joueur &&
                GrilleDeJeu[indice(r - 3, c + 3)] == joueur) {
                return 1;
            }
        }
    }
    return 0;
}

/* Fonction principale */
int main() {
    srand(time(NULL)); // Initialiser le générateur aléatoire
    init();
    display();

    int joueurEnCours = 1;
    while (1) {
        printf("C'est le tour de %s (%c).\n", joueurEnCours == 1 ? NomJoueur1 : NomJoueur2, joueurEnCours == 1 ? 'X' : 'O');

        if (colonne_de_joueur(joueurEnCours) == -1) {
            break;
        }

        display();

        if (test_vainqueur(joueurEnCours)) {
            printf("Félicitations %s, vous avez gagné !\n", joueurEnCours == 1 ? NomJoueur1 : NomJoueur2);
            break;
        }

        if (detecte_plein()) {
            printf("La grille est pleine. Match nul !\n");
            break;
        }

        joueurEnCours = (joueurEnCours == 1) ? 2 : 1;
    }

    return 0;
}

