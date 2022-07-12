#include <iostream>
#include<time.h>
#include<stdlib.h>
#include <cmath>
#include <string>
using namespace std;

// Âûâîä ìàññèâà
template <typename T> void showArr(T mas[], int size) {
    cout << "[";
    for (int i = 0; i < size; i++)
        cout << mas[i] << ", ";
    cout << "\b\b]\n";
}
// Çàäà÷à 1. Ïåðåíàïðàâëåíèå óêàçàòåëÿ íà ìàññèâ.
void redirection(int* pa, int n) {
    int *arr = new int[n];
     for (int i = 0; i < n; i++)
       arr[i] = 0;
    *pa = arr[n];
    cout << "[";
    for (int i = 0; i < n; i++)
        cout << arr[i] << ", ";
    cout << "\b\b]\n";
    delete [] arr;
}
// Çàäà÷à 2. Ñîçäàíèå òðåòüåãî ìàññèâà èç äâóõ òìåþùèõñÿ  è åãî âûâîä 
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
        cout << "Îáà ìàññèâà èäåíòè÷íû.";
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

// Çàäà÷à 3. Âîçâðàò äðîáíîé ÷àñòè.
// Ïåðâàÿ ôóíêöèÿ 
double fractionalPart(double num, double *num2, double *num3 ) {
    *num3 = modf(num, num2);
    return *num3;
}
// Âòîðÿ ôóíêöèÿ. Íî ïîäîçðåâàÿþ ÷òî ýòî íå ïðàâèëüíî
double fractionalPartOther(double num) {
    int toINT = num;
    num -= toINT;
    return num;
}

// Çàäà÷à 4. Ñîçäàíèå ñòðóêòóðû
struct circle {
    string name;
    double radius;
};
// Âûâîä íàçâàíèÿ ñòðóêòóðû ñ íàèáîëüøèì ðàäèóñîì êðóãà.
void comparisonOfCircles(circle& C1, circle& C2) {
    if (C1.radius > C2.radius)
        cout << C1.name;
    else
        cout << C2.name;

}

int main() {
    setlocale(LC_ALL, "ru");

    // Çàäà÷à 1.
    int X, Y;
    cout << "\tÇàäà÷à 1.\nÂâåäèòå ÷èñëî: ";
    cin >> Y;
    int* pa = &X;
    redirection(&X, Y);
    cout << "\n\n";

    // Çàäà÷à 2.
    cout << "\tÇàäà÷à 2.\nÏåðâûé ìàññèâ:\n";
    const int L1 = 6, L2 = 7;
    int arr1[L1] = { 1, 2, 3, 4, 5, 6 }, arr2[L2] = { 1, 2, 8, 9, 7, 3, 4 };
    showArr(arr1, L1);
    cout << "Âòîðîé ìàññèâ:\n";
    showArr(arr2, L2);
    cout << "Ìàññèâ èç óíèêàëüíûõ ýëåìåíòîâ äâóõ ìàññèâîâ:\n";
    newArr(arr1, L1, arr2, L2);

    // Çàäà÷à 3.
    cout << "\n\tÇàäà÷à 3.\nÂâåäèòå âåùåñòâåííîå ÷èñëî: ";
    double n, a, b;
    cin >> n;
    cout << "Äðîáíàÿ ÷àñòü ââåä¸ííîãî ÷èñëà (ïåðâàÿ ôóíêöèÿ): " << fractionalPart(n, &a, &b) << ".\n";
    cout << "Äðîáíàÿ ÷àñòü ââåä¸ííîãî ÷èñëà (âòîðàÿ ôóíêöèÿ): " << fractionalPartOther(n) << ".\n\n";

    // Çàäà÷à 4.
    cout << "\tÇàäà÷à 4.\nÈìåèòñÿ ÷åòûðå êðóãà:\n";

    circle c1 = { "Ñîëíå÷íûé", 19.256 };
    circle c2 = { "Ìèõàèë", 23.5478 };
    circle c3 = { "Ïîðóêà", 23.6 };
    circle c4 = { "Áëèæíèé", 14.8954 };

    cout << "1. " << c1.name << endl;
    cout << "2. " << c2.name << endl;
    cout << "3. " << c3.name << endl;
    cout << "4. " << c4.name << endl;
    cout << "Êàêèå äâà êðóãà õîòèòå ñðàâíèòü? Ââîä -> ";
    int A, B;
    bool flag = true;
    do {
        cin >> A >> B;
        if (A < 0 || A > 4 || B < 0 || B > 4) {
            cout << "Òàêèõ âàðèàíòîâ íåò! Ïîïðîáóéòå åù¸ ðàç: ";
            flag = false;
        }
        else
            if (A > B) {
                cout << "Ïîïðîáóéòå åù¸ ðàç (ââîäèòå çíà÷åíèÿ ïîïîðÿäêó): ";
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
    cout << " - Ñàìûé áîëüøîé èç âûáðàííûõ âàìè êðóãîâ.\n\n";
    return 0;
}
