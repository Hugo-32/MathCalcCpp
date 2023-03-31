//
//  matrix.h
//  Цопин Е.О.
//

struct Matrix {
    int n;
    int m;
    double matrix[100][100];
};

void matrixMenu();


void getMatrix(Matrix* a);
void printMatrix(Matrix a);



void matrixAddition();
void matrixSubstruction();
void matrixMultiplication();
void matrixNumberMultiplication();
void matrixNumberAddition();
void matrixNumberSubstraction();
void matrixtrans();
void matrixReverse();
void matrixD();
double findD(Matrix a);