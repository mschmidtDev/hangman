#ifndef NAME_HELPER_H_INCLUDED
#define NAME_HELPER_H_INCLUDED

struct saved_usernames
{
    char name_1[255];
    char name_2[255];
    char name_3[255];
};

struct saved_usernames set_name(struct saved_usernames saved_usernames);
struct saved_usernames file_read(struct saved_usernames saved_usernames);

#endif // NAME_HELPER_H_INCLUDED
