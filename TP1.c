#include <stdio.h>
#include <stdlib.h>
// EXO 2: function ni ambik satu tableau of int dgn size dia,
// pastu display (printf) number yang tak sama dgn 0
void affiche_pascal(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

// EXO 3: function ni ambik satu tableau of int dgn size dia,
// return line next (1 level bawah) dalam Pascal Triangle
// cth: maj_pascal({1,2,1}, 3) -> {1,3,3,1}
int* maj_pascal(int arr[], int size) {
    int* temp = (int*)malloc(size * sizeof(int));

    temp[0] = arr[0];

    for (int i = 1; i < size; i++) {
        temp[i] = arr[i] + arr[i - 1];
    }

    return temp;
}

int main() {
    // EXO 1
    int size = 6;
    int arr[size];

    for (int i = 0; i < size; i++) {
        arr[i] = 0;
    }

    arr[0] = 1;

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // EXO 2
    affiche_pascal(arr, 6);

    // EXO 3
    printf("EXO 3\n");

    printf("Rang n: ");
    affiche_pascal(arr, 6);

    int* next_arr = maj_pascal(arr, size);    // arr: {1} -> {1,1}

    printf("Rang n+1: ");
    affiche_pascal(next_arr, 6);

    return 0;
}
