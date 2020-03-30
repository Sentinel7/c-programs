/*
   CSC 111 - Fall 2019 - Assignment 5

   Jason Thomo - V00949336 - 10/23/2019

   The source file containing definitions of the vector functions specified in matrix_and_vector.h
*/

#include "matrix_and_vector.h"

/****************************** Vector FUNCTIONS ******************************/

void set_vector(Vector Vout, int vector_size, double value) {
    for (int i=0; i < vector_size; i++) {
        Vout[i] = value;
    }
}

void add_scalar_to_vector(Vector V, Vector Vout, int vector_size, double value) {
    for (int i=0; i < vector_size; i++) {
        Vout[i] = V[i] + value;
    }
}

void mul_vector_by_scalar(Vector V, Vector Vout, int vector_size, double value) {
    for (int i=0; i < vector_size; i++) {
        Vout[i] = V[i] * value;
    }
}

double vector_sum(Vector V, int vector_size) {
    double sum = 0;
    for (int i=0; i < vector_size; i++) {
        sum += V[i];
    }
    return sum;
}

double dot_product(Vector V1, Vector V2, int vector_size) {
    double product = 0;
    for (int i=0; i < vector_size; i++) {
        product += V1[i] * V2[i];
    }
    return product;
}

double norm(Vector V, int vector_size) {
    double product = 0;
    for (int i=0; i < vector_size; i++) {
        product += V[i] * V[i];
    }
    return sqrt(product);
}

void add_vectors(Vector V1, Vector V2, Vector Vout, int vector_size) {
    for (int i=0; i < vector_size; i++) {
        Vout[i] = V1[i] + V2[i];
    }
}

void elementwise_multiply_vectors(Vector V1, Vector V2, Vector Vout, int vector_size) {
    for (int i=0; i < vector_size; i++) {
        Vout[i] = V1[i] * V2[i];
    }
}

/****************************** MATRIX FUNCTIONS ******************************/

void identity(Matrix M, int size) {
    for (int i=0; i < size; i++) {
        for (int j=0; j < size; j++) {
            if (i == j)
                M[i][j] = 1;
            else
                M[i][j] = 0;
        }
    }
}

void matrix_copy(Matrix A, Matrix B, int rows, int cols) {
    for (int i=0; i < rows; i++) {
        for (int j=0; j < cols; j++) {
            B[i][j] = A[i][j];
        }
    }
}

void transpose(Matrix A, Matrix T, int rows, int cols) {
    for (int i=0; i < cols; i++) {
        for (int j=0; j < rows; j++) {
            T[i][j] = A[j][i];
        }
    }
}

void add_matrices(Matrix A, Matrix B, Matrix C, int rows, int cols) {
    for (int i=0; i < rows; i++) {
        for (int j=0; j < cols; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void matrix_vector_multiply(Matrix A, Vector V, Vector Vout, int n, int k) {
    for (int i=0; i < n; i++) {
        Vout[i] = 0;
        for (int j=0; j < k; j++) {
            Vout[i] += A[i][j] * V[j];
        }
    }
}

int matrix_multiply(Matrix A, Matrix B, Matrix C, int Arows, int Acols, int Brows, int Bcols) {
    if (Acols != Brows) return 0;

    for (int i=0; i < Arows; i++) {
        for (int j=0; j < Bcols; j++) {
            C[i][j] = 0;
            for (int k=0; k < Acols; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }
    return 1;
}