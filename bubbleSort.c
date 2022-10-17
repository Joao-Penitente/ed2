#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *v, int tam){
    int aux;
    for (int i = tam; i > 0; i--){
        for (int j = 1; j < i; j++){
            if(v[j-1] > v[j]){
                aux = v[j-1];
                v[j-1] = v[j];
                v[j] = aux;
            }
        }
        
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

    bubbleSort(vetor, tam);
    
    for (int i = 0; i < tam; i++)
    {
        printf("%d ",vetor[i]);
    }
    printf("\n");
    
    free(vetor);
}