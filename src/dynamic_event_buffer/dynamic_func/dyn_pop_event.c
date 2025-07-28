#include "dyn_pop_event.h"


int dyn_pop_event(dynamicBuffer* buffer){
    // check size
    if (buffer->size == 0){
        printf("empty\n");  
        return -1;
    }

    // free memory
    free(buffer->bufferPtr[buffer->head++]);

    if(buffer->head == buffer->array_size){
            buffer->head = 0;
    }

    // resize
    buffer->size--;

    return 0;
};