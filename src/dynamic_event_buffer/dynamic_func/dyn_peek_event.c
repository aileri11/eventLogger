#include "dyn_peek_event.h"

int dyn_peek_event(dynamicBuffer* buffer){
    // check size
    if (buffer->size == 0){
        printf("empty\n");
        return -1;
    }

    printf("code: %d\n", buffer->bufferPtr[buffer->head]->code);
    return 0;
};
