#include <stdio.h>

#include "types.h"
#include "user.h"

int main() {

    FILE* file = fopen("users100.csv", "r");

    //Mudar dinamicamente
    int userListSize = 128;

    User** list = malloc(userListSize * sizeof(User*));
    Definition* userDefinition = createUserDefinition(); 

    if(file == NULL) {
        printf("Error reading file\n");
        return 1;
    }

    const int bufferSize = 10000;

    char buffer[bufferSize];
    int currentUser = 0;

    while(fgets(buffer, bufferSize, file)) {

        if(currentUser >= userListSize) {
            userListSize *= 2;
            list = realloc(list, sizeof(User*) * userListSize);
        }

        User* cur = malloc(sizeof(User));

        if(read(buffer, cur, userDefinition)) {
            list[currentUser++] = cur; 
        } else {
            free(cur);
        }
    }

    return 0;
}