#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int tamHeap;

int pai(int i){
    return (i-1)/2;
}
int filhoEsquerdo(int i){
    return (2*i )+1;
}

int filhoDireito(int i){
    return (2*i)+2;
}

void construirHeap(int *v, int tam){
    int i = tam/2;
    tamHeap = tam;
   while (i >= 0){
    i--;
    heapMin(v,i);
   }
   
}
int retirarMinimo(int *v){
    int min;
    if (tamHeap > 0){
        min = v[0];
        v[0] = v[tamHeap-1];
        tamHeap -= 1;
        heapMin(v,0);
        return min;
    }
    realloc(v,tamHeap * sizeof(int));
}

void decrementarChave(int *v, int i, int chave){
    int aux;
    if(chave < v[i]){
        v[i] = chave;
        while (i > 0 && v[pai(i)] > v[i]){
            aux = v[i];
            v[i] = v[pai(i)];
            v[pai(i)] = aux;
            i = pai(i);
        }
    }
}
void inserirHeapMin(int *v, int chave){
    tamHeap += 1;
    realloc(v,sizeof(int) * tamHeap);
    v[tamHeap-1] = INT_MAX;
    decrementarChave(v,tamHeap-1,chave);

}

void heapMin(int *v, int i){
    int l,r,menor,aux;
    l = filhoEsquerdo(i);
    r = filhoDireito(i);

    if(l < tamHeap && v[l] < v[i]){
        menor = l;
    }else{
        menor = i;
    }
    if (r < tamHeap && v[r] < v[menor]){
        menor = r;
    }
    
    if(menor != i){
        aux = v[i];
        v[i] = v[menor];
        v[menor] = aux;
        heapMin(v,menor);
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
    decrementarChave(vetor,4,0);
    construirHeap(vetor,tam);
    inserirHeapMin(vetor,10);

    for (int i = 0; i < tamHeap; i++)
    {
        printf("%d ",vetor[i]);
    }
    printf("\n");
    
    free(vetor);

}