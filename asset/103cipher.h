/*
** EPITECH PROJECT, 2023
** 103cipher
** File description:
** 103cipher
*/

#ifndef CIPHER_H
    #define CIPHER_H
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    #include <string.h>

int cipher(char **av);
int** processInput(char* str, int size);
int** stringToMatrix(char* str, int cols, int rows);
int** multiplymat(int** matrix1, int** matrix2, int rows1, int cols2);
void print_key(int **key, int size);
void print_message(int **message, int size, int line);
int cryption(char **av);
int key_size(char *str);
int message_size(char *str, double n);

#endif