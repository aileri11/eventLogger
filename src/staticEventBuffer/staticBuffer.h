#ifndef STATIC_BUFFER_H
#define STATIC_BUFFER_H

#include "../eventLog.h"

#define ARRAY_SIZE 10

typedef struct {
    size_t size;
    size_t head;
    Event arr[ARRAY_SIZE];
} staticBuffer;

// createEvent.c
void create_event(staticBuffer* buffer, int code);

void put_event(staticBuffer* buffer, Event new_event);

// staticBuffer.c
void find_event(staticBuffer* buffer);

void peek_event(staticBuffer* buffer);

int pop_event(staticBuffer* buffer);

void save_binary(staticBuffer* buffer);

void clear_buffer(staticBuffer* buffer);

// debug func
void stdout_event_codes(staticBuffer* buffer){
    //stdout
    printf("\nbuffer:\n");
    printf("head idx: %ld\n", buffer->head);
    printf("data: ");
    for(int i = buffer->head; i < (buffer->head + buffer->size) ; i++){
        printf("%d ", buffer->arr[i % ARRAY_SIZE].code);
    }
    printf("\n\n");
}

#endif // STATIC_BUFFER_H