#include <iostream>
#include <conio.h>

using namespace std;

//находим диагональные элементы за O(n)
void Dia(const int * const Mas, const int len) {
    cout << "Dia els: ";
    for (int i = 0;i < len;i++) {
        cout << Mas[i * len + i] << " ";
    }
    cout << endl;
}

//получаем искомое расстояние за O(n)
int dist(const int * const Mas, const int len, const int item1, const int item2) {
    int min = len;
    int pos = 0;
    bool actualItem1; //последний встреченный элемент был равен item1

    //ищем первый встреченный элемент item1/2
    int i = 0;
    for (;i < len;i++) {
        if (Mas[i] == item1) {
            pos = i;
            actualItem1 = true;
            i++;
            break;
        }
        if (Mas[i] == item2) {
            pos = i;
            actualItem1 = false;
            break;
        }
    }
    //идём дальше по массиву, для элементов, равных разным айтемам и идущим друг
    //за другом ищем расстояние между ними и сравниваем его с минимальным
    for (++i;i < len;i++) {
        if (Mas[i] == item1) {
            if (actualItem1) {
                pos = i;
            } else {
                if (min > i - pos) min = i - pos;
                pos = i;
                actualItem1 = true;
            }
        } else {
            if (Mas[i] == item2) {
                if (!actualItem1) {
                    pos = i;
                } else {
                    if (min > i - pos) min = i - pos;
                    pos = i;
                    actualItem1 = false;
                }
            }
        }
    }

    return min;
}

int main()
{
    //задаём квадратную матрицу
    const int len = 10;
    int *Mas = new int[len * len];
    //заполняем её последовательными цифрами
    for (int i = 0;i < len * len;i++) {
        Mas[i] = i;
    }

    //находим диагональные элементы за O(n)
    Dia(Mas, len);

    //массив из десяти элементов
    int A[10] = { 3, 5, 10, 8, 4, 12, 5, 3, 0, 7 };
    const int item1 = 3;
    const int item2 = 8;

    //выводим искомое расстояние за O(n)
    cout << dist(A, len, item1, item2);


    return 0;
}
