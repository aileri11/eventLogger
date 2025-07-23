#include "../eventLog.h"
#include "staticBuffer.h"


int digits_only(const char *s);


void put_event(staticBuffer* buffer, Event new_event){
    if(buffer->size < ARRAY_SIZE){
        buffer->arr[(buffer->head + buffer->size++)% ARRAY_SIZE] = new_event;
    }
    else{
        buffer->arr[buffer->head++] = new_event;
        if(buffer->head == ARRAY_SIZE){
            buffer->head = 0;
        }
    }
}


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


void peek_event(staticBuffer* buffer){
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


Event pop_event(staticBuffer* buffer){
    return buffer->arr[buffer->head + buffer->size-- - 1];
}


int digits_only(const char *s) {
    if (*s == '\0') {
        return 1;
    }

    while (*s != '\0') {
        if (!isdigit(*s)) {
            return 1;
        }
        s++;
    }

    return 0;
}
