#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//typedef uint8_t BYTE;
#define SIZE 512

int main(int argc, char *argv[])
{
    if (argc != 2){
        printf("Incorrect usage: Use two command-line arguments.\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file){
        printf("File could not be opened. Operation Terminated.\n");
        return 1;
    }

    FILE *outFile;
    unsigned char buffer[SIZE];
    //int stream = 0;
    int pics = 0;
    char out[SIZE];

    //stream = fread(buffer, SIZE, 1, file);

    while (fread(buffer, SIZE, 1, file) == 1){
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0){
            if (pics == 0){
                sprintf(out, "%03i.jpg", pics);
                pics++;

                outFile = fopen(out, "w");
                fwrite(buffer, SIZE, 1, outFile);
            }
            if (pics > 0){
                fclose(outFile);
                sprintf(out, "%03i.jpg", pics);
                pics++;

                outFile = fopen(out, "w");
                fwrite(buffer, SIZE, 1, outFile);
            }
        }

        if (pics > 0)
             fwrite(buffer, SIZE, 1, outFile);

    }

    fclose(outFile);
    fclose(file);

    return 0;

}
