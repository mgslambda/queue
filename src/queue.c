#include <stdio.h>
#include <stdlib.h>
#include "../include/_queue.h"
#include "../include/queue.h"

static void _throw_error(char *msg);

Queue *q_init() {
    Queue *q = malloc(sizeof *q);
    if (q == NULL)
        _throw_error("Could not allocate memory for queue");
    q->header = malloc(sizeof *q->header);
    q->trailer = malloc(sizeof *q->trailer);
    if (q->header == NULL || q->trailer == NULL)
        _throw_error("Could not allocate memory for queue");
    q->header->next = q->trailer;
    q->trailer->prev = q->header;
    q->size = 0;
    return q;
}

size_t q_size(Queue *q) {
    return q->size;
}

size_t q_is_empty(Queue *q) {
    return q_size(q) == 0;
}

int q_peek(Queue *q) {
    if (q_is_empty(q))
        _throw_error("Empty queue");
    return q->header->next->val;
}

void q_offer(Queue *q, int val) {
    Position *p = malloc(sizeof *p);
    if (p == NULL)
        _throw_error("Could not allocate memory for queue position");
    p->val = val;
    p->next = q->trailer;
    p->prev = q->trailer->prev;
    q->trailer->prev->next = p;
    q->trailer->prev = p;
    q->size++;
}

int q_poll(Queue *q) {
    if (q_is_empty(q))
        _throw_error("Empty queue");
    Position *head = q->header->next;
    int val = head->val;
    q->header->next->next->prev = q->header;
    q->header->next = q->header->next->next;
    q->size--;
    free(head);
    return val;
}

void q_print(Queue *q) {
    if (q_is_empty(q)) {
        puts("NULL");
    } else {
        Position *current = q->header->next;
        while (current != q->trailer->prev) {
            printf("%d<-", current->val);
            current = current->next;
        }
        printf("%d\n", current->val);
    }
}

void q_del(Queue **q) {
    while ((*q)->header->next != (*q)->trailer) {
        Position *current = (*q)->header->next;
        (*q)->header->next = (*q)->header->next->next;
        free(current);
    }
    free((*q)->header);
    free((*q)->trailer);
    free(*q);
    *q = NULL;
}

static void _throw_error(char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(EXIT_FAILURE);
}

