#ifndef DYN_CREATE_EVENT_H
#define DYN_CREATE_EVENT_H

#include "dyn_buffer.h"


void dyn_create_event(dynamicBuffer* buffer, int code);

void dyn_put_event(dynamicBuffer* buffer, Event* new_event);


#endif // DYN_CREATE_EVENT_H