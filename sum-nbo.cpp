#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]){
    FILE *fp[argc];
    uint32_t data[argc];
    uint32_t sum = 0;

    for(int i = 0; i < argc; i++){
        fp[i] = fopen(argv[i],"rb");
        uint32_t A = fread(data+i, sizeof(uint32_t), 4, fp[i]);
    }

    for(int i = 1; i < argc; i++){
        printf("%d(0x%08x)",htonl(data[i]), htonl(data[i]));
        if( i < argc -1){
          printf(" + ");
        }
        sum += htonl(data[i]);
    }

    printf(" = %d(0x%08x)", int(sum), sum);

    for(int i = 0; i < argc; i++){
        fclose(fp[i]);
    }
}
