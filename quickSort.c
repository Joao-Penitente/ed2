#include <stdio.h>
#include <stdlib.h>


int particao(int *v, int p, int r){
    int x,i,aux;
    x = v[r];
    i = p-1;

    for (int j = p; j <= r-1; j++)
    {
        
        if (v[j] <= x)
        {
            i++;
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
        }
    }
    aux = v[i+1];
    v[i+1] = v[r];
    v[r] = aux;

    return i+1;
}

void quickSort(int *v, int p, int r){
    int q;
    if(p < r){
        q = particao(v,p,r);
        quickSort(v,p, q-1);
        quickSort(v,q +1 , r); 
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
    quickSort(vetor,0,tam-1);

    for (int i = 0; i < tam; i++)
    {
        printf("%d ",vetor[i]);
    }
    printf("\n");
    
    free(vetor);

}