#ifndef _QUEUE_H
#define _QUEUE_H

#include <stddef.h>

typedef struct position {
    int val;
    struct position *prev;
    struct position *next;
} Position;

struct queue {
    Position *header;
    Position *trailer;
    size_t size;
};

#endif

