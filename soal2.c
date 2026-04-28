/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 3 - Dynamic Array and Structure
 *   Hari dan Tanggal    : Selasa, 28 April 2026
 *   Nama (NIM)          : Akursio Kidung Gamel (13224051)
 *   Nama File           : soal2.c
 *   Deskripsi           : Mengurutkan inventori, lalu print nama barang dengan prefix sesuai inputan user, maksimum 3. Jika tidak ada, print TIDAK ADA
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct data
{
    char name[50];
}invent;
int main (){
    int valid = 0;
    int N, count = 0, k = 0;
    char buffer[50], pref [10];
    scanf ("%d", &N);
    invent *arr = (invent*) malloc (N * sizeof(invent));
    for (int i = 0; i < N; i++){
        scanf ("%s", arr[i].name);
    }
    scanf ("%s", pref);
    for (int i = 0; i < N; i++){
        for (int j = i+1; j < N; j++){
            if (strcmp (arr[i].name, arr[j].name) > 0){
                strcpy (buffer, arr[i].name);
                strcpy (arr[i].name, arr[j].name);
                strcpy (arr[j].name, buffer);
            }
        }
    }
    while (k < N && count < 3){
        if (strncmp (arr[k].name, pref, strlen (pref)) == 0){
            count++;
            valid = 1;
        }
        if (count == 1 && valid == 1){
            printf ("SUGGESTION ");
            printf ("%s ", arr[k].name);
        }
        else if (count == 3 && valid == 1) {
            printf ("%s", arr[k].name);
        }
        else if (count != 0  && valid ==1){
            printf ("%s ", arr[k].name);
        }
        k++;
        valid = 0;
    }

    if (count == 0){
        printf ("TIDAK ADA\n");
    }
    else {
        printf ("\n");
    }
    free (arr);
    return 0;
}

}

