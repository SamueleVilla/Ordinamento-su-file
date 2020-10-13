/*
Estrarre N numeri casuali compresi tra 1 e 100, scriverli nel file "numeri.txt",
leggere il file, ordinare i numeri in modo crescente, scrivere i numeri ordinati nel file numeri_ord.txt 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 500

int random(int _min, int _max)
{
    return rand() % _max + _min;
}

void inNumbers(int v[], int n)
{
    for (int i = 0; i < n; i++)
        v[i] = random(0, 100);
}

void arraySort(int v[], int n)
{
    int i, j, key = 0;
    for (j = 1; j < n; j++)
    {
        key = v[j];
        for (i = j - 1; i >= 0 && v[i] > key; i--)
            v[i + 1] = v[i];
        v[i + 1] = key;
    }
}

int main()
{
    FILE *fp;  //Puntatore a FILE//
    int N = 0; // numeri casuali  //
    int numbers[MAX] = {0};
    int choise;
    srand(time(NULL)); //init seme random //

    printf("\tORDINAMENTO NUMERI SU FILE\t\n\n");

    //START FILE//
    fp = fopen("numeri.txt", "w");
    if (fp == NULL)
    {
        printf("\nERRORE APERTURA FILE!\n");
        exit(1);
    }
    printf("Qunati numeri casuali vuoi generare [MAX : 500]: ");
    scanf("%d", &N);

    inNumbers(numbers, N);

    for (int i = 0; i < N; i++)
        fprintf(fp, "%d\n", numbers[i]);

    printf("\nNumeri scritti correttamente su file!\n");
    fclose(fp);
    //END FILE//

    //START FILE//
    fp = fopen("numeri.txt", "r");
    if (fp == NULL)
    {
        printf("\nERRORE APERTURA FILE!\n");
        exit(1);
    }

    int debug[MAX] = {0};
    //Reading array from file//
    for (int i = 0; i < N; i++)
        fscanf(fp, "%d", &debug[i]);

    //order numbers//
    arraySort(debug, N);

    printf("\nFile  letto correttamente!\n");
    fclose(fp);

    //START FILE//
    fp = fopen("numeri_ord.txt", "w");
    if (fp == NULL)
    {
        printf("\nERRORE APERTURA FILE!\n");
        exit(1);
    }

    for (int i = 0; i < N; i++)
        fprintf(fp, "%d\n", debug[i]);

    printf("\nFile scritto correttamente!");
    fclose(fp);
    //END FILE//
    return EXIT_SUCCESS;
}