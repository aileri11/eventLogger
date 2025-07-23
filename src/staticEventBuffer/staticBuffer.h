#ifndef STATIC_BUFFER_H
#define STATIC_BUFFER_H

#include "../eventLog.h"

#define ARRAY_SIZE 10

typedef struct {
    size_t size;
    size_t head;
    Event arr[ARRAY_SIZE];
} staticBuffer;


void put_event(staticBuffer* buffer, Event new_event);

void peek_event(staticBuffer* buffer);

Event pop_event(staticBuffer* buffer);

void save_binary(staticBuffer* buffer);

void clear_buffer(staticBuffer* buffer);


#endif // STATIC_BUFFER_H