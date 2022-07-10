#include <iostream>
#include<time.h>
#include<stdlib.h>
#include <cmath>
#include <string>
using namespace std;

// ����� �������
template <typename T> void showArr(T mas[], int size) {
    cout << "[";
    for (int i = 0; i < size; i++)
        cout << mas[i] << ", ";
    cout << "\b\b]\n";
}
// ������ 1. ��������������� ��������� �� ������.
void redirection(int* pa, int n) {
    int *arr = new int[n];
     for (int i = 0; i < n; i++)
       arr[i] = 0;
    *pa = arr[n];
    cout << "[";
    for (int i = 0; i < n; i++)
        cout << arr[i] << ", ";
    cout << "\b\b]\n";
}
// ������ 2. �������� �������� ������� �� ���� ���������  � ��� ����� 
template <typename T> void newArr(T mas1[], int size1, T mas2[], int size2) {
    int count = 0;
    for (int i = 0; i < size1; i++) {
        bool flag = false;
        for (int j = 0; j < size2; j++) {
            if (mas1[i] == mas2[j]) {
                flag = true;
                break;
            }
        }
        if (!flag)
            count++;
    }
    for (int i = 0; i < size2; i++) {
        bool flag = false;
        for (int j = 0; j < size1; j++) {
            if (mas2[i] == mas1[j]) {
                flag = true;
                break;
            }
        }
        if (!flag)
            count++;
    }

    if (count == 0) {
        cout << "��� ������� ���������.";
        return;
    }

    int lenght = count;
    T* ARR = new int[lenght];
    count = 0;
    for (int i = 0; i < size1; i++) {
        bool flag = false;
        for (int j = 0; j < size2; j++) {
            if (mas1[i] == mas2[j]) {
                flag = true;
                break;
            }
        }
        if (!flag)
            ARR[count++] = mas1[i];
    }
    for (int i = 0; i < size2; i++) {
        bool flag = false;
        for (int j = 0; j < size1; j++) {
            if (mas2[i] == mas1[j]) {
                flag = true;
                break;
            }
        }
        if (!flag)
            ARR[count++] = mas2[i];
    }
    cout << "[";
    for (int i = 0; i < lenght; i++)
        cout << ARR[i] << ", ";
    cout << "\b\b]\n";
}

// ������ 3. ������� ������� �����.
// ������ ������� 
double fractionalPart(double num, double *num2, double *num3 ) {
    *num3 = modf(num, num2);
    return *num3;
}
// ����� �������. �� ����������� ��� ��� �� ���������
double fractionalPartOther(double num) {
    int toINT = num;
    num -= toINT;
    return num;
}

// ������ 4. �������� ���������
struct circle {
    string name;
    double radius;
};
// ����� �������� ��������� � ���������� �������� �����.
void comparisonOfCircles(circle& C1, circle& C2) {
    if (C1.radius > C2.radius)
        cout << C1.name;
    else
        cout << C2.name;

}

int main() {
    setlocale(LC_ALL, "ru");

    // ������ 1.
    int X, Y;
    cout << "\t������ 1.\n������� �����: ";
    cin >> Y;
    int* pa = &X;
    redirection(&X, Y);
    cout << "\n\n";

    // ������ 2.
    cout << "\t������ 2.\n������ ������:\n";
    const int L1 = 6, L2 = 7;
    int arr1[L1] = { 1, 2, 3, 4, 5, 6 }, arr2[L2] = { 1, 2, 8, 9, 7, 3, 4 };
    showArr(arr1, L1);
    cout << "������ ������:\n";
    showArr(arr2, L2);
    cout << "������ �� ���������� ��������� ���� ��������:\n";
    newArr(arr1, L1, arr2, L2);

    // ������ 3.
    cout << "\n\t������ 3.\n������� ������������ �����: ";
    double n, a, b;
    cin >> n;
    cout << "������� ����� ��������� ����� (������ �������): " << fractionalPart(n, &a, &b) << ".\n";
    cout << "������� ����� ��������� ����� (������ �������): " << fractionalPartOther(n) << ".\n\n";

    // ������ 4.
    cout << "\t������ 4.\n������� ������ �����:\n";

    circle c1 = { "���������", 19.256 };
    circle c2 = { "������", 23.5478 };
    circle c3 = { "������", 23.6 };
    circle c4 = { "�������", 14.8954 };

    cout << "1. " << c1.name << endl;
    cout << "2. " << c2.name << endl;
    cout << "3. " << c3.name << endl;
    cout << "4. " << c4.name << endl;
    cout << "����� ��� ����� ������ ��������? ���� -> ";
    int A, B;
    bool flag = true;
    do {
        cin >> A >> B;
        if (A < 0 || A > 4 || B < 0 || B > 4) {
            cout << "����� ��������� ���! ���������� ��� ���: ";
            flag = false;
        }
        else
            if (A > B) {
                cout << "���������� ��� ��� (������� �������� ���������): ";
                flag = false;
            }
            else
                if (A == 1 && B == 2) {
                    comparisonOfCircles(c1, c2);
                    flag = true;
                }
                else
                    if (A == 1 && B == 3) {
                        comparisonOfCircles(c1, c3);
                        flag = true;
                    }
                    else
                        if (A == 1 && B == 4) {
                            comparisonOfCircles(c1, c4);
                            flag = true;
                        }
                        else
                            if (A == 2 && B == 3) {
                                comparisonOfCircles(c2, c3);
                                flag = true;
                            }
                            else
                                if (A == 2 && B == 4) {
                                    comparisonOfCircles(c2, c4);
                                    flag = true;
                                }
                                else
                                    if (A == 3 && B == 4) {
                                        comparisonOfCircles(c3, c4);
                                        flag = true;
                                    }
    } while (flag == false);
    cout << " - ����� ������� �� ��������� ���� ������.\n\n";
    return 0;
}
