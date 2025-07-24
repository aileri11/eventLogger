#include "../input.h"
#include "../enum.h"
#include "../eventLog.h"
#include "createEvent.c"
#include "staticBuffer.c"
#include "saveBuffer.c"


void staticBufferProc(){
    // static event buffer
    Event* eventArray[ARRAY_SIZE];

    staticBuffer buffer;
    buffer.size = 0; // buff is empty
    buffer.head = 0; // first elem at 0


    int option;
    // for testing, code == event creating order
    int code = 0;

    // stdout option info
    info();

    // read values, break on exit value
    do {
        option = read_value();

        switch(option){
        
            case ADD_OPTION:
                create_event(&buffer, code++);
                break;

            case SAVE_OPTION:
                save_binary(&buffer);
                break;
            
            case PEEK_OPTION:
                peek_event(&buffer);
                stdout_event_codes(&buffer);
                break;

            case POP_OPTION:
                pop_event(&buffer);
                stdout_event_codes(&buffer);
                break;

            case EXIT_OPTION:
                printf("exited\n");
                break;

            case CLEAR_FILE_OPTION:
                printf("file reset\n");

                if (remove(SAVE_FILE_PATH)) {
                    printf("error removing file\n");
                };

                break;

            case FIND_OPTION:
                find_event(&buffer);
                break;

            default:
                break;

        }

    } while (option != EXIT_OPTION);

}
