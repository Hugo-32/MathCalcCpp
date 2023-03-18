#pragma once

struct Matrix {
    int n;
    int m;
    double* matrix;
};

void matrixMenu();


void getMatrix(Matrix* a);
void printMatrix(Matrix b);



void matrixAddition();
void matrixSubstruction();
void matrixMultiplication();
void matrixNumberMultiplication();
void matrixNumberAddition();
void matrixNumberSubstraction();
void matrixtrans();
void matrixReverse();
void matrixD();