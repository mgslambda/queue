#ifndef QUEUE_H
#define QUEUE_H

#include <stddef.h>

typedef struct queue Queue;
extern Queue *q_init();
extern size_t q_size(Queue *q);
extern size_t q_is_empty(Queue *q);
extern int q_peek(Queue *q);
extern void q_offer(Queue *q, int val);
extern int q_poll(Queue *q, int val);
extern void q_print(Queue *q);
extern void q_del(Queue *q);

#endif

