// encryption function for creating encrypted word list from words.txt
// can also be used to decrypt since the encryption is so simple
// not used in program, included for fun :D

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int encrypt()
{
    FILE * fp;
    // open .txt with list of words (one per line)
    fp = fopen("words.txt", "r");
    // create new file for encrypted list (one per line)
    FILE * new_file;
    new_file = fopen("encrypted.txt", "wb");

    // declare char array for saving a line
    char line[256];

    // iterate over lines
    while (fgets(line, sizeof(line), fp)) {
        // iterate over each letter of a line
        for (int i = 0; line[i] != '\n'; i++) {
            // change each letter by 13 without the need to loop back
            if (line[i] <= 'm') {
                // letters up to 'm' are incresed by 13 (m -> z)
                line[i] = (char)(line[i] + 13);
            } else {
                // letters from n are decreased by 13 (n -> a)
                line[i] = (char)(line[i] - 13);
            }
        }
        // write each line into new file
        fputs(line, new_file);
    }

    return 0;
}
