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

    DynamicArray(const DynamicArray& other) {
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; i++) data[i] = other.data[i];
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
            cout << "Ошибка диапазона!" << endl;
            return;
        }
        data[index] = value;
    }

    void print() const {
        for (int i = 0; i < size; i++) cout << data[i] << " ";
        cout << endl;
    }

    // Добавление значения в конец
    void addValue(int value) {
        if (value < -100 || value > 100) {
            cout << "Ошибка: значение вне диапазона [-100,100]" << endl;
            return;
        }

        int* newData = new int[size + 1];
        for (int i = 0; i < size; i++) newData[i] = data[i];
        newData[size] = value;

        delete[] data;
        data = newData;
        size++;
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);

    cout << "=== Тест ЗАДАНИЕ 3 ===" << endl;

    DynamicArray arr(3);
    arr.setValue(0, 10);
    arr.setValue(1, 20);
    arr.setValue(2, 30);
    cout << "Исходный массив: ";
    arr.print();

    arr.addValue(40);
    cout << "После добавления 40: ";
    arr.print();

    arr.addValue(150); // ошибка
    return 0;
}
