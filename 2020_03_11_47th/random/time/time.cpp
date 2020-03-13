#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void do_aes(char *key, char *data) {
    // TODO (if this was real)
}

void do_encrypt(char *text) {
    unsigned char key[16];
    srand(time(0));
    for (int i = 0; i < 16; i++) {
        key[i] = rand();    
    }

    printf("Key: ");
    for(int i=0;i < 16; i++) {
        printf("%02x",key[i]);
    }
    printf("\n\n");
}

int main(int argc, char *argv[]) {
    do_encrypt("This is a data string");
    return 0;
}


