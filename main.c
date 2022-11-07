#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"

int main (void) {
     TLista* lista;
    lista = cria_lista();

    lista = insere_inicio(lista, 2);
    lista = insere_inicio(lista, 3);
    lista = insere_inicio(lista, 3);    
    lista = insere_inicio(lista, 5);
    lista = remover(lista, 3);
    imprime_lista(lista);
    
}