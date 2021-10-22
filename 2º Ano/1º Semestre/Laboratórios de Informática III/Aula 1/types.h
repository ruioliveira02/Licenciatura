#ifndef _TYPES_H_
#define _TYPES_H_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct _definition {
    int numberParameters;
    char** types;
    char** names;
    int (**functions)(char*, void*);
} Definition;


#define VAR(type, name, function) type,name,function
#define STRINGIFY(x) #x

#define POST0(type, name, function) type name;
#define POST1(type, name, function) STRINGIFY(type)
#define POST2(type, name, function) STRINGIFY(name)
#define POST3(type, name, function) function

#define MAP1(type,x,y,z,...) POST##type(x,y,z)
#define MAP2(type,x,...) POST##type##_##x , MAP1(type,__VA_ARGS__)
#define MAP3(type,x,...) POST##type##_##x , MAP2(type,__VA_ARGS__)
#define MAP4(type,x,...) POST##type##_##x , MAP3(type,__VA_ARGS__)
#define MAP5(type,x,...) POST##type##_##x , MAP4(type,__VA_ARGS__)
#define MAP6(type,x,...) POST##type##_##x , MAP5(type,__VA_ARGS__)
#define MAP7(type,x,...) POST##type##_##x , MAP6(type,__VA_ARGS__)
#define MAP8(type,x,...) POST##type##_##x , MAP7(type,__VA_ARGS__)
#define MAP(type,n, ...) MAP##n(type,__VA_ARGS__)

#define REGISTERSTRUCT(name, numberOfParameters, ...)       typedef struct _##name {                                                            \
                                                                MAP(0,numberOfParameters,  __VA_ARGS__ )                                        \
                                                            } name;                                                                             \
                                                                                                                                                \
                                                            Definition* create_##name##_definition() {                                          \
                                                                char* types[] = { MAP(1,numberOfParameters,  __VA_ARGS__ ) };                   \
                                                                char* names[] = { MAP(2,numberOfParameters,  __VA_ARGS__ ) };                   \
                                                                int (*functions[])(char*, void*) = {MAP(3,numberOfParameters,  __VA_ARGS__ )};  \
                                                                                                                                                \
                                                                Definition* d = malloc(sizeof(Definition));                                     \
                                                                                                                                                \
                                                                d->numberParameters = numberOfParameters;                                       \
                                                                                                                                                \
                                                                d->types = malloc(sizeof(char*) * d->numberParameters);                         \
                                                                d->names = malloc(sizeof(char*) * d->numberParameters);                         \
                                                                d->functions = malloc(8 *  d->numberParameters);                                \
                                                                for(int i = 0; i < d->numberParameters; i++) {                                  \
                                                                                                                                                \
                                                                    d->types[i] = malloc(sizeof(char) * (strlen(types[i]) + 1));                \
                                                                    d->names[i] = malloc(sizeof(char) * (strlen(names[i]) + 1));                \
                                                                    strcpy(d->types[i], types[i]);                                              \
                                                                    strcpy(d->names[i], names[i]);                                              \
                                                                                                                                                \
                                                                    d->functions[i] = functions[i];                                             \
                                                                }                                                                               \
                                                                return d;                                                                       \
                                                            }
                                                       

void freeDefinition(Definition*);
int read(char*, void*, Definition*);
