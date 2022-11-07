#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// representação dos nós de a
typedef struct noA
{
    char info;
    struct noA *esq;
    struct noA *dir;
} TNoA;

// Criar nó
TNoA *criaNo(char ch)
{
    TNoA *novo = (TNoA *)malloc(sizeof(TNoA));
    novo->info = ch;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}
// Imprimir a Árvore

void imprime(TNoA *nodo, int TNoA)
{
    for (int i = 0; i < TNoA; i++)
    {
        printf("-");
    }
    if (nodo != NULL)
    {
        printf("%c\n", nodo->info);
        imprime(nodo->esq, TNoA + 2);
        printf("\n");
        imprime(nodo->dir, TNoA + 2);
    }else printf("vazio");
}

//caminhamentos

void profundidade(TNoA* a){
    if (a != NULL){
        printf("%c\n", a->info);
        profundidade(a->esq);
        profundidade(a->dir);
    }
}

void simetrica(TNoA* a){
    if (a != NULL){
        simetrica(a->esq);
        printf("%c\n", a->info);
        simetrica(a->dir);
    }
}

void posOrdem(TNoA* a){
    if(a!=NULL){
        posOrdem(a->esq);
        posOrdem(a->dir);
        printf("%c\n", a->info);
    }
}

int quantidade_nos(TNoA* raiz){
    if(raiz == NULL){
        return 0;
    }else{
        return 1+quantidade_nos(raiz->esq)+quantidade_nos(raiz->dir);
    }
}
int altura(TNoA* raiz){
    if(raiz == NULL){
        return 0;
    }
    int esq = 1+altura(raiz->esq);
    int dir = 1+altura(raiz->dir);
    if(esq>dir){
        return esq;
    }else if(dir>esq){
        return dir;
    }else if(dir==esq){
        return esq;
    }
}
int binaria_cheia(int alt, int qt){
    int x = 0, i;
    for(i=0;i<alt;i++){
        x = x + pow(2,i);
    }
    if(x == qt){
        return 1;
    }else{
        return 0;
    }
}

TNoA *espelho(TNoA *a)
{

    if (a != NULL)
    {
        TNoA *raizEspelho = (TNoA *)malloc(sizeof(TNoA));
        raizEspelho->info = a->info;
        raizEspelho->esq = espelho(a->dir);
        raizEspelho->dir = espelho(a->esq);
        return raizEspelho;
    }
    return NULL;
}

void main()
{
    TNoA *raiz;
    raiz = criaNo("A");
    raiz->esq = criaNo("B");
    raiz->dir = criaNo("C");
    raiz->dir->esq = criaNo("D");
    raiz->dir->dir = criaNo("E");
    imprime(raiz, 0);
}