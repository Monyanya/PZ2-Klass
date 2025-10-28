#include <iostream>
#include <windows.h>
using namespace std;

// Класс для работы с динамическим массивом int
class DynamicArray {
private:
    int* data;
    int size;

public:
    // Конструктор с заданным размером
    DynamicArray(int n) {
        if (n <= 0) {
            cout << "Ошибка: размер массива должен быть положительным!" << endl;
            size = 0;
            data = nullptr;
        } else {
            size = n;
            data = new int[size];
            for (int i = 0; i < size; i++) {
                data[i] = 0;
            }
        }
    }

    // Деструктор
    ~DynamicArray() {
        delete[] data;
    }

    // Установка значения с проверкой диапазона
    void setValue(int index, int value) {
        if (index < 0 || index >= size) {
            cout << "Ошибка: индекс " << index << " вне диапазона!" << endl;
            return;
        }
        if (value < -100 || value > 100) {
            cout << "Ошибка: значение " << value << " вне диапазона [-100, 100]!" << endl;
            return;
        }
        data[index] = value;
    }

    // Получение значения
    int getValue(int index) const {
        if (index < 0 || index >= size) {
            cout << "Ошибка: индекс " << index << " вне диапазона!" << endl;
            return 0;
        }
        return data[index];
    }

    // Вывод массива
    void print() const {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);

    cout << "=== Тест ЗАДАНИЕ 1 ===" << endl;

    DynamicArray arr(5);
    arr.setValue(0, 10);
    arr.setValue(1, -20);
    arr.setValue(2, 50);
    arr.print();

    cout << "arr[1] = " << arr.getValue(1) << endl;

    arr.setValue(10, 15);
    arr.setValue(2, 150);

    return 0;
}
