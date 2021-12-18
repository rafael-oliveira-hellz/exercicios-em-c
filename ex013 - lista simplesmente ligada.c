// Trabalhando com listas

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

// Primeiro criamos uma struct para representar cada nó da nossa lista simplesmente ligada
struct Node {
    int info; // informação presente em um nó
    struct Node* next; // é um ponteiro que aponta para outro nó da estrutura
};

/* 
** Criamos um struct para representar a lista propriamente dita. Essa struct deve conter, como campos, um ponteiro para o primeiro 
** nó da lista e a quantidade de elementos presentes nessa lista 
*/
struct List {
    struct Node* start; // ponteiro para o primeiro nó da lista 
    int size; // quantidade de elementos presentes na lista
};

// Função para criar uma lista vazia
struct List* create() {
    struct List* new_list = (struct List*) malloc(sizeof(struct List));

    if (new_list != NULL) {
        new_list->start = NULL; // O campo “start”, que é um ponteiro, deve apontar para NULL, uma vez que estamos criando uma lista vazia
        new_list->size = 0; // o campo “size” deve ser inicializado com o valor igual a 0
    }
    return new_list;
};

// Função para verificar se uma lista está vazia
bool empty(struct List* list) {
    assert(list != NULL);

    if (list->start == NULL) {
        return true;
    } else {
        return false;
    }
}

// Função que insere um novo elemento na lista
void insert (struct List* list, int pos, int item) {
    assert(list != NULL);
    assert(pos >= 0 && pos <= list->size);

    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    new_node->info = item;

    if (pos == 0) {
        new_node->next = list->start;
        list->start = new_node;
    } else {
        struct Node* aux = list->start;

        for(int i = 0; i < pos - 1; i++) {
            aux = aux->next;
        }
        new_node->next = aux->next;
        aux->next = new_node;
    }
    list->size++;
}

// Função para imprimir os elementos de uma lista
void printList(struct List* list) {
    assert(list != NULL);

    printf("\nLista Gerada: \t");

    struct Node* aux = list->start;

    for(int i = 0; i < list->size; i++) {
        printf("%d\t", aux->info);
        aux = aux->next;
    }
}

// Retorna a quantidade de elementos da lista
int listSize(struct List* list) {
    assert(list != NULL);
    
    return list->size;
}

// Retorna o elemento de determinada posição da lista
int getListPos(struct List* list, int pos) {
    assert(list != NULL);
    assert(pos >= 0 && pos < list->size);

    struct Node* aux = list->start;

    for(int i = 0; i < pos; i++) {
        aux = aux->next;
    }

    return aux->info;
}

// Função para remove o elemento de determinada posição de uma lista
int remove(struct List* list, int pos) {
    assert(empty(list) == false);
    assert(pos >= 0 && pos < list->size);

    struct Node* previous = NULL;
    struct Node* aux = list->start;

    for(int i = 0; i < pos; i++) {
        previous = aux;
        aux = aux->next;
    }

    if (previous == NULL) {
        list->start = aux->next;
    } else {
        previous->next = aux->next;
    }

    int element = aux->info;
    list->size--;
    free(aux);

    return element;
}

void freeMemory(struct List* list) {
    while(empty(list) == false) {
        remove(list, 0);
    }
    free(list);
}

// Verifica se o “item” existe ou não na lista
bool hasItem(struct List* list, int item) {
    assert(list != NULL);

    struct Node* aux = list->start;

    while (aux != NULL) {
        if (aux->info == item) {
            return true;
        }
        aux = aux->next;
    }

    return false;
    
}

// retorna a posição menor elemento da lista
int lowerPos(struct List* list) {
    assert(list != NULL);

    struct Node* aux = list->start;

    int lowerPos = 0, lower = aux->info;

    for(int i = 0; i < list->size; i++) {
        if (aux->info < lower) {
            lowerPos = i;
            lower = aux->info;
        }
        aux = aux->next;
    }

    return lowerPos;
}

// Criar uma lista vazia e testar se ela realmente está vazia
int main() {
    struct List* my_list = create();

    // if (empty(my_list) == true) {
    //     printf("\nOk, lista vazia!");
    // } else {
    //     printf("\nOps... Algo deu errado!");
    // }

    insert(my_list, 0, 5);     // Lista = [5]

    insert(my_list, 0, 3);     // Lista = [3, 5]

    insert(my_list, 2, 6);     // Lista = [3, 5, 6]

    insert(my_list, 3, 7);     // Lista = [3, 5, 6, 7] 

    printList(my_list);

    return 0;
}
