// encryption function for creating encrypted word list from words.txt
// not used in program, included for fun :D

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int encrypt()
{
    FILE * fp;
    fp = fopen("words.txt", "r");
    FILE * new_file;
    new_file = fopen("encrypted.txt", "wb");
    char line[256];

    while (fgets(line, sizeof(line), fp)) {
        for (int i = 0; line[i] != '\n'; i++) {
            if (line[i] <= 'm') {
                line[i] = (char)(line[i] + 13);
            } else {
                line[i] = (char)(line[i] - 13);
            }
        }
        fputs(line, new_file);
    }

    return 0;
}
