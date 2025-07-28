#include "dyn_save_buffer.h"

// dynamic
int dyn_save_binary(dynamicBuffer* buffer){
    // empty check
    if (buffer->array_size == 0){
        printf("Empty\n");
        return -1;
    }

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

        idx = (buffer->head+i) % buffer->array_size;

        fwrite(&buffer->bufferPtr[idx]->timestamp, sizeof(uint32_t), 1, file);
        summ += byte_sum_uint32_t(buffer->bufferPtr[idx]->timestamp);
        
        fwrite(&buffer->bufferPtr[idx]->code, sizeof(uint16_t), 1, file);
        summ += byte_sum_uint16_t(buffer->bufferPtr[idx]->code);

        fwrite(&buffer->bufferPtr[idx]->data, sizeof(uint8_t), DATA_SIZE, file);
        for (int i = 0; i < DATA_SIZE; i++){
            summ += buffer->bufferPtr[idx]->data[i] & 0xFF;
        }

        //write summ
        fwrite(&summ, sizeof(uint8_t), 1, file);
        summ = 0;
    }

    // clear buffer 
    dyn_clear_buffer(buffer);
    fclose(file);

    return 0;
}

int dyn_clear_buffer(dynamicBuffer* buffer){
    // empty check
    if (buffer->size == 0){
        printf("Empty\n");

        return -1;
    }

    // free event memory
    for (int i = 0; i < buffer->array_size; i++){
        // check NULL-ptr
        if (buffer->bufferPtr[i] != NULL){
            free(buffer->bufferPtr[i]);
        }
    }
    
    buffer->head = 0;
    buffer->size = 0;

    return 0;
};
