#include "eventLog.h"

#ifndef EVENT_BUFFER_H
#define EVENT_BUFFER_H

// dynamic
typedef struct{
    size_t size;
    size_t head;
    size_t array_size;
    Event **bufferPtr;
} dynamicBuffer;

//eventBufffer.c

void dyn_create_event(dynamicBuffer* buffer, int code);

void dyn_put_event(dynamicBuffer* buffer, Event* new_event);

void dyn_find_event(dynamicBuffer* buffer);

void dyn_peek_event(dynamicBuffer* buffer);

int dyn_pop_event(dynamicBuffer* buffer);

void dyn_save_binary(dynamicBuffer* buffer);

void dyn_clear_buffer(dynamicBuffer* buffer);

// debug func
void stdout_event_codes_dyn(dynamicBuffer* buffer){
    //stdout
    printf("\nbuffer:\n");
    printf("head idx: %ld\n", buffer->head);
    printf("data: ");
    for (int i = buffer->head; i < (buffer->head + buffer->size); i++){
        printf("%d ", buffer->bufferPtr[i % buffer->array_size]->code);
    }
    printf("\n\n");
}


#endif //EVENT_BUFFER_H