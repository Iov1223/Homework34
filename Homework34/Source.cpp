#include <iostream>
#include<time.h>
#include<stdlib.h>
#include <cmath>
#include <string>
using namespace std;

// Вывод массива
template <typename T> void showArr(T mas[], int size) {
    cout << "[";
    for (int i = 0; i < size; i++)
        cout << mas[i] << ", ";
    cout << "\b\b]\n";
}
// Задача 1. Перенаправление указателя на массив.
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
// Задача 2. Создание третьего массива из двух тмеющихся  и его вывод 
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
        cout << "Оба массива идентичны.";
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

// Задача 3. Возврат дробной части.
// Первая функция 
double fractionalPart(double num, double *num2, double *num3 ) {
    *num3 = modf(num, num2);
    return *num3;
}
// Вторя функция. Но подозреваяю что это не правильно
double fractionalPartOther(double num) {
    int toINT = num;
    num -= toINT;
    return num;
}

// Задача 4. Создание структуры
struct circle {
    string name;
    double radius;
};
// Вывод названия структуры с наибольшим радиусом круга.
void comparisonOfCircles(circle& C1, circle& C2) {
    if (C1.radius > C2.radius)
        cout << C1.name;
    else
        cout << C2.name;

}

int main() {
    setlocale(LC_ALL, "ru");

    // Задача 1.
    int X, Y;
    cout << "\tЗадача 1.\nВведите число: ";
    cin >> Y;
    int* pa = &X;
    redirection(&X, Y);
    cout << "\n\n";

    // Задача 2.
    cout << "\tЗадача 2.\nПервый массив:\n";
    const int L1 = 6, L2 = 7;
    int arr1[L1] = { 1, 2, 3, 4, 5, 6 }, arr2[L2] = { 1, 2, 8, 9, 7, 3, 4 };
    showArr(arr1, L1);
    cout << "Второй массив:\n";
    showArr(arr2, L2);
    cout << "Массив из уникальных элементов двух массивов:\n";
    newArr(arr1, L1, arr2, L2);

    // Задача 3.
    cout << "\n\tЗадача 3.\nВведите вещественное число: ";
    double n, a, b;
    cin >> n;
    cout << "Дробная часть введённого числа (первая функция): " << fractionalPart(n, &a, &b) << ".\n";
    cout << "Дробная часть введённого числа (вторая функция): " << fractionalPartOther(n) << ".\n\n";

    // Задача 4.
    cout << "\tЗадача 4.\nИмеится четыре круга:\n";

    circle c1 = { "Солнечный", 19.256 };
    circle c2 = { "Михаил", 23.5478 };
    circle c3 = { "Порука", 23.6 };
    circle c4 = { "Ближний", 14.8954 };

    cout << "1. " << c1.name << endl;
    cout << "2. " << c2.name << endl;
    cout << "3. " << c3.name << endl;
    cout << "4. " << c4.name << endl;
    cout << "Какие два круга хотите сравнить? Ввод -> ";
    int A, B;
    bool flag = true;
    do {
        cin >> A >> B;
        if (A < 0 || A > 4 || B < 0 || B > 4) {
            cout << "Таких вариантов нет! Попробуйте ещё раз: ";
            flag = false;
        }
        else
            if (A > B) {
                cout << "Попробуйте ещё раз (вводите значения попорядку): ";
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
    cout << " - Самый большой из выбранных вами кругов.\n\n";
    return 0;
}
