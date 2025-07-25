#include "input.h"
#include "eventLog.h"
#include "staticBuffer.h"


int dichotomy(int target, staticBuffer* buffer){
    int left = buffer->head;
    int right = buffer->head + buffer->size - 1;

    if (target < buffer->arr[left % ARRAY_SIZE].code || target > buffer->arr[right % ARRAY_SIZE].code || buffer->size == 0) return -1;

    while (left <= right){
        int idx = (left + right) / 2;
        if (buffer->arr[idx % ARRAY_SIZE].code == target){
            return idx % ARRAY_SIZE;
        }
        else if (buffer->arr[idx % ARRAY_SIZE].code > target){
            right = idx - 1; 
        } else left = idx + 1;
    }
    return -1;
}


void find_event(staticBuffer* buffer){
    if (buffer->size == 0){
        printf("Empty\n");
        return;
    }

    char code[80];

    printf("Enter event code to peek idx\n");
    scanf("%s", code);

    if (digits_only(code) != 0){
        printf("Invalid input\n");
        return;
    }
    
    int target_idx = dichotomy(atoi(code), buffer);
    printf("target idx: %d\n", target_idx);

    if (target_idx < 0){
        printf("Element not found\n");
        return;
    }

}


void peek_event(staticBuffer* buffer){
    // check size
    if (buffer->size == 0){
        printf("empty\n");
        return;
    }

    printf("code: %d\n", buffer->arr[buffer->head].code);
    
}


int pop_event(staticBuffer* buffer){
    // check size
    if (buffer->size == 0){
        printf("empty\n");
        return -1;
    }

    buffer->size--;
    buffer->arr[buffer->head++];

    return 0;
}
