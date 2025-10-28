#include <iostream>
#include <windows.h>
using namespace std;


class DynamicArray {
private:
    int* data;
    int size;

public:
    DynamicArray(int n) {
        if (n <= 0) {
            cout << "Ошибка: размер массива должен быть положительным!" << endl;
            size = 0;
            data = nullptr;
        } else {
            size = n;
            data = new int[size];
            for (int i = 0; i < size; i++) data[i] = 0;
        }
    }

    // Конструктор копирования
    DynamicArray(const DynamicArray& other) {
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    ~DynamicArray() {
        delete[] data;
    }

    void setValue(int index, int value) {
        if (index < 0 || index >= size) {
            cout << "Ошибка индекса!" << endl;
            return;
        }
        if (value < -100 || value > 100) {
            cout << "Ошибка диапазона значения!" << endl;
            return;
        }
        data[index] = value;
    }

    int getValue(int index) const {
        if (index < 0 || index >= size) {
            cout << "Ошибка индекса!" << endl;
            return 0;
        }
        return data[index];
    }

    void print() const {
        for (int i = 0; i < size; i++) cout << data[i] << " ";
        cout << endl;
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);

    cout << "=== Тест ЗАДАНИЕ 2 ===" << endl;

    DynamicArray a(3);
    a.setValue(0, 5);
    a.setValue(1, 15);
    a.setValue(2, 25);

    cout << "Исходный массив: ";
    a.print();

    DynamicArray b = a; // копирование
    cout << "Копия массива: ";
    b.print();

    a.setValue(1, 99);
    cout << "После изменения исходного массива:" << endl;
    cout << "A: "; a.print();
    cout << "B: "; b.print();

    return 0;
}
