#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "name_helper.h"

// Get username from user
struct saved_usernames set_name(struct saved_usernames this_this_saved_usernames)
{
    char name[255];

    this_this_saved_usernames = file_read(this_this_saved_usernames);

    // Either use an existing name or pick a new one
    printf("Are you %s (n1), %s (n2) or %s (n3)? \n If not, type in a new name: ", this_this_saved_usernames.name_1, this_this_saved_usernames.name_2, this_this_saved_usernames.name_3);
    scanf("%s", name);

    // Logic to determine if the user wants to use an existing name or a new one
    if (!strcmp(name, 'n1')) {
        // Change nothing
    } else if (!strcmp(name, 'n2')) {
        // Swap saved_name 1 and 2
        char save[255] = this_saved_usernames.name_1;
        this_saved_usernames.name_1 = this_saved_usernames.name_2;
        this_saved_usernames.name_2 = save;
    } else if (!strcmp(name, 'n3')) {
        // Swap saved_name 1 and 3
        char save[255] = this_saved_usernames.name_1;
        this_saved_usernames.name_1 = this_saved_usernames.name_2;
        this_saved_usernames.name_2 = save;
    } else {
        // Enter new name and delete one
        this_saved_usernames.name_3 = this_saved_usernames.name_2;
        this_saved_usernames.name_2 = this_saved_usernames.name_1;
        this_saved_usernames.name_1 = name;
    }

    return this_saved_usernames;
}

// File reading
struct saved_usernames file_read(struct saved_usernames this_saved_usernames)
{
    FILE * fp;
    char line[256];
    int helper = 1;

    // Read each line of txt and save to name1, 2 and 3
    while (fgets(line, sizeof(line), fp)) {
        if (helper == 1) {
            this_saved_usernames.name_1 = line;
        } else if (helper == 2) {
            this_saved_usernames.name_2 = line;
        } else {
            this_saved_usernames.name_3 = line;
        }

        helper++;
    }

    // Close document
    fclose(fp);

    return this_saved_usernames;
}
