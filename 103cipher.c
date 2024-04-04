/*
** EPITECH PROJECT, 2023
** 103cipher
** File description:
** 103cipher
*/

#include "asset/103cipher.h"

void file_descriptor()
{
    printf("USAGE:\n");
    printf("\t./103cipher message key flag\n");
    printf("DESCRIPTION\n");
    printf("\tmessage\t a  message, made of ASCII characters .\n");
    printf("\tkey \t message, made of ASCII characters\n");
    printf("\tflag \t 0 for the message to be encrypted, 1 to be decrypted\n");
}

int main(int ac, char **av)
{

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        file_descriptor();
    } else if (ac == 4 ) {
            if (strcmp(av[3], "0") == 0) {
            cipher(av);
        } else {
            printf("Error\n");
            return 84;
        }
    } else {
        printf("Initialize error. You may do ./103cipher -h for more information.\n");
        return 84;
    }
    return 0;
}

int cipher(char **av)
{
   
    cryption(av);
    
}
