#include "eventLog.h"
#include "./staticEventBuffer/staticBuffer.h"


void create_event(staticBuffer* buffer, int code) {
    // init new Event struct
    Event new_event;

    // get time
    time_t timestamp;
    timestamp = time(NULL);
    new_event.timestamp = (uint32_t)timestamp;

    // event code
    new_event.code = code;

    // data
    // const for testing
    for (int i = 0; i < 10; ++i){
        new_event.data[i] = i;
    }

    // input
    // char input[9];

    // printf("Enter data\n");

    // for (int i = 0; i < 10; ++i){
    //     printf("data[%d] = ", i);
    //     scanf("%s", input);
    //     new_event.data[i] = atoi(input);
    // }

    // put Event into buffer
    put_event(buffer, new_event);
}

