#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

void inserir(No **lista, int num){
    No *novo = malloc(sizeof(No));
    
    novo->valor = num;
    novo->proximo = *lista;
    *lista = novo;
}

void inserirFim(No **lista, int num){
    No *aux, *novo = malloc(sizeof(No));
    
    novo->valor = num;
    novo->proximo = NULL;

    if(*lista == NULL)
        *lista = novo;
    else{
        aux = *lista;
        while(aux->proximo)
            aux = aux->proximo;
        aux->proximo = novo;
    }
}

void inserirMeio(No **lista, int num, int ant){
    No *aux, *novo = malloc(sizeof(No));

    novo->valor = num;
    if(*lista == NULL){
        novo->proximo = NULL;
        *lista = novo;
    }else{
        aux = *lista;
        while(aux->valor != ant && aux->proximo)
            aux = aux->proximo;
        novo->proximo = aux->proximo;
        aux->proximo = novo;
    }
}

void imprima(No *node){
    while(node){
        printf("%d", node->valor);
        if(node->proximo){
            printf(" -> ");
        }
        node = node->proximo;
    }
}

int main() {
    No *lista = NULL;
    
    inserir(&lista, 1);
    inserir(&lista, 2);
    inserir(&lista, 3);
    inserir(&lista, 4);
    inserir(&lista, 5);
    inserir(&lista, 6);
    inserir(&lista, 7);
    inserir(&lista, 8);
    inserir(&lista, 9);
    inserir(&lista, 10);
    inserirFim(&lista, 11);
    inserirFim(&lista, 12);
    inserirFim(&lista, 13);
    inserirFim(&lista, 14);
    inserirFim(&lista, 15);
    inserirFim(&lista, 16);
    inserirFim(&lista, 17);
    inserirFim(&lista, 18);
    inserirFim(&lista, 19);
    inserirFim(&lista, 20);
    inserirMeio(&lista, 21, 1);
    inserirMeio(&lista, 22, 1);
    inserirMeio(&lista, 23, 1);
    inserirMeio(&lista, 24, 1);
    inserirMeio(&lista, 25, 1);
    inserirMeio(&lista, 26, 1);
    inserirMeio(&lista, 27, 1);
    inserirMeio(&lista, 28, 1);
    inserirMeio(&lista, 29, 1);
    inserirMeio(&lista, 30, 1);
    imprima(lista);
    return 0;
}