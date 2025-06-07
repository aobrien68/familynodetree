#include <stdlib.h>
#include <stdio.h>

typedef struct {
    char name[32];
    short id;
    short partner;
    short parents[2];
    short children[12];
} member_entry;

member_entry getEntry(int id, FILE* stream) {
    member_entry result;
    fread(&result, 1, sizeof(member_entry), stream);
    return result;
}
