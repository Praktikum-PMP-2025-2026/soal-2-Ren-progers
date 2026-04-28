#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct data
{
    char name[50];
}invent;
int main (){
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
            if (strcmp (arr[i].name, arr[j].name) == 1){
                strcpy (buffer, arr[i].name);
                strcpy (arr[i].name, arr[j].name);
                strcpy (arr[j].name, buffer);
            }
        }
    }
    while (k < N && count != 3){
        if (strncmp (arr[k].name, pref, strlen (pref)) == 0){
            count++;
        }
        if (count == 1){
            printf ("SUGGESTION ");
            printf ("%s ", arr[k].name);
        }
        else if (count == 3) {
            printf ("%s", arr[k].name);
        }
        else if (count != 0){
            printf ("%s ", arr[k].name);
        }
        k++;
    }
    if (count == 0){
        printf ("TIDAK ADA\n");
    }
    else {
        printf ("\n");
    }
    
    return 0;
}
