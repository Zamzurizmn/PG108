#include <stdio.h>

/**
 * Retourne la position de la premiÃ¨re occurence de `needle` dans la chaine de
 * caractÃ¨re `haystack`, -1 s'il n'existe pas de telle occurence.
 *
 * Remarque: `haystack` est supposÃ© bien formÃ©e
 */
int index_of(char needle, const char *haystack)
{
    for (int i=0 ; haystack[i]!='\0';i++){
        if(haystack[i]==needle){
            return i;
        }
        else {
            return -1;
        }
    }
    
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

void hist(const char *str ,const char *dictionnary, int occurrences[]){
    int start;
    for(int i=0;dictionnary[i]!='\0';i++){
        start = index_of(dictionnary[i],str);
        int compte=0;
        if(start==-1){
            occurrences[i]=0;
        }
        else {
            for(int j= start ; str[j];j++){
                if(str[j]==dictionnary[i]){
                    compte++;
                }
            }
            occurrences[i]=compte;
        }
    }
}

/**
 * Retourne la valeur maximale du tableau `array` (de longueur `length`).
 */
int max(int length, const int array[])
{
    int maxi=0;
    //int c;
    //array[0]='0';
    for (int i=0;i<length;i++){
        if(array[i]>maxi){
            maxi=array[i];
            
        }
    }
    printf("%d \n",maxi);
    return maxi;
}


/**
 * Affiche `times` fois le caractÃ¨re `c`, suivi d'un saut de ligne.
 */
void print_n(char c, int times)
{
    int compt=0;
    int array[] = {2, 4, 0, 1};
    times = array[5];
    for(int i=0;i<times;i++){
        compt++;
    }
    printf("%c : %d \n",c,compt);

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
void draw_barplot(const char *dictionnary, const int occurrences[], int columns);


int main() {
    int length = 5;
    const char *str;
    const char *haystack;
    char dico[] = "mahp";
    int occ[] = {2, 4, 0, 1};
    int stars = 10;
    //draw_barplot(dico, occ, stars);
    
    hist(str,dico,occ);

    printf("%d \n",index_of('needle',occ));
    
    max(length,dico);
    print_n('c', 10);

    return 0;

}
