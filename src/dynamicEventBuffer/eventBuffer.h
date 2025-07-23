#include <eventLog.h>

#ifndef EVENT_BUFFER_H
#define EVENT_BUFFER_H

// dynamic
struct eventBuffer{
    const size_t size;
    Event* bufferPtr;
};

#endif //EVENT_BUFFER_H