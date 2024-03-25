#include "charQueueADT.h"

typedef struct listNode ListNode, *ListNodePtr;
struct listNode {
   char data;
   ListNodePtr next;
};

struct charQueue {
    ListNodePtr front; /* Punta al primo nodo della lista, che contiene l'elemento in testa alla coda, se la coda è vuota vale NULL */
    ListNodePtr rear; /* Punta all'ultimo nodo della lista, che contiene l'elemento in fondo alla coda, se la coda è vuota vale NULL */
    
    unsigned int size;
    /* aggiungere eventuali altre variabili per ottenere una implementazione più efficiente */
};

/* @brief Restituisce una coda vuota, se non trova memoria restituisce NULL */
CharQueueADT mkQueue() {
    CharQueueADT q = (CharQueueADT)malloc(sizeof(struct charQueue));
    if (q != NULL) {
        q->front = NULL;
        q->rear = NULL;
        q-> size = 0;
        return q;
    }
    return NULL;
}

/* @brief Distrugge la coda, recuperando la memoria */
void dsQueue(CharQueueADT *pq) {
    if(*pq != NULL){
        free(*pq);
        *pq = NULL;
    }
    return; 
}

/* @brief Aggiunge un elemento in fondo alla coda */
_Bool enqueue(CharQueueADT q, const char e) {
    int ret = 0;
    ListNodePtr new = (ListNodePtr)malloc(sizeof(ListNode));
    if(new != NULL){
        new->data = e;
        new->next = NULL;
        if(q->front == NULL){
            q->front = new;
        } else {
            q->rear->next = new;
        }
        q->rear = new;
        q->size++;
        ret = 1;
    }
    return ret;
}

/* @brief Toglie e restituisce l'elemento in testa alla coda */
_Bool dequeue(CharQueueADT q, char* res) {
    int ret = 0;
    if(q->front != NULL){
        ListNodePtr temp = q->front;
        *res = temp->data;
        q->front = q->front->next;
        free(temp);
        ret = 1;
        q->size--;
    }
    return ret;
}

/* @brief Controlla se la coda è vuota */
_Bool isEmpty(CharQueueADT q) {
    int ret = 0;
    if(q->front == NULL){
        ret = 1;
    }
    return ret; 
}

/* @brief Restituisce il numero degli elementi presenti nella coda */
int size(CharQueueADT q) {
    return q->size;
}

/* @brief Restituisce l'elemento nella posizione data (senza toglierlo) */
_Bool peek(CharQueueADT q, int position, char *res) {
    int ret = 0;
    ListNodePtr temp = q->front;
    for(int i = 0; i < position; i++){
        if(temp != NULL){
            temp = temp->next;
        } else {
            return 0;
        }
    }
    if(temp != NULL){
        *res = temp->data;
        ret = 1;
    }
    return ret;
}


