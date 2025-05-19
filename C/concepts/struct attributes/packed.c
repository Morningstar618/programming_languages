#include <stdio.h>
#include <stdbool.h>

#define NAME_LENGTH 64

/*
    Struct Attributes can used to provide compiler instructions.
    Here we are using the '__packed__' attribute which is pretty
    important in-case we are dealing with structs.

    This is because when we are compiling C code that contains structures
    on various architectures and systems, some systems may add padding in
    between the various struct members.

    This creates problems during Serialization/Deserializationwhen one instance 
    of the same struct compiled in other architecture/system is communicating
    data with respect to the same struct in another arch/sys.asm

    Thus using this attribute makes sure that the struct members are tightly packed
    result in proper Serialization/Deserialization.
*/

__attribute__((__packed__)) struct Employee {
    char name[NAME_LENGTH];
    int id;
    int age;
    bool isManager;
};

void main() {
    printf("%d", sizeof(struct Employee));
}