#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"

typedef struct fila
{
    TLista *inicio;
    TLista *fim;
} TFila;

int filaVazia(TFila *f)
{
    if (f->inicio == NULL)
        return 1;
    return 0;
}

void insere(TFila *f, int elem)
{
    TLista* novo = (TLista *)malloc(sizeof(TLista));
    novo->info = elem;
    novo->prox = NULL; // inserção no fim da fila
    if (!filaVazia(f))
        f->fim->prox = novo;
    else
        f->inicio = novo;
    f->fim = novo; // elt. novo é o novo fim da fila
}

int retira(TFila *f)
{
    if (filaVazia(f))
        exit(1);
    int info = f->inicio->info;
    TLista* aux = f->inicio;
    f->inicio = f->inicio->prox;
    /* se elemento removido era o único da fila
    faz fim apontar para null também*/
    if (f->inicio == NULL)
        f->fim = NULL;
    free(aux);
    return info;
}

int alteraInicio(TFila *f, int novoElem){
    f->inicio->info = novoElem;
    return 0;
}

void push_fila(TFila* f, int elem){
    TLista* novo = (TLista*) malloc(sizeof(TLista));
    novo->info = elem;
    novo->prox = NULL;
    if(f->inicio != NULL){
        f->fim->prox = novo;
    }else{
        f->inicio = novo;
    }
    f->fim = novo;
}
int pop_fila(TFila* f){
    TLista* aux = f->inicio;
    if(f->inicio == NULL){
        printf("Sem numeros na fila\n");
        return 0;
    }else{
        int x = f->inicio->info;
        f->inicio = f->inicio->prox;
        free(aux);
        return x;
    }
}

void ret_como_pilha_por_fila(TFila* fila){
    if(fila->inicio->prox == NULL){
        TLista* aux = fila->inicio;
        fila->inicio = fila->inicio->prox;
        free(aux);
    }else{
        TFila* auxfila = inicializa_fila();
        while(fila->inicio->prox != NULL){
            push_fila(auxfila, pop_fila(fila));
        }
        pop_fila(fila);
        while(auxfila->inicio != NULL){
            push_fila(fila, pop_fila(auxfila));
        }
        free(auxfila);
    }
}