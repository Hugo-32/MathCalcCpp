#include <stdio.h>
#include <iostream>
#include "matrix.h"


void getMatrix(Matrix* a) { //TODO // Цопин
    std::cout << "getting matrix";
}

void printMatrix(Matrix a) { //TODO // Цопин
    std::cout << "printing matrix";
}




void matrixAddition() { //TODO // Цопин
    Matrix a;
    Matrix b;
    std::cout << "1";
}
void matrixSubstruction() { //TODO // Цопин
    std::cout << "2";
}

void matrixMultiplication() { //TODO // Цопин
    std::cout << "3";
}
void matrixNumberMultiplication() { //TODO // Цопин
    std::cout << "4";
}
void matrixNumberAddition() {//TODO // Цопин
    std::cout << "5";
}
void matrixNumberSubstraction() {//TODO // Цопин
    std::cout << "6";
}
void matrixTrans() {//TODO // Цопин
    std::cout << "7";
}
void matrixReverse() {//TODO // Цопин
    std::cout << "8";
}
void matrixD() {//TODO // Цопин
    std::cout << "9";
}


void matrixMenu() { // Цопин
    int c = -1;
    std::cout << "1. Сложение матриц\n" << "2. Вычитание матриц\n" << "3. Умножение матриц\n" << "4. Умножение матрицы на число\n" << "5. Сложение матрицы и числа\n" << "6. Вычитание числа из матрицы\n" << "7. Транспонирование матрицы\n" << "8. Обратная матрица\n" << "9. Определитель матрицы\n";
    do {
        std::cin >> c;
    } while (c < 0 || c>9);
    switch (c) {
    case 1:
        matrixAddition();
        break;
    case 2:
        matrixSubstruction();
        break;
    case 3:
        matrixMultiplication();
        break;
    case 4:
        matrixNumberMultiplication();
        break;
    case 5:
        matrixNumberAddition();
        break;
    case 6:
        matrixNumberSubstraction();
        break;
    case 7:
        matrixTrans();
        break;
    case 8:
        matrixReverse();
        break;
    case 9:
        matrixD();
        break;
    }
    if (c != 0) {
        getchar();
        matrixMenu();
    }

}