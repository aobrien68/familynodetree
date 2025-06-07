#include <stdlib.h>
#include <stdio.h>

typedef unsigned short eid_t;

typedef struct {
    char name[32];
    eid_t id;
    eid_t partner;
    eid_t parents[2];
    eid_t children[12];
} member_entry;

member_entry getEntry(eid_t id, FILE* stream) {
    member_entry result;
    fseek(stream, (long)id * sizeof(member_entry), SEEK_SET + sizeof(id_t));
    fread(&result, 1, sizeof(member_entry), stream);
    return result;
}

void setEntry(eid_t id, member_entry entry, FILE* stream) {
    fseek(stream, (long)id * sizeof(member_entry), SEEK_SET + sizeof(id_t));
    fwrite(&entry, 1, sizeof(member_entry), stream);
}

eid_t add_entry(member_entry entry, FILE* stream) {
    eid_t id;
    fseek(stream, 0l, SEEK_SET);
    fread(&id, 1, sizeof(id_t), stream);
    id++;
    fseek(stream, 0l, SEEK_SET);
    fwrite(&id, 1, sizeof(id_t), stream);
    fseek(stream, (long)id * sizeof(member_entry), SEEK_SET + sizeof(id_t));
    fwrite(&entry, 1, sizeof(member_entry), stream);
    return id;
}
