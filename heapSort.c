#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int pai(int i){
    return (i-1)/2;
}
int filhoEsquerdo(int i){
    return (2*i )+1;
}

int filhoDireito(int i){
    return (2*i)+2;
}

void heapMax(int *v, int i,int tam){
    int l,r,maior,aux;
    l = filhoEsquerdo(i);
    r = filhoDireito(i);

    if(l < tam && v[l] > v[i]){
        maior = l;
    }else{
        maior = i;
    }
    if (r < tam && v[r] > v[maior]){
        maior = r;
    }
    if(maior != i){
        aux = v[i];
        v[i] = v[maior];
        v[maior] = aux;
        heapMax(v,maior,tam);
    }
}

int retirarMaximo(int *v,int tam){
    int max;
    if (tam > 0){
        max = v[0];
        v[0] = v[tam-1];
        tam -= 1;
        heapMax(v,0,tam);
        return max;
    }
}

void aumentarChave(int *v, int i, int chave){
    int aux;
    if(chave > v[i]){
        v[i] = chave;
        while (i > 0 && v[pai(i)] < v[i]){
            aux = v[i];
            v[i] = v[pai(i)];
            v[pai(i)] = aux;
            i = pai(i);
        }
    }
}

void inserirHeapMax(int *v, int chave,int tam){
    tam += 1;
    realloc(v,sizeof(int) * tam);
    v[tam] = INT_MIN;
    aumentarChave(v,tam,chave);

}
void construirHeap(int *v, int tam){
    for (int i = tam/2; i >= 0; i--)
    {
        heapMax(v,i,tam);
    }
}

void heapSort(int *v, int tam){
    int aux;
    construirHeap(v,tam);   
    for (int i = tam-1; i > 0; i--)
    {
        aux = v[0];
        v[0] = v[i];
        v[i] = aux;
        tam -= 1;
        heapMax(v,0,tam);
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
    inserirHeapMax(vetor, 100,tam);
    inserirHeapMax(vetor, 200,tam);
    heapSort(vetor,tam);


    for (int i = 0; i < tam; i++)
    {
        printf("%d ",vetor[i]);
    }
    printf("\n");
    
    free(vetor);

}