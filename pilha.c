#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"

typedef struct pilha
{
    TLista *topo;
    int min;
} TPilha;

TPilha *inicializa()
{
    TPilha *pilha = (TPilha *)malloc(sizeof(TPilha));
    pilha->topo = NULL;
    pilha->min = 0;
    return pilha;
}

int push(TPilha *pilha, int elem, int cont0, int cont1)
{
    TLista *novo = (TLista *)malloc(sizeof(TLista));   
        novo->info = elem;
        novo->prox = pilha->topo;
        pilha->topo = novo;
        if(elem == 0){
            cont0 = cont0+1;
        }
        else if(elem == 1){
            cont1= cont1 +1;
        }
        return cont0, cont1;
        
}


int pop(TPilha *pilha)
{
    TLista *p;
    TLista *aux;
    int removido;
    removido = pilha->topo->info;
    p = pilha->topo;
    pilha->topo = pilha->topo->prox;
    if(pilha->min == aux->info){
        TLista* p;
        int menor = 9999    ;
        for(p = pilha->topo;p!=NULL;p=p->prox){
            if(p->info < menor){
                menor = p->info;
            }
        }
        pilha->min = menor;
    }
    int x = aux->info;
    free(aux);
    return x;

    free(p);
    return removido;
}

int peek(TPilha *pilha)
{
    int elem;
    elem = pilha->topo->info;
    return elem;
    return 0;
}

int alteraTopo(TPilha *pilha, int novoElem)
{
    pilha->topo->info = novoElem;
    return 0;
}




void main(){
    TPilha* pilha = inicializa();
    int i, c0, c1;
    scanf("digite: %i", &i);
    while(i != -1){
        push(pilha, i, c0, c1);
    }
    if (c1 > c0){
            printf("1\n");
        }
        else if (c0 > c1){
            printf("0\n");
        }
        else if (c0 == c1){
            printf("empate\n");
        }
}