#include "../input.h"
#include "../eventLog.h"
#include "dynBuffer.h"

// dynamic
void dyn_save_binary(dynamicBuffer* buffer){
    // empty check
    if (buffer->array_size == 0){
        printf("Empty\n");
        return;
    }

    // open file
    FILE *file = fopen(SAVE_FILE_PATH, "ab");
    if (file == NULL){
        perror("Error\n");
        return;
    }

    int idx;

    // write bytes
    for (int i = 0; i < buffer->size; i++) {

        idx = (buffer->head+i) % buffer->array_size;

        fwrite(&buffer->bufferPtr[idx]->timestamp, sizeof(uint32_t), 1, file); 
        fwrite(&buffer->bufferPtr[idx]->code, sizeof(uint16_t), 1, file);
        fwrite(&buffer->bufferPtr[idx]->data, sizeof(uint8_t), DATA_SIZE, file); 

    }

    // clear buffer 
    dyn_clear_buffer(buffer);
    fclose(file);
}

void dyn_clear_buffer(dynamicBuffer* buffer){
    // empty check
    if (buffer->size == 0){
        printf("Empty\n");

        return;
    }

    // free event memory
    for (int i = 0; i < buffer->array_size; i++){
        // check NULL-ptr
        if (buffer->bufferPtr[i] != NULL){
            free(buffer->bufferPtr[i]);
            buffer->bufferPtr[i] = NULL;
        }
    }
    
    buffer->head = 0;
    buffer->size = 0;
};
