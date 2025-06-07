#include <stdlib.h>
#include <stdio.h>
#define CMD_SIZE (128)


int main(int argc, char *argv[]) {
    char* cmd_buffer = malloc(CMD_SIZE);
    fgets(cmd_buffer, CMD_SIZE, stdin);

    free(cmd_buffer);
}
