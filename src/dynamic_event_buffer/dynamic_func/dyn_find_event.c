#include "dyn_find_event.h"


int dyn_binary_search(int target, dynamicBuffer* buffer){
    int left = buffer->head;
    int right = buffer->head + buffer->size - 1;

    if (target < buffer->bufferPtr[left % buffer->array_size]->code || 
        target > buffer->bufferPtr[right % buffer->array_size]->code || buffer->size == 0)
        return -1;

    while (left <= right){
        int idx = (left + right) / 2;
        if (buffer->bufferPtr[idx % buffer->array_size]->code == target){
            return idx % buffer->array_size;
        }
        else if (buffer->bufferPtr[idx % buffer->array_size]->code > target){
            right = idx - 1; 
        } else left = idx + 1;
    }
    return -1;
}


int dyn_find_event(dynamicBuffer* buffer){
    if (buffer->size == 0){
        printf("Empty\n");
        return -1;
    }

    char code[80];

    printf("Enter event code to peek idx\n");
    scanf("%s", code);

    if (digits_only(code) != 0){
        printf("Invalid input\n");
        return -1;
    }
    
    int target_idx = dyn_binary_search(atoi(code), buffer);
    printf("target idx: %d\n", target_idx);

    if (target_idx < 0){
        printf("Element not found\n");
        return -1;
    }

    return 0;
};

