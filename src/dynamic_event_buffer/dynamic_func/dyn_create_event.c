#include "dyn_create_event.h"

void dyn_create_event(dynamicBuffer* buffer, int code){
    // init new Event struct, alloc memory for new event
    Event* new_event = (Event *)malloc(sizeof(Event));

    // get time
    time_t timestamp;
    timestamp = time(NULL);
    new_event->timestamp = (uint32_t)timestamp;

    // event code
    new_event->code = code;

    // data
    // const for testing
    for (int i = 0; i < 10; ++i){
        new_event->data[i] = i;
    }

    // input
    // char input[9];

    // printf("Enter data\n");

    // for (int i = 0; i < 10; ++i){
    //     printf("data[%d] = ", i);
    //     scanf("%s", input);
    //     new_event->data[i] = atoi(input);
    // }

    // put Event into buffer
    dyn_put_event(buffer, new_event);
}

void dyn_put_event(dynamicBuffer* buffer, Event* new_event){
    if (buffer->size < buffer->array_size){
        uint8_t idx = (buffer->head + buffer->size)% buffer->array_size;
        buffer->bufferPtr[idx] = new_event;
        buffer->size++;
    }
    else{
        free(buffer->bufferPtr[buffer->head]);
        buffer->bufferPtr[buffer->head++] = new_event;
        if(buffer->head == buffer->array_size){
            buffer->head = 0;
        }
    }
}
