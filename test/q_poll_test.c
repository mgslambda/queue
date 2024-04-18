#include <stdio.h>
#include "../include/queue.h"

int main() {
    // setup
    Queue *q = q_init();
    q_offer(q, 1);
    q_offer(q, 2);
    q_offer(q, 3);
    q_offer(q, 4);
    q_offer(q, 5);
    q_print(q);
    puts("");

    // poll an element
    int val = q_poll(q);
    printf("Polled '%d' from queue\n", val);
    q_print(q);
    puts("");

    // poll remaining elements
    puts("Polling remaining elements");
    for (size_t i = 0; i < 4; i++) {
        q_poll(q);
        q_print(q);
        puts("");
    }
}

