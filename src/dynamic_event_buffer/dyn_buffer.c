#include "dyn_buffer.h"
#include "dyn_create_event.c"
#include "dyn_save_buffer.c"
#include "dyn_find_event.c"
#include "dyn_peek_event.c"
#include "dyn_pop_event.c"


void dyn_buffer(){
    // dynamic event buffer
    int array_size = 0;
    do {
        array_size = get_array_size();
    } while (array_size < 1);
    

    dynamicBuffer buffer;
    buffer.size = 0; // buff is empty
    buffer.head = 0; // first elem at 0
    buffer.array_size = array_size;
    buffer.bufferPtr = (Event **)malloc(array_size * sizeof(Event *));

    int option;
    // for testing, code == event creating order
    int code = 0;

    // read values, break on exit value
    do {
         // stdout option info
        info();

        option = read_value();

        switch(option){
        
            case ADD_OPTION:
                dyn_create_event(&buffer, code++);
                stdout_event_codes_dyn(&buffer);
                break;

            case SAVE_OPTION:
                dyn_save_binary(&buffer);
                break;
            
            case PEEK_OPTION:
                dyn_peek_event(&buffer);
                stdout_event_codes_dyn(&buffer);
                break;

            case POP_OPTION:
                dyn_pop_event(&buffer);
                stdout_event_codes_dyn(&buffer);
                break;

            case EXIT_OPTION:
                printf("exited\n");

                // NULL pointer check
                if (&buffer != NULL){
                    dyn_clear_buffer(&buffer);
                };

                free(buffer.bufferPtr);

                break;

            case CLEAR_FILE_OPTION:
                printf("file reset\n");

                if (remove(SAVE_FILE_PATH)) {
                    printf("error removing file\n");
                };

                break;

            case FIND_OPTION:
                dyn_find_event(&buffer);
                stdout_event_codes_dyn(&buffer);
                break;

            default:
                break;

        }

    } while (option != EXIT_OPTION);

}

