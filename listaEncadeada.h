#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int info;
    struct lista* prox;    
}TLista;

TLista* criaLista(void)
{
    return NULL;
}

TLista* insereInicio (TLista* li, int i)
{
    TLista* novo = (TLista*) malloc(sizeof(TLista));
    novo->info = i;
    novo->prox = li;
    return novo;
}

void imprimeLista (TLista* li)
{
    TLista* p;
    for(p = li; p != NULL; p = p->prox)
        printf("info = %d\n", p->info);
}

TLista* insereFim (TLista* li, int i)
{
    TLista* novo = (TLista*) malloc(sizeof(TLista));
    novo->info = i;
    novo->prox = li;
    TLista* p = li;// auxiliar para percorrer a lista
    if(p == NULL) // se a lista estiver vazia
        li = novo;
    else{
        while (p->prox != NULL){
            p = p->prox;
        }
        p->prox = novo;
    }
    return li;
}

TLista* insereOrdenado (TLista*li, int i){
    TLista* novo;
    //cria novo elemento
    novo = (TLista*) malloc(sizeof(TLista));
    novo->info = i;
    TLista* p = li; //ponteiro para percorrer a lista
    if (p == NULL){ //lista vazia, insere no inicio
        novo->prox = NULL;
        li = novo;       
    }else if(p->info > i){ // insere no inicio da lista
        novo->prox = li;
        li=novo;
    }else{// procura a posição da inserção
        while(p->prox != NULL && p->prox->info < i){
            p = p->prox;
        }
        novo->prox = p->prox;
        p->prox = novo;
    }
    return li;
}

TLista* alterarLista(TLista* li, int vAntigo, int vNovo){
    TLista* p;
    int encontrado = 0;
    for(p = li; p != NULL; p = p->prox){
        if(p->info == vAntigo){
           p->info = vNovo;
           printf("Valor alterado");
           encontrado = 1;
        }
    }
    if (encontrado == 0)
        printf("Valor não encontrado");
    return li;
}

TLista* exclui(TLista* li, int i){
    TLista* p;
    TLista* c;

    if(li->prox == NULL)
        return NULL;
    if(li->info == i){
        p = li; //auxiliar para ajudar na exclusão sem quebrar a lista
        li = p->prox;
        printf("Elemento encontrado: %d\n", i);
        printf("----------------------------\n");
    }
    else{
        for(p = li; p != NULL; p = p->prox){
            if(p->info == i){
                c->prox = p->prox; //c usado para percorrer a lista sempre um elemento antes de p
                printf("Elemento encontrado: %d\n", i);
                printf("----------------------------\n");
                break;
            }c = p;
        }

    }
    free(p);
    return li;
}