#include <stdio.h>
#include <iostream>
#include "matrix.h"


void getMatrix(Matrix* a) { //TODO // �����
    std::cout << "getting matrix";
}

void printMatrix(Matrix a) { //TODO // �����
    std::cout << "printing matrix";
}




void matrixAddition() { //TODO // �����
    Matrix a;
    Matrix b;
    std::cout << "1";
}
void matrixSubstruction() { //TODO // �����
    std::cout << "2";
}

void matrixMultiplication() { //TODO // �����
    std::cout << "3";
}
void matrixNumberMultiplication() { //TODO // �����
    std::cout << "4";
}
void matrixNumberAddition() {//TODO // �����
    std::cout << "5";
}
void matrixNumberSubstraction() {//TODO // �����
    std::cout << "6";
}
void matrixTrans() {//TODO // �����
    std::cout << "7";
}
void matrixReverse() {//TODO // �����
    std::cout << "8";
}
void matrixD() {//TODO // �����
    std::cout << "9";
}


void matrixMenu() { // �����
    int c = -1;
    std::cout << "1. �������� ������\n" << "2. ��������� ������\n" << "3. ��������� ������\n" << "4. ��������� ������� �� �����\n" << "5. �������� ������� � �����\n" << "6. ��������� ����� �� �������\n" << "7. ���������������� �������\n" << "8. �������� �������\n" << "9. ������������ �������\n";
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