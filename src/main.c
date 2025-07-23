#include "eventLog.h"
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
    printf("6 : delete binary\n\n");

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
        
            case 1:
                create_event(&buffer, code++);
                break;

            case 2:
                save_binary(&buffer);
                break;
            
            case 3:
                peek_event(&buffer);
                //stdout
                printf("\nbuffer:\n");
                printf("head idx: %ld\n", buffer.head);
                printf("data: ");
                for(int i = buffer.head; i < (buffer.head + buffer.size) ; i++){
                    printf("%d ", buffer.arr[i % ARRAY_SIZE].code);
                }
                printf("\n");

                break;

            case 4:
                Event pop;

                if(buffer.size > 0){
                    pop = pop_event(&buffer);
                }
                else{
                    printf("empty\n");
                    break;
                }

                //stdout
                printf("code: %d\n", pop.code);
                printf("timestamp: %d\n", pop.timestamp);
                for(int i = 0; i < 10; i++){
                    printf("%d ", pop.data[i]);
                }
                printf("\n");
                
                break;

            case 5:
                printf("exited\n");

                break;

            case 6:
                printf("file reset\n");

                if (remove(SAVE_FILE_PATH)) {
                    printf("error removing file\n");
                };

                break;

            default:
                break;

        }

    } while (option != 5);
    
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
    //     return 5;
    // }


    //check input
    if(strlen(input) != 1 || input[0] - '0' > 6 || input[0] - '0' < 1){
        printf("invalid input\n");
        return 0;
    }

    //chat to int
    value = input[0] - '0';

    return value;
}
