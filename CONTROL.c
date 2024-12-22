#include <stdio.h>

/**
 * Retourne la position de la premiÃ¨re occurence de `needle` dans la chaine de
 * caractÃ¨re `haystack`, -1 s'il n'existe pas de telle occurence.
 *
 * Remarque: `haystack` est supposÃ© bien formÃ©e
 */
int index_of(char needle, const char *haystack){
    for (int i = 0; haystack[i] != '\0'; i++) {
        if (haystack[i] == needle) {
            return i;  // Return the index if needle is found
        }
    }
    return -1;
}

/**
 * Compte le nombre d'occurrences des caractÃ¨res de `dictionnary` dans la
 * chaine `str`. Si une lettre de `str` n'apparait pas dans la chaine
 * `dictionnary`, elle sera ignorÃ©e.
 *
 * Exemple:
 * hist("maman et papa", "map", occurrences) => occurrences == {2, 4, 2}
 *
 * Remarques:
 * - `occurrences` est suppposÃ© (dÃ©jÃ ) initialisÃ© Ã  zÃ©ro.
 * - `occurrences` est supposÃ© au moins aussi long que `dictionnary`
 */

void hist(const char *str, const char *dictionnary, int occurrences[]){
    for (int i = 0; dictionnary[i] != '\0'; i++) {
        occurrences[i] = 0;  // Initialize occurrences to 0
    }
    for (int i = 0; str[i] != '\0'; i++) {
        for (int j = 0; dictionnary[j] != '\0'; j++) {
            if (str[i] == dictionnary[j]) {
                occurrences[j]++;  // Increment count for matching dictionary character
                break;
            }
        }
    }
}

/**
 * Retourne la valeur maximale du tableau `array` (de longueur `length`).
 */
int max(int length, const int array[]){
    int max_value = array[0];
    for (int i = 1; i < length; i++) {
        if (array[i] > max_value) {
            max_value = array[i];  // Update max_value if a larger value is found
        }
    }
    return max_value;
}


/**
 * Affiche `times` fois le caractÃ¨re `c`, suivi d'un saut de ligne.
 */
void print_n(char c, int times){
    for (int i = 0; i < times; i++) {
        putchar(c);  // Print the character 'c' 'times' times
    }
    putchar('\n');
}

/**
 * Affiche un diagramme bÃ¢ton dont les labels sont les caractÃ¨res de la chaine
 * `dictionnary` (verticalement) et les valeurs (horizontalement) un nombre
 * d'Ã©toiles proportionnel Ã  l'Ã©lÃ©ment correspondant dans `occurrences`
 * La valeur la plus reprÃ©sentÃ©e aura `columns` Ã©toiles.
 * Cette fonction n'affichera pas les lettres ayant un nombre d'occurrences nul.
 *
 * Exemple:
 *      draw_barplot("mahp", {2, 4, 0, 1}, 10)
 * Affiche:
 *      m *****
 *      a **********
 *      p **
 */
void draw_barplot(const char *dictionnary, const int occurrences[], int columns){
    // Find the maximum occurrence to scale the bars
    int max_occurrence = occurrences[0];
    for (int i = 1; dictionnary[i] != '\0'; i++) {
        if (occurrences[i] > max_occurrence) {
            max_occurrence = occurrences[i];
        }
    }

    // Draw each bar based on scaled occurrence values
    for (int i = 0; dictionnary[i] != '\0'; i++) {
        if (occurrences[i] == 0) continue;  // Skip labels with zero occurrences

        // Scale the occurrence to fit within the 'columns' limit
        int star_count = (occurrences[i] * columns) / max_occurrence;
        printf("%c ", dictionnary[i]);
        for (int j = 0; j < star_count; j++) {
            putchar('*');  // Print stars for the bar
        }
        putchar('\n');  // Newline after each bar
    }
}


int main() {
    
    char dico[] = "mahp";
    int occ[] = {2, 4, 0, 1};
    int stars = 10;
    printf("Bar plot for given occurrences:\n");
    draw_barplot(dico, occ, stars);

    // Testing print_n function
    char print_char = '#';
    int times = 5;
    printf("Printing character '%c' %d times:\n", print_char, times);
    print_n(print_char, times);

    // Testing max function
    int values[] = {10, 20, 15, 7, 25};
    int length = sizeof(values) / sizeof(values[0]);
    int max_value = max(length, values);
    printf("Maximum value in array: %d\n", max_value);
    
    return 0;

}
