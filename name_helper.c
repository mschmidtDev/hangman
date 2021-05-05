#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "name_helper.h"

// Get username from user
struct saved_usernames set_name(struct saved_usernames saved_usernames)
{
    char name[255];

    struct saved_usernames this_saved_usernames = file_read(saved_usernames);

    // Either use an existing name or pick a new one
    printf("Are you\n %s (n1)\n %s (n2)\n or %s (n3)\n If not, type in a new name: ", this_saved_usernames.name_1, this_saved_usernames.name_2, this_saved_usernames.name_3);
    scanf("%s", name);

    // Logic to determine if the user wants to use an existing name or a new one
    if (!strcmp(name, "n1")) {
        // Change nothing
    } else if (!strcmp(name, "n2")) {
        // Swap saved_name 1 and 2
        char save[255];
        strcpy(save, this_saved_usernames.name_1);
        strcpy(this_saved_usernames.name_1, this_saved_usernames.name_2);
        strcpy(this_saved_usernames.name_2, save);
    } else if (!strcmp(name, "n3")) {
        // Swap saved_name 1 and 3
        char save[255];
        strcpy(save, this_saved_usernames.name_1);
        strcpy(this_saved_usernames.name_1, this_saved_usernames.name_3);
        strcpy(this_saved_usernames.name_3, save);
    } else {
        // Enter new name and delete one
        strcpy(this_saved_usernames.name_3, this_saved_usernames.name_2);
        strcpy(this_saved_usernames.name_2, this_saved_usernames.name_1);
        strcpy(this_saved_usernames.name_1, name);
    }

    // Write new usernames to file
    file_write(this_saved_usernames);

    return this_saved_usernames;
}

// Get usernames for co-op
struct saved_usernames set_names_coop(struct saved_usernames saved_usernames)
{
    char name[255];

    struct saved_usernames this_saved_usernames = file_read(saved_usernames);

    // Either use an existing name or pick a new one
    printf("Player 1: Are you\n %s (n1)\n %s (n2)\n or %s (n3)\n If not, type in a new name: ", this_saved_usernames.name_1, this_saved_usernames.name_2, this_saved_usernames.name_3);
    scanf("%s", name);

    // Logic to determine if the name of player 1
    if (!strcmp(name, "n1")) {
        // Change nothing
    } else if (!strcmp(name, "n2")) {
        // Swap saved_name 1 and 2
        char save[255];
        strcpy(save, this_saved_usernames.name_1);
        strcpy(this_saved_usernames.name_1, this_saved_usernames.name_2);
        strcpy(this_saved_usernames.name_2, save);
    } else if (!strcmp(name, "n3")) {
        // Swap saved_name 1 and 3
        char save[255];
        strcpy(save, this_saved_usernames.name_1);
        strcpy(this_saved_usernames.name_1, this_saved_usernames.name_3);
        strcpy(this_saved_usernames.name_3, save);
    } else {
        // Enter new name and delete one
        strcpy(this_saved_usernames.name_3, this_saved_usernames.name_2);
        strcpy(this_saved_usernames.name_2, this_saved_usernames.name_1);
        strcpy(this_saved_usernames.name_1, name);
    }

    // Either use an existing name or pick a new one
    printf("Player 2: Are you\n %s (n1)\n %s (n2)\n or %s (n3)\n If not, type in a new name: ", this_saved_usernames.name_1, this_saved_usernames.name_2, this_saved_usernames.name_3);
    scanf("%s", name);

    // Logic to determine the name of player 2
    if (!strcmp(name, "n1")) {
        // Copy name 1
        strcpy(this_saved_usernames.name_2, this_saved_usernames.name_1);
    } else if (!strcmp(name, "n2")) {
        // Change nothing
    } else if (!strcmp(name, "n3")) {
        // Swap 2 and 3
        char save[255];
        strcpy(save, this_saved_usernames.name_2);
        strcpy(this_saved_usernames.name_2, this_saved_usernames.name_3);
        strcpy(this_saved_usernames.name_3, save);
    } else {
        // Enter new name and delete one
        strcpy(this_saved_usernames.name_3, this_saved_usernames.name_2);
        strcpy(this_saved_usernames.name_2, name);
    }

    // Write new usernames to file
    file_write(this_saved_usernames);

    return this_saved_usernames;
}

// File write
void file_write(struct saved_usernames this_saved_usernames)
{
    FILE * fp;

    fp = fopen("usernames.txt", "wb");

    // We only save 3 usernames
    for (int i = 1; i <= 3; i++) {
        if (i == 1) {
            // Append \n so windows doesn't get confused and put string in file
            strcat(this_saved_usernames.name_1, "\n");
            fputs(this_saved_usernames.name_1, fp);
        } else if (i == 2) {
            // Append \n so windows doesn't get confused
            strcat(this_saved_usernames.name_2, "\n");
            fputs(this_saved_usernames.name_2, fp);
        } else {
            // Append \n so windows doesn't get confused
            strcat(this_saved_usernames.name_3, "\n");
            fputs(this_saved_usernames.name_3, fp);
        }
    }

    // Close the file
    fclose(fp);
}

// File reading
struct saved_usernames file_read(struct saved_usernames this_saved_usernames)
{
    FILE * fp;
    // Variable for buffer
    char line[256];
    // Helper to change different struct elements
    int helper = 1;

    // check if highscores.csv exists already
    if ((fp = fopen("usernames.txt", "r"))!=NULL) {
        // if it exists, continue with the rest
        fclose(fp);
    } else {
        // otherwise create it and write first line with column names
        fp = fopen("usernames.txt", "w");
        fprintf(fp, "Merlin\nSven\nJohannes\n");
        fclose(fp);
    }


    // Open file
    fp = fopen("usernames.txt", "r");

    // Read each line of txt and save to name1, 2 and 3
    while (fgets(line, sizeof(line), fp)) {
        if (helper == 1) {
            // Safe line from file to buffer and replace \n with \0
            strcpy(this_saved_usernames.name_1, line);
            this_saved_usernames.name_1[strlen(this_saved_usernames.name_1)-1] = '\0';
        } else if (helper == 2) {
            // Safe line from file to buffer and replace \n with \0
            strcpy(this_saved_usernames.name_2, line);
            this_saved_usernames.name_2[strlen(this_saved_usernames.name_2)-1] = '\0';
        } else {
            // Safe line from file to buffer and replace \n with \0
            strcpy(this_saved_usernames.name_3, line);
            this_saved_usernames.name_3[strlen(this_saved_usernames.name_3)-1] = '\0';
        }

        helper++;
    }

    // Close document
    fclose(fp);

    return this_saved_usernames;
}
