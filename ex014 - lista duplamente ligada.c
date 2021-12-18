#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

struct Node {
    int info;
    struct Node* previous;
    struct Node* next;
};

struct List {
    struct Node* start;
    struct Node* end;
    int size;
};

// Função para criar uma lista duplamente encadeada
struct List* create() {
    struct List* new_list = (struct List*) malloc(sizeof(struct List));

    if (new_list != NULL) {
        new_list->start = NULL;
        new_list->end = NULL;
        new_list->size = 0;
    }

    return new_list;
}

// Função para verificar se uma lista está vazia
bool empty(struct List* list) {
    assert(list != NULL);

    if (list->start == NULL) {
        return true;
    } else {
        return false;
    }
}

// Retorna a quantidade de elementos da lista
int listSize(struct List* list) {
    assert(list != NULL);
    
    return list->size;
}

// Função que esvazia a lista e limpa a memória
void freeMemory(struct List* list) {
    while(empty(list) == false) {
        remove(list, 0);
    }
    free(list);
}

// Função inserir um elemento em uma lista duplamente encadeada
void insert(struct List* list, int pos, int item) {
    assert(list != NULL);
    assert(pos >= 0 && pos <= list->size);

    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    new_node->info = item;

    if (pos == 0) {
        new_node->previous = NULL;
        new_node->next = list->start;
        list->start = new_node;
        if (list->end == NULL) {
            list->end = new_node;
        }
    } else if (pos == list->size) {
        new_node->previous = list->end;
        new_node->next = NULL;
        list->end->next = new_node;
        list->end = new_node;
    } else {
        struct Node* aux = list->start;

        for(int i = 0; i < pos - 1; i++) {
            aux = aux->next;
        }
        new_node->previous = aux;
        new_node->next = aux->next;
        aux->next = new_node;
    }
    list->size++;
}

// Função remover um elemento em uma lista duplamente encadeada
int remove(struct List* list, int pos) {
    assert(empty(list) == false);
    assert(pos >= 0 && pos < list->size);

    struct Node* aux = NULL;

    if (pos == 0) {
        aux = list->start;
        list->start = aux->next;

        if (list->start == NULL) {
            list->end = NULL;
        } else {
            list->start->previous = NULL;
        }
    } else if (pos == list->size - 1) {
        aux = list->end;
        list->end = aux->previous;
        list->end->next = NULL;
    } else {
        struct Node* prev = NULL;
        aux = list->start;

        for(int i = 0; i < pos; i++) {
            prev = aux;
            aux = aux->next;
        }

        prev->next = aux->next;
        aux->next->previous = prev;
    }

    int element = aux->info;
    list->size--;
    free(aux);

    return element;
}

// Função para obter um elemento em uma lista duplamente encadeada
int getListPos(struct List* list, int pos) {
    assert(list != NULL);
    assert(pos >= 0 && pos < list->size);

    struct Node* aux;

    if (pos == 0) {
        aux = list->start;
    } else if (pos == list->size - 1) {
        aux = list->end;
    } else {
        aux = list->start;

        for(int i = 0; i < pos; i++) {
        aux = aux->next;
        }
    }

    return aux->info;
}