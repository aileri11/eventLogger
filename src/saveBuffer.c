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

    size_t out;
    int idx;
    // write bytes
    for (int i = 0; i < buffer->size; i++) {

        idx = (buffer->head+i) % ARRAY_SIZE;
        out = fwrite(&buffer->arr[idx], sizeof(Event), 1, file); 

        if (out != 1){
            perror("fwrite error\n");
            fclose(file);
            break;
        }

    }

    // clear buffer
    clear_buffer(buffer);
    fclose(file);
}


void clear_buffer(staticBuffer* buffer){
    buffer->head = 0;
    buffer->size = 0;
};