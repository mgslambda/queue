#include <stdio.h>
#include "../include/queue.h"

int main() {
    // setup
    Queue *q = q_init();

    // offer to empty queue
    q_offer(q, 42);
    printf("'%d' is at the head of the queue\n", q_peek(q));

    // offer to populated queue
    q_offer(q, 24);
    q_print(q);

    q_del(&q);
}

