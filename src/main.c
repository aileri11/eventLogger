#include "eventLog.h"
#include "enum.h"
#include "createEvent.c"
#include "./staticEventBuffer/staticBuffer.c"
#include "saveBuffer.c"


int read_value();


int main(void){
    // entry options
    printf("Enter the value to the corresponding value\n");
    printf("1 : add event\n");
    printf("2 : save event sequence to file\n");
    printf("3 : peek element by code\n");
    printf("4 : pop element\n");
    printf("5 : exit\n");
    printf("6 : delete binary\n");
    printf("7 : find element\n\n");

    // static event buffer
    Event* eventArray[ARRAY_SIZE];

    staticBuffer buffer;
    buffer.size = 0; // buff is empty
    buffer.head = 0; // first elem at 0


    int option;
    // for testing, code == event creating order
    int code = 0;

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


int read_value(){
    //const buffer
    char input[100];
    int value;

    // get inputVj;
    scanf("%s", input);

    //check test input
    // if(strcmp(input, "TEST_ABOBA_228") == 0){
    //     printf("test input detected\n");
    //     return TEST_INPUT_OPTION;
    // }


    //check input
    if(strlen(input) != 1 || input[0] - '0' > MAX_OPTION_ENTRY || input[0] - '0' < 1){
        printf("invalid input\n");
        return 0;
    }

    //chat to int
    value = input[0] - '0';

    return value;
}
