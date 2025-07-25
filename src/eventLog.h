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


uint8_t byte_sum_uint32_t(uint32_t data){
    int summ = 0;

    for (int i = 0; i <= 24; i += 8){
        summ += (data >> i) & 0xFF;
    }

    return summ;
}


uint8_t byte_sum_uint16_t(uint16_t data){
    int summ = 0;

    for (int i = 0; i <= 8; i += 8){
        summ += (data >> i) & 0xFF;
    }

    return summ;
}


#endif //EVENT_LOG_H