#ifndef DYN_EVENT_BUFFER_H
#define DYN_EVENT_BUFFER_H

#include "input.h"
#include "enum.h"
#include "eventLog.h"

// dynamic
typedef struct{
    size_t size;
    size_t head;
    size_t array_size;
    Event **bufferPtr;
} dynamicBuffer;


void dyn_buffer();

// debug func
static inline void stdout_event_codes_dyn(dynamicBuffer* buffer){
    //stdout
    printf("\nbuffer:\n");
    printf("head idx: %ld\n", buffer->head);
    printf("data: ");
    for (int i = buffer->head; i < (buffer->head + buffer->size); i++){
        printf("%d ", buffer->bufferPtr[i % buffer->array_size]->code);
    }
    printf("\n\n");
}


#endif //DYN_EVENT_BUFFER_H