#include <stdio.h>
#include <stdlib.h>

int *aux;


void merge(int *v, int esquerda,int direita, int meio){
    int i = esquerda;
    int j = meio + 1;
    int k = esquerda;
    for (int i = esquerda; i <= direita; i++){
        aux[i] = v[i];
    }
    while (i  <= meio && j <= direita){
        if(aux[i] <= aux[j]){
            v[k] = aux[i];
            i++;
        }else{
            v[k] = aux[j];
            j++;
        }
        k++;
    }
    while (i <= meio)
    {
        v[k] = aux[i];
        i++;
        k++;
    }
    while (j <= direita)
    {
        v[k] = aux[j];
        j++;
        k++;
    }
    
}

void mergeSort(int *v, int esquerda, int direita){
    int meio = (esquerda + direita) / 2;

    if (esquerda >= direita){
        return;
    }
    mergeSort(v,esquerda,meio);
    mergeSort(v,meio + 1, direita);
    merge(v,esquerda,direita, meio);
}

void main(){
    int tam;
    int *vetor;


    scanf("%d", &tam);

    vetor = malloc(tam * sizeof(int));    
    aux = malloc(tam * sizeof(int));
    for (int i = 0; i < tam; i++){
        scanf("%d", &vetor[i]);
    }

    mergeSort(vetor, 0,tam - 1);
    
    for (int i = 0; i < tam; i++)
    {
        printf("%d ",vetor[i]);
    }
    printf("\n");
    
    free(vetor);
    free(aux);
}