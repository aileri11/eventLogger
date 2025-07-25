#include "input.h"
#include "enum.h"
#include "eventLog.h"
#include "staticEventBuffer/staticBufferProc.c"
#include "dynamicEventBuffer/dynBufferProc.c"


int main(void){
    // select mode option
    printf("Enter the value to the corresponding mode\n");
    printf("1 : static\n");
    printf("2 : dynamic\n\n");

    int mode = read_mode_value();

    switch (mode)
    {
        case STATIC_MODE:
            staticBufferProc();
            break;

        case DYNAMIC_MODE:
            dynamicBufferProc();
            break;
        
        default:
            break;
    }
    
}

