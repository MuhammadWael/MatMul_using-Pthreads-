#ifndef MATRIX_MULTIPLICATION_H_
#define MATRIX_MULTIPLICATION_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <sys/time.h>

#define MAX_NUMBERS 30

typedef struct 
{
    int row,col;
    int data[MAX_NUMBERS][MAX_NUMBERS];
}matrix_t;

typedef struct
{
    matrix_t *mat1;
    matrix_t *mat2;
    matrix_t *result;
    int row_start;
    int row_end;
} thread_data_t;

matrix_t read_matrix_from_file(char *mat);
void write_matrix_to_file(matrix_t *mat,char* name);
matrix_t perMatrix(matrix_t mat_1,matrix_t mat_2);
void perElement(matrix_t *mat1, matrix_t *mat2, matrix_t *result);
void perRow(matrix_t *mat1, matrix_t *mat2, matrix_t *result);
void *multiply_element(void *arg);
void *multiply_row(void *arg);
char *string_concat(char *str1, char *str2);

#endif

