#ifndef NAME_HELPER_H_INCLUDED
#define NAME_HELPER_H_INCLUDED

// Struct to save names while running programm
struct saved_usernames
{
    char name_1[255];
    char name_2[255];
    char name_3[255];
};

// Function to set the name for this round
struct saved_usernames set_name(struct saved_usernames saved_usernames);
// Function to read last used usernames from file
struct saved_usernames file_read(struct saved_usernames saved_usernames);
// Function to write last used usernames to file
void file_write(struct saved_usernames this_saved_usernames);

#endif // NAME_HELPER_H_INCLUDED
