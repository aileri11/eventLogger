#ifndef EVENT_LOG_H
#define EVENT_LOG_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>


#define SAVE_FILE_PATH "./data/log.bin"


typedef struct {
    uint32_t timestamp;
    uint16_t code;
    uint8_t data[10];
} Event;

#endif //EVENT_LOG_H