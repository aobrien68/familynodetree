#include <stdlib.h>
#include <stdio.h>

typedef struct {
    char name[32];
    short id;
    short partner;
    short parents[2];
    short children[12];
} member_entry;

member_entry getEntry(short id, FILE* stream) {
    member_entry result;
    fseek(stream, (long)id * sizeof(member_entry), SEEK_SET);
    fread(&result, 1, sizeof(member_entry), stream);
    return result;
}
