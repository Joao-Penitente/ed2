#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *v, int tam){
    
    int min = 0, aux = 0;
    for (int i = 0; i < tam - 1; i++){
        min = i;
        for (int j = i+1; j < tam; j++){
            if(v[min] > v[j]){
                min = j;
            }
        }
        aux = v[min];
        v[min] = v[i];
        v[i] = aux;
    }
}


void main() {
    int tam;
    int *vetor;
    scanf("%d", &tam);

    vetor = malloc(tam * sizeof(int));

    for (int i = 0; i < tam; i++){
        scanf("%d", &vetor[i]);
    }
    selectionSort(vetor,tam);

    for (int i = 0; i < tam; i++)
    {
        printf("%d ",vetor[i]);
    }
    printf("\n");
    
    free(vetor);

}