/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 3 - Dynamic Array and Structure
 *   Hari dan Tanggal    : Selasa, 28 April 2026
 *   Nama (NIM)          : Akursio Kidung Gamel (13224051)
 *   Nama File           : soal2.c
 *   Deskripsi           : Mengurutkan inventori, lalu print nama barang dengan prefix sesuai inputan user, maksimum 3. Jika tidak ada, print TIDAK ADA
 * 
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nama[50];
} inventori;

void getInput(inventori *l, int N) {
    for (int i = 0; i < N; i++) {
        scanf("%s", l[i].nama);
    }
}

void getSug(inventori *l, inventori *sug, int *idxSug, char *prefix, int N) {
    *idxSug = 0;
    for (int i = 0; i < N; i++) {
        if (strncmp(prefix, l[i].nama, 2) == 0) {
            sug[*idxSug] = l[i];
            *idxSug = *idxSug + 1;
        }
    }
}

void sorting(inventori *l, int N) {
    for (int j = 0; j < N - 1; j++) {
        for (int i = 0; i < N - 1; i++) {
            if (strcmp(l[i].nama, l[i + 1].nama) > 0) {
                inventori temp = l[i];
                l[i] = l[i + 1];
                l[i + 1] = temp;
            }
        }
    }
}

void display(inventori *l, int N) {
    if (N > 0) {
        printf("SUGGESTION ");
        for(int i = 0; i < N && i < 3; i++) {
            printf("%s", l[i].nama);
            if (i < N - 1 && i < 2) printf(" ");
        }
    }
    else {
        printf("TIDAK ADA");
    }

}

int main() {
    int N = 0;
    int idxsug = 0;
    scanf("%d", &N);

    inventori *myData = (inventori*) malloc(N * sizeof(inventori));
    inventori *myDataSug = (inventori*) malloc(N * sizeof(inventori));

    getInput(myData, N);

    // for (int i = 0; i < N; i++) {
    //     printf("%s ", myData[i]);
    // }

    char prefix[50];
    scanf("%s", prefix);

    getSug(myData, myDataSug, &idxsug, prefix, N);
    sorting(myDataSug, idxsug);

    display(myDataSug, idxsug);

    return 0;
}

