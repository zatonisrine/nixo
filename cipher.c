#include "asset/103cipher.h"

int key_size(char *str)
{
    double i = sqrt(strlen(str));
    int j = sqrt(strlen(str));

    if (i != j)
        return j + 1;
    return j;
}

int message_size(char *str, double n)
{
    double i = strlen(str) / n;
    int j =  strlen(str) / n;

    if (i != j)
        return j + 1;
    return j;
}

int** processInput(char* str, int size)
{
    int** matrix = (int**)malloc(size * sizeof(int*));
    int j;

    int k = 0;
    for (int i = 0; i < size; i++) {
        matrix[i] = (int*)malloc(size * sizeof(int));
        for (j = 0; j < size && str[k] != '\0'; j++) {
            matrix[i][j] = str[k];
            k++;
        }
        j = 0;
    }

    return matrix;
}

int** stringToMatrix(char* str, int cols, int rows)
{
    int** matrix = (int **)malloc(sizeof(int *) * rows);
    int j;

    int k = 0;
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(sizeof(int) * (cols));
        for (j = 0; j < cols && str[k] != '\0'; j++) {
            matrix[i][j] = str[k];
            k++;
        }
        j = 0;
    }

    return matrix;
}

int** multiplymat(int** matrix1, int** matrix2, int rows1, int cols2)
{
    int temp = 0;
    
    int** result = (int**)malloc(rows1 * sizeof(int*));
    for (int i = 0; i < rows1; i++) {
        result[i] = (int*)malloc(cols2 * sizeof(int));
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            temp = 0;
            for (int k = 0; k < cols2; k++) {
                temp += matrix1[i][k] * matrix2[k][j];
            }
            result[i][j] += temp; 
        }
    }
    return result;
}

void print_key(int **key, int size)
{
    int i = 0;
    int j = 0;
    for (i; i < size; i++) {
        for (j; j < size - 1; j++) {
            printf("%d\t", key[i][j]);
        }
        if (j == size - 1)
            printf("%d", key[i][j]);
        j = 0;
        printf("\n");
    }
}

void print_message(int **message, int size, int line)
{
    int i = 0;
    int j = 0;
    for (i; i < line; i++) {
        for (j; j < size; j++) {
            if (i == line - 1 && j == size - 1)
                printf("%d", message[i][j]);
            else
                printf("%d ", message[i][j]);
        }
        j = 0;
    }
    printf("\n");
}

int cryption(char **av)
{
    char *message = av[1];
    char *key = av[2];
    int shift = atoi(av[3]);
    int keySize = key_size(key);
    int messageSize = message_size(message,keySize);
    int** keyMatrix = processInput(key, keySize);
    int** MessageMatrix = stringToMatrix(message, keySize, messageSize);
    printf("Key matrix:\n");
    print_key(keyMatrix, keySize);
    printf("\n");
    int** cryptedmessage = multiplymat(MessageMatrix, keyMatrix, messageSize, keySize);
    printf("Encrypted message:\n");
    print_message(cryptedmessage, keySize, messageSize);
}

