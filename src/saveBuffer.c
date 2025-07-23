#include "eventLog.h"
#include "./staticEventBuffer/staticBuffer.h"

//static
void save_binary(staticBuffer* buffer){
    // open file
    FILE *file = fopen(SAVE_FILE_PATH, "ab");
    if (file == NULL){
        perror("Error\n");
        return;
    }

    int idx;

    // write bytes
    for (int i = 0; i < buffer->size; i++) {

        idx = (buffer->head+i) % ARRAY_SIZE;

        fwrite(&buffer->arr[idx].timestamp, sizeof(uint32_t), 1, file); 
        fwrite(&buffer->arr[idx].code, sizeof(uint16_t), 1, file);
        fwrite(&buffer->arr[idx].data, sizeof(uint8_t), DATA_SIZE, file); 

    }

    // clear buffer
    clear_buffer(buffer);
    fclose(file);
    
}


void clear_buffer(staticBuffer* buffer){
    buffer->head = 0;
    buffer->size = 0;
};