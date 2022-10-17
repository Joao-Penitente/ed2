#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *v, int tam){
    int chave = 0, i = 0;
    
    for (int j = 1; j < tam; j++){
        chave = v[j];
        i = j - 1;
        while (i >= 0 && v[i] > chave)
        {
            v[i+1] = v[i];
            i--;
        }
        v[i+1] = chave;
    }
    
}

void main(){
    int tam;
    int *vetor;
    scanf("%d", &tam);

    vetor = malloc(tam * sizeof(int));

    for (int i = 0; i < tam; i++){
        scanf("%d", &vetor[i]);
    }
    insertionSort(vetor, tam);
    for (int i = 0; i < tam; i++)
    {
        printf("%d ",vetor[i]);
    }
    printf("\n");
    
    free(vetor);
}