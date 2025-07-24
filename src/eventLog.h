#ifndef EVENT_LOG_H
#define EVENT_LOG_H

#include <stdint.h>

#define SAVE_FILE_PATH "./data/log.bin"
#define DATA_SIZE 10

typedef struct {
    uint32_t timestamp;
    uint16_t code;
    uint8_t data[DATA_SIZE];
} Event;

#endif //EVENT_LOG_H