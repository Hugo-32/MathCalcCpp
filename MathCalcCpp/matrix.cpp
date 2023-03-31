//
//  matrix.cpp
//  ����� ����
//  

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include "matrix.h"
#include <math.h>



void printMatrix(Matrix a) { 
    for (int i = 0;i < a.n;i++) {
        for (int j = 0;j < a.m;j++) {
            std::cout << a.matrix[i][j] << " \t";
        }
        std::cout << "\n";
    }
}

void getMatrix(Matrix* a) {
    for (int i = 0;i < a->n;i++) {
        for (int j = 0;j < a->m;j++) {
            printf("�������[%d][%d]: ", i + 1, j + 1);
            scanf("%lf", &a->matrix[i][j]);
        }
    }
    std::cout << "���������� �������: \n";
    printMatrix(*a);

}




void matrixAddition() { 
    Matrix a;
    Matrix b;
    do {
        std::cout << "\n";
        std::cout << "������� ���������� �����: ";
        std::cin >> a.n;
        std::cout << "������� ���������� ��������: ";
        std::cin >> a.m;
    } while (a.n < 1 || a.m < 1);
    b.n = a.n; b.m = a.m;
    std::cout << "������� 1: \n";
    getMatrix(&a);
    std::cout << "������� 2: \n";
    getMatrix(&b);
    for (int i = 0;i < a.n;i++) {
        for (int j = 0;j < a.m;j++) {
            a.matrix[i][j] += b.matrix[i][j];
        }
    }
    std::cout << "���������: \n";
    printMatrix(a);
}
void matrixSubstruction() { 
    Matrix a;
    Matrix b;
    do {
        std::cout << "\n";
        std::cout << "������� ���������� �����: ";
        std::cin >> a.n;
        std::cout << "������� ���������� ��������: ";
        std::cin >> a.m;
    } while (a.n < 1 || a.m < 1);
    b.n = a.n; b.m = a.m;
    std::cout << "������� 1: \n";
    getMatrix(&a);
    std::cout << "������� 2: \n";
    getMatrix(&b);
    for (int i = 0;i < a.n;i++) {
        for (int j = 0;j < a.m;j++) {
            a.matrix[i][j] -= b.matrix[i][j];
        }
    }
    std::cout << "���������: \n";
    printMatrix(a);
}

void matrixMultiplication() { 
    Matrix a;
    Matrix b;
    do {
        std::cout << "\n";
        std::cout << "������� ���������� �����: ";
        std::cin >> a.n;
        std::cout << "������� ���������� ��������: ";
        std::cin >> a.m;
    } while (a.n < 1 || a.m < 1);
    b.n = a.n; b.m = a.m;
    std::cout << "������� 1: \n";
    getMatrix(&a);
    std::cout << "������� 2: \n";
    getMatrix(&b);
    for (int i = 0;i < a.n;i++) {
        for (int j = 0;j < a.m;j++) {
            a.matrix[i][j] *= b.matrix[i][j];
        }
    }
    std::cout << "���������: \n";
    printMatrix(a);
}
void matrixNumberMultiplication() { 
    Matrix a;
    double n;
    do {
        std::cout << "\n";
        std::cout << "������� ���������� �����: ";
        std::cin >> a.n;
        std::cout << "������� ���������� ��������: ";
        std::cin >> a.m;
    } while (a.n < 1 || a.m < 1);
    std::cout << "�������: \n";
    getMatrix(&a);
    std::cout << "�����: \n";
    std::cin >> n;
    for (int i = 0;i < a.n;i++) {
        for (int j = 0;j < a.m;j++) {
            a.matrix[i][j] *= n;
        }
    }
    std::cout << "���������: \n";
    printMatrix(a);
}
void matrixNumberAddition() {
    Matrix a;
    double n;
    do {
        std::cout << "\n";
        std::cout << "������� ���������� �����: ";
        std::cin >> a.n;
        std::cout << "������� ���������� ��������: ";
        std::cin >> a.m;
    } while (a.n < 1 || a.m < 1);
    std::cout << "�������: \n";
    getMatrix(&a);
    std::cout << "�����: \n";
    std::cin >> n;
    for (int i = 0;i < a.n;i++) {
        for (int j = 0;j < a.m;j++) {
            a.matrix[i][j] += n;
        }
    }
    std::cout << "���������: \n";
    printMatrix(a);
}
void matrixNumberSubstraction() {
    Matrix a;
    double n;
    do {
        std::cout << "\n";
        std::cout << "������� ���������� �����: ";
        std::cin >> a.n;
        std::cout << "������� ���������� ��������: ";
        std::cin >> a.m;
    } while (a.n < 1 || a.m < 1);
    std::cout << "�������: \n";
    getMatrix(&a);
    std::cout << "�����: \n";
    std::cin >> n;
    for (int i = 0;i < a.n;i++) {
        for (int j = 0;j < a.m;j++) {
            a.matrix[i][j] -= n;
        }
    }
    std::cout << "���������: \n";
    printMatrix(a);
}
void matrixTrans() {
    Matrix a;
    Matrix b;
    do {
        std::cout << "\n";
        std::cout << "������� ���������� �����: ";
        std::cin >> a.n;
        std::cout << "������� ���������� ��������: ";
        std::cin >> a.m;
    } while (a.n < 1 || a.m < 1);
    b.n = a.m; b.m = a.n;
    std::cout << "�������: \n";
    getMatrix(&a);
    for (int i = 0;i < a.n;i++) {
        for (int j = 0;j < a.m;j++) {
            b.matrix[j][i] = a.matrix[i][j];
        }
    }
    std::cout << "���������: \n";
    printMatrix(b);
}
void findTrans(Matrix a, Matrix* b) {
    for (int i = 0;i < a.n;i++) {
        for (int j = 0;j < a.m;j++) {
            b->matrix[j][i] = a.matrix[i][j];
        }
    }
}
double findD(Matrix a) {
    double d = 0;
    Matrix b;
    int curr_n = 0, curr_m = 0;
    if (a.n == 2) {
        return a.matrix[0][0] * a.matrix[1][1] - a.matrix[1][0] * a.matrix[0][1];
    }
    if (a.n == 1) {
        return a.matrix[0][0];
    }
    b.n = a.n - 1; b.m = a.m - 1;
    for (int i = 0;i < a.n;i++) {
        for (int j = 1;j < a.n;j++) {
            for (int k = 0;k < a.m;k++) {
                if (k != i) {
                    b.matrix[curr_n][curr_m] = a.matrix[j][k];
                    if (curr_m + 1 == b.m) {
                        curr_m = 0;
                        curr_n += 1;
                    }
                    else {
                        curr_m += 1;
                    }
                }
            }
        }
        curr_n = 0;
        curr_m = 0;
        if (i % 2 == 0) {
            d += a.matrix[0][i] * findD(b);
        }
        else {
            d -= a.matrix[0][i] * findD(b);
        }
    }

    return d;
}



void matrixReverse() {
    Matrix a;
    Matrix aT;
    Matrix minor;
    Matrix b;
    do {
        std::cout << "\n";
        std::cout << "������� ���������� ����� � ��������: ";
        std::cin >> a.n;
    } while (a.n < 1);
    a.m = aT.n = aT.m = b.n = b.m = a.n;
    minor.n = minor.m = a.n - 1;
    int minor_i, minor_j;
    minor_i = minor_j = 0;
    std::cout << "�������: \n";
    getMatrix(&a);
    double d = findD(a);
    if (d == 0) {
        std::cout << "���������� ����� �������� �������, ��� ��� ������������ ����� 0.";
        return;
    }
    findTrans(a, &aT);
    //std::cout<<"���������: \n";
    //printMatrix(aT);
    for (int i = 0; i < a.n;i++) {
        for (int j = 0;j < a.n;j++) {
            //for each element of aT
            for (int k = 0; k < a.n;k++) {
                for (int m = 0;m < a.n;m++) {
                    if (k != i && m != j) {
                        //std::cout<<k<<" "<<m<<"\n";
                        minor.matrix[minor_i][minor_j] = aT.matrix[k][m];
                        if (minor_j + 1 == minor.m) {
                            minor_j = 0;
                            minor_i += 1;
                        }
                        else {
                            minor_j += 1;
                        }
                    }
                }
            }
            minor_i = minor_j = 0;
            if ((i + j) % 2 == 0) {
                b.matrix[i][j] = -1 * findD(minor) / fabs(d);
            }
            else {
                b.matrix[i][j] = findD(minor) / fabs(d);
            }
            if (b.matrix[i][j] == -0) b.matrix[i][j] = 0.0;
            //printMatrix(minor);
        }
    }
    std::cout << "���������: \n";
    printMatrix(b);

}
void matrixD() {
    Matrix a;
    do {
        std::cout << "\n";
        std::cout << "������� ���������� ����� � ��������: ";
        std::cin >> a.n;
    } while (a.n < 1);
    a.m = a.n;
    std::cout << "�������: \n";
    getMatrix(&a);
    printMatrix(a);
    std::cout << "���������: " << findD(a) << "\n";
}


void matrixMenu() {

    int c;
    system("cls");
    do {
        std::cout << "��������� �����������: \n";
        std::cout << "\n1. �������� ������\n" << "2. ��������� ������\n" << "3. ��������� ������\n" << "4. ��������� ������� �� �����\n" << "5. �������� ������� � �����\n" << "6. ��������� ����� �� �������\n" << "7. ���������������� �������\n" << "8. �������� �������\n" << "9. ������������ �������\n" << "0. ����� � ������� ����\n";
        std::cout << "\n";
        std::cout << "�������� ����� ����: ";
        std::cin >> c;
        switch (c)
        {
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
        case 0:
            break;
        default:
            std::cout << "\n������: �������� ����� ����. ���������� ��� ���!\n";
            break;
        } 
    } while (c != 0);
    {
        return;
    }
}
