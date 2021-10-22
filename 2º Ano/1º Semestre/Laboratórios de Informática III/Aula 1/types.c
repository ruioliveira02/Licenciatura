#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "type.h"


void freeDefinition(Definition* def) {
    for(int i = 0; i < def->numberParameters; i++) {
        free(def->names[i]);
        free(def->types[i]);
    }

    free(def->names);
    free(def->types);
    free(def->functions);
    free(def);
}



int read(char* str, void* obj, Definition* definition) {

    int result = 1;
    const char separator = ',';

    int length = strlen(str);
    char* temp = malloc(sizeof(char) * (strlen(str) + 1));

    int currentParameter = 0;
    int currentIndex = 0;
    for(int i = 0; i <= length && result; i++) {

        if(str[i] == separator || str[i] == '\0') {

            temp[currentIndex] = '\0';

            result &= (*(definition->functions[currentParameter++]))(temp, obj);

            currentIndex = 0;
        } else {
            temp[currentIndex++] = str[i];
        }
    }

    free(temp);
    return result;
}