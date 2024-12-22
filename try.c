#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAILLE 30 // Taille maximale des noms des joueurs
#define NB_COL 7  // Nombre de colonnes de la grille
#define NB_LIGNE 6 // Nombre de lignes de la grille

char NomJoueur1[TAILLE];
char NomJoueur2[TAILLE];
char GrilleDeJeu[NB_COL * NB_LIGNE]; // Grille de jeu sous forme de tableau 1D
clock_t start_time, end_time; // Variables pour mesurer le temps
float temps_total = 0.0; // Temps total de jeu

/* Fonction pour calculer l'indice dans le tableau 1D correspondant aux coordonnées (r, c) */
int indice(int r, int c) {
    return r * NB_COL + c;
}

/* Fonction pour initialiser les noms des joueurs et la grille de jeu */
void init() {
    printf("Entrez le nom du joueur 1 : ");
    scanf("%s", NomJoueur1);
    printf("Entrez le nom du joueur 2 : ");
    scanf("%s", NomJoueur2);

    // Initialisation de la grille avec des zéros (cases vides)
    for (int i = 0; i < NB_COL * NB_LIGNE; i++) {
        GrilleDeJeu[i] = 0;
    }
    start_time = clock(); // Début du chronomètre
}

/* Fonction pour afficher la grille de jeu */
void display() {
    printf("\nGrille de jeu :\n");
    for (int r = NB_LIGNE - 1; r >= 0; r--) { // Commencer par la dernière ligne (affichage en haut vers le bas)
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
                    symbole = '.'; // Case vide
                    break;
            }
            printf("%c ", symbole);
        }
        printf("\n");
    }

    // Affichage des numéros de colonnes
    printf("1 2 3 4 5 6 7\n");
}

/* Fonction combinée pour demander au joueur la colonne et placer un jeton */
int colonne_de_joueur(int joueur) {
    int colonne;
    while (1) {
        printf("\nQuelle colonne pour placer le jeton (1-7) : ");
        scanf("%d", &colonne);
        if (colonne >= 1 && colonne <= 7) {
            colonne -= 1; // Convertir en index de colonne (0-6)

            // Tenter de placer le jeton
            for (int r = 0; r < NB_LIGNE; r++) {
                if (GrilleDeJeu[indice(r, colonne)] == 0) {
                    GrilleDeJeu[indice(r, colonne)] = joueur;
                    return 1; // Succès
                }
            }
            printf("La colonne est pleine. Choisissez une autre colonne.\n");
        } else {
            printf("Valeur invalide. Veuillez entrer un numéro entre 1 et 7 : ");
        }
    }
}

/* Fonction pour vérifier si un joueur a gagné */
int test_vainqueur(int joueur) {
    // Vérification des lignes horizontales
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

    // Vérification des colonnes verticales
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

    // Vérification des diagonales montantes
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

    // Vérification des diagonales descendantes
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

    return 0; // Aucun vainqueur
}

/* Fonction pour vérifier si la grille est pleine */
int detecte_plein() {
    for (int c = 0; c < NB_COL; c++) {
        if (GrilleDeJeu[indice(NB_LIGNE - 1, c)] == 0) {
            return 0; // Il reste des cases vides
        }
    }
    return 1; // La grille est pleine
}

/* Fonction pour mesurer et afficher le temps total de jeu */
void afficher_temps_total() {
    end_time = clock(); // Fin du chronomètre
    temps_total += (float)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("\nTemps total de jeu : %.2f secondes.\n", temps_total);
}

int main() {
    init();
    display();

    int joueurEnCours = 1; // 1 pour joueur 1, 2 pour joueur 2

    while (1) { // Boucle infinie pour le jeu
        printf("\nC'est le tour de %s (%c).", joueurEnCours == 1 ? NomJoueur1 : NomJoueur2, joueurEnCours == 1 ? 'X' : 'O');

        colonne_de_joueur(joueurEnCours);
        display();

        // Vérifier si le joueur courant a gagné
        if (test_vainqueur(joueurEnCours)) {
            printf("\nFélicitations %s, vous avez gagné !\n", joueurEnCours == 1 ? NomJoueur1 : NomJoueur2);
            afficher_temps_total();
            break;
        }

        // Vérifier si la grille est pleine
        if (detecte_plein()) {
            printf("\nLa grille est pleine. Match nul !\n");
            afficher_temps_total();
            break;
        }

        // Alterner les joueurs
        joueurEnCours = (joueurEnCours == 1) ? 2 : 1;
    }

    return 0;
}
