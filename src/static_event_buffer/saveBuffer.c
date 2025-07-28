#include "input.h"
#include "eventLog.h"
#include "staticBuffer.h"

// static
int save_binary(staticBuffer* buffer){
    // open file
    FILE *file = fopen(SAVE_FILE_PATH, "ab");
    if (file == NULL){
        perror("Error\n");
        return -1;
    }

    int idx;
    uint8_t summ = 0;

    // write bytes, calculate byte summ
    for (int i = 0; i < buffer->size; i++) {

        idx = (buffer->head+i) % ARRAY_SIZE;

        fwrite(&buffer->arr[idx].timestamp, sizeof(uint32_t), 1, file);
        summ += byte_sum_uint32_t(buffer->arr[idx].timestamp);
        
        fwrite(&buffer->arr[idx].code, sizeof(uint16_t), 1, file);
        summ += byte_sum_uint16_t(buffer->arr[idx].code);

        fwrite(&buffer->arr[idx].data, sizeof(uint8_t), DATA_SIZE, file);
        for (int i = 0; i < DATA_SIZE; i++){
            summ += buffer->arr[idx].data[i] & 0xFF;
        }

        //write summ
        fwrite(&summ, sizeof(uint8_t), 1, file);
        summ = 0;
    }

    // clear buffer
    clear_buffer(buffer);
    fclose(file);
    
    return 0;
}


void clear_buffer(staticBuffer* buffer){
    buffer->head = 0;
    buffer->size = 0;
};